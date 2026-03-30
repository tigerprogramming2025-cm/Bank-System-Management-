#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;

class clsUpdateUserScreen:protected clsScreen
{

private:
	enum enUpDatePartInfo {
		UpdateName = 1, UpdateEmail = 2, UpdatePhoneNumber = 3, UpdatePassWord = 4, UpdatePermissions = 5,
		UpdateAllInfo = 6, MainMenue = 7
	};


	static void _UpdateName(clsUser& User)
	{
		cout << "\nEnter First Name: ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "Enter Last Name: ";
		User.LastName = clsInputValidate::ReadString();
	}

	static void _UpdateEmail(clsUser& User)
	{
		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();
	}

	static void _UpdatePhone(clsUser& User)
	{
		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();
	}

	static void _UpdatePassWord(clsUser& User)
	{
		cout << "\nEnter PinCode: ";
		User.Password = clsInputValidate::ReadString();
	}

	static void _UpdatePermissions(clsUser& User)
	{
		cout << "\nEnter Account Balance: ";
		User.Permissions = ReadPermissions(); 
	}

	static void _UpdateAllInfo(clsUser& User)
	{
		_UpdateName(User);
		_UpdateEmail(User);
		_UpdatePhone(User);
		_UpdatePassWord(User);
		_UpdatePermissions(User);
	}
	static int ReadPermissions()
	{

		int Permissions = 0;


		if (clsInputValidate::IsSoureYesOrNo("\nDo you want to give User full access ?"))
		{
			Permissions = clsUser::Users_Permissions::FullPermissons;
			return Permissions;
		}
		cout << "Do you want  to give access to : \n\n";

		if (clsInputValidate::IsSoureYesOrNo("\nShow Client List "))
			Permissions = Permissions + clsUser::Users_Permissions::Ushowclientlist;

		if (clsInputValidate::IsSoureYesOrNo("\nAdd new client "))
			Permissions = Permissions + clsUser::Users_Permissions::UAddnewclient;


		if (clsInputValidate::IsSoureYesOrNo("\nDelete client "))
			Permissions = Permissions + clsUser::Users_Permissions::UDeleteclient;

		if (clsInputValidate::IsSoureYesOrNo("\nUpdata client"))
			Permissions = Permissions + clsUser::Users_Permissions::UUpdatclient;


		if (clsInputValidate::IsSoureYesOrNo("\nFind client "))
			Permissions = Permissions + clsUser::Users_Permissions::UFindclient;


		if (clsInputValidate::IsSoureYesOrNo("\nTransactions client "))
			Permissions = Permissions + clsUser::Users_Permissions::UTransactions;


		if (clsInputValidate::IsSoureYesOrNo("\nManag Users "))
			Permissions = Permissions + clsUser::Users_Permissions::UManageUsers;

		if (clsInputValidate::IsSoureYesOrNo("\Login Register "))
			Permissions = Permissions + clsUser::Users_Permissions::ULoginRegister;

		return Permissions;
	}


	static	void _PrintUser(clsUser user)
	{
		cout << "\nClient Card:";
		cout << "\n_______________________________________";
		cout << "\nFirstName         : " << user.FirstName;
		cout << "\nLastName          : " << user.LastName;
		cout << "\nFull Name         : " << user.FullName();
		cout << "\nEmail             : " << user.Email;
		cout << "\nEmail             : " << user.Phone;
		cout << "\nUser Name         : " << user.UserName;
		cout << "\nPassword          : " << user.Password;
		cout << "\nPermission        : " << user.Permissions;

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
	static bool _SaveAndReport(clsUser& User)
	{
		clsUser::enSaveResults result = User.Save();
		switch (result)
		{
		case clsUser::svSucceeded:
			cout << "\n✓ Changes saved successfully.\n";
			return true;
		case clsUser::svFaildEmptyObject:
			cout << "\n✗ Error: User object is empty.\n";
			return false;
		default:
			cout << "\n✗ Error: Failed to save changes.\n";
			return false;
		}
	}

	static	bool _performUpDateClient(enUpDatePartInfo OptionUpdate, clsUser& User)
	{
		bool ForConyinue = true;
		switch (OptionUpdate)
		{
		case UpdateName:

			_UpdateName(User);
			_SaveAndReport(User);
			_GoBackToUpdatingMenue();
			break;

		case UpdateEmail:

			_UpdateEmail(User);
			_SaveAndReport(User);
			_GoBackToUpdatingMenue();
			break;

		case UpdatePhoneNumber:

			_UpdatePhone(User);
			_SaveAndReport(User);
			_GoBackToUpdatingMenue();

			break;

		case UpdatePassWord:

			_UpdatePassWord(User);
			_SaveAndReport(User);
			_GoBackToUpdatingMenue();
			break;

		case UpdatePermissions:


			_UpdatePermissions(User);
			_SaveAndReport(User);
			_GoBackToUpdatingMenue();

			break;

		case UpdateAllInfo:
			_UpdateAllInfo(User);
			_SaveAndReport(User);
			_GoBackToUpdatingMenue();
			break;

		case MainMenue:
			ForConyinue = false;
			break;

		default:
			break;
		}

		return ForConyinue;
	}

	static void ShowUpDate(clsUser& User)
	{
		bool ContinueUpdating = true;

		while (ContinueUpdating)
		{
			system("cls");
			string suptitle = "Current User ( " + (User.UserName) + " )\n";
			_DrawScreenHeader("\tUpdating User Screen\n", suptitle);

			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\tUpdating User Menue\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] Changing Current Name.\n";
			cout << setw(37) << left << "" << "\t[2] Changing Current Email.\n";
			cout << setw(37) << left << "" << "\t[3] Changing Current Phone Number.\n";
			cout << setw(37) << left << "" << "\t[4] Changing Current PassWord.\n";
			cout << setw(37) << left << "" << "\t[5] Changing Current Permissins.\n";
			cout << setw(37) << left << "" << "\t[6] Changing Current AllInfo.\n";
			cout << setw(37) << left << "" << "\t[7] Save & Exit .\n";

			cout << setw(37) << left << "" << "===========================================\n";

			enUpDatePartInfo Option = ((enUpDatePartInfo)_ReadUpDateOption());
			ContinueUpdating = _performUpDateClient(Option, User);
		}
	}

public:
	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\t UpDate UserScreen");
		string AccountNumber = "";
		cout << "Plase enter   User Name  For Update ?\n";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(AccountNumber))
		{
			cout << "User Name can not Found,pleas enter User Name Agin ?\n ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsUser  User = clsUser::Find(AccountNumber);
		_PrintUser(User);

		if (clsInputValidate::IsSoureYesOrNo("\t\n\nDo you Want Update This User  enter ",
			"Sorry,The char is valid  enter for  Update client  "))
		{

			ShowUpDate(User);
			cout << "Update Process Completed\n";
			
		}
		else
		{
			cout << "Update is Cancled\n";
		}

	}

};
