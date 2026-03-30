#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include <iomanip>

using namespace std;
class clsListUserScreen:protected clsScreen
{
private:
	static void Printclientdatafromline(clsUser h)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << h.UserName;

		cout << "| " << setw(20) << left << h.FullName();
		cout << "| " << setw(12) << left << h.Phone;
		cout << "| " << setw(20) << left << h.Email;
		cout << "| " << setw(10) << left << h.Password;
		cout << "| " << setw(12) << left << h.Permissions;


	}

public:
	static	void ShowUserList()
	{
		int s;
		system("cls");
		stack <clsUser> vClient = clsUser::_LoadUsersDataFromFileStack();

		string Title = " \t  User list Screen ";
		string SubTitle = " \t   (" + to_string(vClient.size()) + ") User(s) ";

		clsScreen::_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________"
			"________________________\n\n";
		cout << setw(8) << left << "" << "| " << setw(15) << left << "Account Number ";
		cout << "| " << setw(20) << left << "Client Name ";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(20) << left << "Email ";
		cout << "| " << setw(10) << left << "PassWord ";
		cout << "| " << setw(12) << left << "Permission ";
		cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________"
			"________________________\n";
		if (vClient.size() == 0)
			cout << "\n\t\t\t\tThere is not Client in the system\n";
		else

			
		       s= vClient.size();
			for (int  j=0; j<s;j++)
			{
				Printclientdatafromline(vClient.top());
				cout << endl;
				vClient.pop();
			}
		cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________"
			"________________________\n";

	}

};

