#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <iomanip>
using namespace std;
class clsUpDateclientScreen:protected clsScreen
{
private:

	enum enUpDatePartInfo {
		UpdateName = 1, UpdateEmail = 2, UpdatePhoneNumber = 3, UpdatePincode = 4, UpdateAccountBalnc = 5,
		UpdateAllInfo = 6, MainMenue = 7
	};

	static void _UpdateName(clsBankClient& Client)
	{
		cout << "\nEnter First Name: ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "Enter Last Name: ";
		Client.LastName = clsInputValidate::ReadString();
	}

	static void _UpdateEmail(clsBankClient& Client)
	{
		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();
	}

	static void _UpdatePhone(clsBankClient& Client)
	{
		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();
	}

	static void _UpdatePinCode(clsBankClient& Client)
	{
		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();
	}

	static void _UpdateBalance(clsBankClient& Client)
	{
		cout << "\nEnter Account Balance: ";
		Client.Accountbalance = clsInputValidate::ReadFloatNumber();
	}

	static void _UpdateAllInfo(clsBankClient& Client)
	{
		_UpdateName(Client);
		_UpdateEmail(Client);
		_UpdatePhone(Client);
		_UpdatePinCode(Client);
			_UpdateBalance(Client);
	}
	

	static void _PrintClient(clsBankClient client)
	{
		cout << "\nClient Card:";
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

	static short _ReadUpDateOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 7, "Enter Number between 1 to 7? ");
		return Choice;
	}

	static  void _GoBackToUpdatingMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to Update other information...\n";

		system("pause>0");
		
	}

	// حفظ التغييرات وعرض النتيجة
	static bool _SaveAndReport(clsBankClient& Client)
	{
		clsBankClient::enSaveResults result = Client.Save();
		switch (result)
		{
		case clsBankClient::SvSucceeded:
			cout << "\n✓ Changes saved successfully.\n";
			return true;
		case clsBankClient::SvFailEmptyObject:
			cout << "\n✗ Error: Client object is empty.\n";
			return false;
		default:
			cout << "\n✗ Error: Failed to save changes.\n";
			return false;
		}
	}
    
	static	bool _performUpDateClient(enUpDatePartInfo OptionUpdate,clsBankClient& Client)
	{
		bool ForConyinue = true;
		switch (OptionUpdate)
		{
		case UpdateName:

			_UpdateName(Client);
			_SaveAndReport(Client);
			_GoBackToUpdatingMenue();
			break;

		case UpdateEmail:

			_UpdateEmail(Client);
			_SaveAndReport(Client);
			_GoBackToUpdatingMenue();
			break;

		case UpdatePhoneNumber:
			
			_UpdatePhone(Client);
			_SaveAndReport(Client);
			_GoBackToUpdatingMenue();

			break;

		case UpdatePincode:
		
			_UpdatePinCode(Client);
			_SaveAndReport(Client);
			_GoBackToUpdatingMenue();
			break;

		case UpdateAccountBalnc:

			
			_UpdateBalance(Client);
			_SaveAndReport(Client);
			_GoBackToUpdatingMenue();

			break;

		case UpdateAllInfo:
			_UpdateAllInfo(Client);
			_SaveAndReport(Client);
			_GoBackToUpdatingMenue();
			break;

		case clsUpDateclientScreen::MainMenue:
			ForConyinue = false;
			break;

		default:
			break;
		}

		return ForConyinue;
	}

	static void ShowUpDate(clsBankClient& Client)
	{
		bool ContinueUpdating = true;

		while (ContinueUpdating)
		{
			system("cls");
			string suptitle = "Current Client ( " + (Client.AccountNumber()) + " )\n";
			_DrawScreenHeader("\tUpdating Client Screen\n", suptitle);

			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\tUpdating Client Menue\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] Changing Current Name.\n";
			cout << setw(37) << left << "" << "\t[2] Changing Current Email.\n";
			cout << setw(37) << left << "" << "\t[3] Changing Current Phone Number.\n";
			cout << setw(37) << left << "" << "\t[4] Changing Current PinCode.\n";
			cout << setw(37) << left << "" << "\t[5] Changing Current Accountbalance.\n";
			cout << setw(37) << left << "" << "\t[6] Changing Current AllInfo.\n";
			cout << setw(37) << left << "" << "\t[7] Save & Exit .\n";

			cout << setw(37) << left << "" << "===========================================\n";

			enUpDatePartInfo Option = ((enUpDatePartInfo)_ReadUpDateOption());
			 ContinueUpdating= _performUpDateClient(Option, Client);
		}
	}

public:
	static void ShowUpdateClientScreen()
	{

		if (!CheckAccessRights(clsUser::Users_Permissions::UUpdatclient))
		{
			return;
		}
		_DrawScreenHeader("\t UpDate Client Screen");
		string AccountNumber = "";
		cout << "Plase enter Client  Account number For Update ?\n";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExit(AccountNumber))
		{
			cout << "Account number can not Found,pleas enter account Agin ?\n ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient  Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);


	
		if (clsInputValidate::IsSoureYesOrNo("\t\n\nDo you Want  Update This Client enter ",
			"Sorry,The char is valid  enter for  Update client  "))
		{

			ShowUpDate(Client);

			cout << "Update process Completed\n";
		}
		else
		{
			cout << "Update is Cancled\n";
		}

	}



};

