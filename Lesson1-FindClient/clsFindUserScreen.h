#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include <iomanip>

using namespace std;
class clsFindUserScreen:protected clsScreen
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
static void ShowFinduserScreen()
	{
		_DrawScreenHeader("\tFind User Screen");
		string  UserName;
		cout << "Pleas enter UserName ?\n";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "Sorry User con not fount enter UserName ,agin?\n";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);
	}

};

