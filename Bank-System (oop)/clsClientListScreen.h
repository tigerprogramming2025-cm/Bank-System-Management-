#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <iomanip>


using namespace std;

class clsClientListScreen :protected clsScreen
{

private:

	static void Printclientdatafromline(clsBankClient h)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << h.AccountNumber();

		cout << "| " << setw(20) << left << h.FullName();
		cout << "| " << setw(12) << left << h.Phone;
		cout << "| " << setw(20) << left << h.Email;
		cout << "| " << setw(10) << left << h.PinCode;
		cout << "| " << setw(12) << left << h.Accountbalance;
	}

public:
    static	void ShowClientList()
	{

		if (!CheckAccessRights(clsUser::Users_Permissions::Ushowclientlist))
		{
			return;
		}
		system("cls");
		vector <clsBankClient> vClient = clsBankClient::GetClientList();

		string Title = " \t  Client list Screen ";
		string SubTitle = " \t   (" + to_string(vClient.size()) + ") Client(s) ";

		clsScreen::_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________"
			"________________________\n\n";
		cout << setw(8) << left << ""  << "| " << setw(15) << left << "Account Number ";
		cout << "| " << setw(20) << left << "Client Name ";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(20) << left << "Email ";
		cout << "| " << setw(10) << left << "Pin Code ";
		cout << "| " << setw(12) << left << "Balance ";
		cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________"
			"________________________\n";
		if (vClient.size() == 0)
			cout << "\n\t\t\t\tThere is not Client in the system\n";
		else


			for (clsBankClient& j : vClient)
			{
				Printclientdatafromline(j);
				cout << endl;
			}
		cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________"
			"________________________\n";

	}

};

