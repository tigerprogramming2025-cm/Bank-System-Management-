#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include <iomanip>
using namespace std;

class clsAddNewUserScreen:protected clsScreen
{

private:
	

	static int ReadPermissions()
	{
		
		int Permissions =0;
		
	
		if (clsInputValidate::IsSoureYesOrNo("\nDo you want to give User full access ?"))
		{
			Permissions = clsUser:: Users_Permissions::FullPermissons;
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

static	void _ReadUserInfo(clsUser& User)
	{


		cout << "Enter First name  ? ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "Enter last name  ? ";
		User.LastName = clsInputValidate::ReadString();
		cout << "Enter Your Email? ";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter Your phone number? ";
		User.Phone = clsInputValidate::ReadString();

		cout << "Enter passWord ? ";
		User.Password = clsInputValidate::ReadString();

		cout << "Enter Permission ?\n\n ";
		User.Permissions = ReadPermissions();

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


public:
	static void ShowAddNewUserScreen()
	{
		string  UserName;
		_DrawScreenHeader("\tAdd New User Screen");
		cout << "\n\nPleas enter UserName ?\n";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "Sorry User con not fount enter UserName ,agin?\n";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::GetAddNewUserObject(UserName);


		clsUser::enSaveResults Resualt;

		_ReadUserInfo(User);
		Resualt = User.Save();

		switch (Resualt)
		{
		case clsUser::svFaildEmptyObject:

			cout << "Save is faild -:( \n";
			break;
		case clsUser::svSucceeded:

			cout << "Account Update  Succeeded -:) \n";
			_PrintUser(User);
			break;

		}
	}
};

