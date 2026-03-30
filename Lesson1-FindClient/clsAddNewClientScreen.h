#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <iomanip>
class clsAddNewClientScreen:protected clsScreen

{

private:
	static void _ReadClientdataInfo(clsBankClient& Client)
	{


		cout << "Enter First name  ? ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "Enter last name  ? ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "Enter Your Email? ";
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter Your phone number? ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter PinCode ? ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "Enter Balance ? ";
		Client.Accountbalance = clsInputValidate::ReadDblNumber();

	}
	static void _Print(clsBankClient client)
	{
		cout << "\nUser Card:";
		cout << "\n_______________________________________";
		cout << "\nFirstName         : " << client.FirstName;
		cout << "\nLastName          : " << client.LastName;
		cout << "\nFull Name         : " << client.FullName();
		cout << "\nEmail             : " << client.Email;
		cout << "\nPhone             : " << client.GetPhone();
		cout << "\nAccount Number    : " << client.AccountNumber();
		cout << "\nPinCode           : " << client.PinCode;
		cout << "\nAccountBalance    : " << client.Accountbalance;

		cout << "\n________________________________________\n";

	}

	public:
		static void ShowAddNewClientScreen()
		{


			if (!CheckAccessRights(clsUser::Users_Permissions::UAddnewclient))
			{
				return;
			}
			string t = "\t Add New Client Screen ";
			clsScreen::_DrawScreenHeader(t);
			string AccountNumber = "";
			cout <<  setw(12) << left <<"Plase enter Client  Account number  ?\n";
			AccountNumber = clsInputValidate::ReadString();

			while (clsBankClient::IsClientExit(AccountNumber))
			{
				cout << "Account number Found,pleas enter account Agin ?\n ";
				AccountNumber = clsInputValidate::ReadString();
			}

			clsBankClient  Client = clsBankClient::GetAddNewClientObject(AccountNumber);
			

			_ReadClientdataInfo(Client);

			clsBankClient::enSaveResults SaveResult;

			SaveResult = Client.Save();

			switch (SaveResult)
			{
			case clsBankClient::SvFailEmptyObject:

				cout << "Save is faild -:( \n";
				


				break;
			case clsBankClient::SvFailedAccountnumberExists:

				cout << "Save is Faild, Is OrReady exiet -:( \n";
				

				break;
			case clsBankClient::SvSucceeded:

				cout << "Save is Succeeded -:( \n";
				_Print(Client);

				break;
			default:
				break;
			}

		}

};

