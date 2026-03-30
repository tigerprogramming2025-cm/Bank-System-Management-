#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <iomanip>
using namespace std;
class clsDepositScreen :protected clsScreen
{
private:
	static void _PrintClient(clsBankClient client)
	{
		cout << "\nClient Card:";
		cout << "\n_______________________________________";
		cout << "\nFirstName         : " << client.FirstName;
		cout << "\nLastName          : " << client.LastName;
		cout << "\nFull Name         : " << client.FullName();
		cout << "\nEmail             : " << client.Email;
		cout << "\nAccount Number    : " << client.AccountNumber();
		cout << "\nPinCode           : " << client.PinCode;
		cout << "\nAccountBalance    : " << client.Accountbalance;

		cout << "\n________________________________________\n";

	}
public:
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\tDeposit  Screen");
		string AccountNumber = "";
		cout << "Plase enter Client  Account number For Deposit ?\n";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExit(AccountNumber))
		{
			cout << "Account number can not Found,pleas enter account Agin ?\n ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient  Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		double Amount = 0;
		cout << "Please enter deposit amount ?\n";
		Amount =clsInputValidate::ReadDblNumber();

		if (clsInputValidate::IsSoureYesOrNo("Are you sure you want to perform this transaction "))
		{
			Client.Deposit(Amount);

			cout << "Amount deposited Successfully :) \n\n";


			cout << "New Balance is : "<<Client.GetAccountbalance();

		}
		else
		{
			cout << "Amount deposited Canceled :( \n\n";
		}
	}

};

