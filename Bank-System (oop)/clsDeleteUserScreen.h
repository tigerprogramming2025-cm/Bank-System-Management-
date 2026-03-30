#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include <iomanip>
using namespace std;
class clsDeleteUserScreen:protected clsScreen
{
private:

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
	static  void ShowDeleteClientScreen()
	{

		_DrawScreenHeader("\tDelete Client Screen");
		string AccountNumber = "";
		cout << "Plase enter Client  Account number  ?\n";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(AccountNumber))
		{
			cout << "Account number is not Found,pleas enter account Agin ?\n ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsUser  User = clsUser::Find(AccountNumber);

		_PrintUser(User);


		if (clsInputValidate::IsSoureYesOrNo("Do you Want Delete This Client enter ",
			"Sorry,The char is valid  enter for delete client "))
		{
			if (User.Delete())
			{
				cout << "Deleted Successdfully\n";
				_PrintUser(User);
			}
			else
			{
				cout << "Deleted Faild\n";

			}

		}
		else
		{
			cout << "Deleted canceled\n";
			return;
		}

	}
};

