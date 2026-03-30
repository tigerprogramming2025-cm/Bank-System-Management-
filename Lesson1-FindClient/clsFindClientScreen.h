#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <iomanip>
using namespace std;

class clsFindClientScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient client)
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
	static void ShowFindClientScreen()
	{

		if (!CheckAccessRights(clsUser::Users_Permissions::UFindclient))
		{
			return;
		}
		_DrawScreenHeader("\t Find Client Screen");
		string AccountNumber = "";
		cout << "Plase enter Client  Account number For Find ?\n";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExit(AccountNumber))
		{
			cout << "Account number can not Found,pleas enter account Agin ?\n ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient  Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
	}

};

