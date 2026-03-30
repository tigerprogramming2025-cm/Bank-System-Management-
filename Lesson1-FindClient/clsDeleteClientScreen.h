#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <iomanip>
using namespace std;

class clsDeleteClientScreen:protected clsScreen
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


	 static  void ShowDeleteClientScreen()
	   {


		 if (!CheckAccessRights(clsUser::Users_Permissions::UDeleteclient))
		 {
			 return;
		 }
		   _DrawScreenHeader("\tDelete Client Screen");
		   string AccountNumber = "";

		   cout << "Plase enter Client  Account number  ?\n";
		   AccountNumber = clsInputValidate::ReadString();

		   while (!clsBankClient::IsClientExit(AccountNumber))
		   {
			   cout << "Account number is not Found,pleas enter account Agin ?\n ";
			   AccountNumber = clsInputValidate::ReadString();
		   }

		   clsBankClient  Client = clsBankClient::Find(AccountNumber);
		   
				  _PrintClient(Client);

		   
		  if (clsInputValidate::IsSoureYesOrNo("Do you Want Delete This Client enter ",
			  "Sorry,The char is valid  enter for delete client "))
		  {
			   if (Client.Delete())
			   {
				   cout << "Deleted Successdfully\n";
				   _PrintClient(Client);
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

