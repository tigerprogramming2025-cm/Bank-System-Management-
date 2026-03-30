#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <iomanip>
using namespace std;

class clsShowTransferScreen:protected clsScreen
{
   private:
	   static void _PrintClientTransfer(clsBankClient client)
	   {
		   cout << "\nClient Card:";
		   cout << "\n_______________________________________";
		   cout << "\nFull Name    : " << client.FullName();
		   cout << "\nAcc. Number  : " << client.AccountNumber();
		   cout << "\nBalance      : " << client.Accountbalance;
		   cout << "\n________________________________________\n";

	   }

	   static string _ReadAccountNumber(string Typetransfer="From")
	   {
		   string AccountNumber = "";
		   cout << "\nPlase enter   Account number to Transfer to "<< Typetransfer<<" : ";
		   AccountNumber = clsInputValidate::ReadString();

		   while (!clsBankClient::IsClientExit(AccountNumber))
		   {
			   cout << "Account number can not Found,pleas enter account Agin ?\n ";
			   AccountNumber = clsInputValidate::ReadString();
		   }
		   cout << endl;
		   return AccountNumber;
	   }

	   static double _ReadAmount(clsBankClient SourceClient)
	   {
		   double Amount = 0;
		   cout << "\n\nEnter Tranfer amount ?";
		   Amount = clsInputValidate::ReadDblNumber();

		   while (!clsInputValidate::IsNumber1BigThanNumber2Db(SourceClient.Accountbalance, Amount))
		   {
			   cout << "\n\nAmount Exceesds availble Balance,Enter another Amount ? ";
			   Amount = clsInputValidate::ReadDblNumber();
		   }

		   return Amount;
	   }
  public:
	  static void ShowDepositScreen()
	  {
		  _DrawScreenHeader("\Transfer  Screen");
		  clsBankClient  SourceClient = clsBankClient::Find(_ReadAccountNumber());
		  _PrintClientTransfer(SourceClient);

		   clsBankClient  DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));
		  _PrintClientTransfer(DestinationClient);


		  double amount = _ReadAmount(SourceClient);


		  if (clsInputValidate::IsSoureYesOrNo("Are you sure you want to perform this operation "))
		  {       
			  if (SourceClient.Tansfer(amount, DestinationClient))
			  {
				  cout << "\n\nTrasfer done Successfully :-) \n\n";
				  
			  }
			  else
			  {
				  cout << "\n\nTrasfer done Faild :-( \n\n";

			  }

			  _PrintClientTransfer(SourceClient);
			  _PrintClientTransfer(DestinationClient);
		  }
		  else
		  {
			  cout << "Amount deposited Canceled :( \n\n";
		  }
	  }


};

