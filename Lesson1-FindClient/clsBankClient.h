#pragma once
#include <iostream>
#include "clsPerson.h"
#include <vector>
#include<iomanip>
#include "clsString.h"
#include <fstream>

class clsBankClient :public clsPerson
{

private:
	string _AccontNumber;
	string _pincode;
	double _Accountbalance;
	bool _MarkForDelete=false;


	enum enMode { EmptyMode = 0, UpdataMode = 1 ,AddNewMode=2,DeleteMode};


	enMode _Mode;


	static clsBankClient  _ConvertLineToClientObject(string Line, string d = "#//#")
	{


		vector<string> vClient;
		vClient = clsString::Split(Line, d);

		return clsBankClient(enMode::UpdataMode, vClient[0], vClient[1],
			vClient[2], vClient[3], vClient[4], vClient[5], stod(vClient[6]));


	}
	static clsBankClient  _GetEmptyClientObject()
	{

		return clsBankClient(enMode::EmptyMode, " ", " ", " ", " ", " ", "", 0);
	}
	static string  _ConverClientObjectToLine(clsBankClient Client, string d = "#//#")
	{
		string Clientline;

		Clientline += Client.FirstName + d;
		Clientline += Client.LastName + d;
		Clientline += Client.Email + d;
		Clientline += Client.Phone + d;
		Clientline += Client.AccountNumber() + d;
		Clientline += Client.PinCode + d;
		Clientline += to_string(Client.Accountbalance);

		return Clientline;
	}
     static vector <clsBankClient>_LoadClientDataFromFill()
   {
	   vector <clsBankClient> sp;

	     fstream fileclient;

	    fileclient.open("Clients.txt", ios::in);

	   if (fileclient.is_open())
	   {
		  string line;
		  while (getline(fileclient, line))
		  {
			clsBankClient Client = _ConvertLineToClientObject(line);

			sp.push_back(Client);

		  }

		fileclient.close();
	   }
	  return sp;
    } 
     
     static void _SaveClientsDataToFill(vector<clsBankClient> vClients) {
	   fstream fileclient;

	   fileclient.open("Clients.txt", ios::out);

	   string DateLine;
	   if (fileclient.is_open())
	   {
		   for (clsBankClient c : vClients)
		   {
			   if (c.MarkForDeleted() == false)
			   {
				   DateLine = _ConverClientObjectToLine(c);
				   fileclient << DateLine << endl;
			   }
		   }
		   fileclient.close();
	   }
   }
	 static void _AddNewObjectToFile(string Line)
	 {
		 fstream fileclient;

		 fileclient.open("Clients.txt", ios::app|ios::out);

		
		 if (fileclient.is_open())
		 {
			 fileclient << Line << endl;
			 fileclient.close();
		 }
	 }
	 void _UpDateClient()
	{
		vector <clsBankClient> vClients = _LoadClientDataFromFill();

			for (clsBankClient& cl : vClients)
			{
				if (cl.AccountNumber() == AccountNumber())
				{
					cl = *this;
					break;
				}
			}
			
			_SaveClientsDataToFill(vClients);
		
	}
	 void _AddNew()
	{
		_AddNewObjectToFile(_ConverClientObjectToLine(*this));
	}

	
	  string _perpareTransferToline(double Amount, clsBankClient DestinationClient, string Seperator = "#//#")
	 {
		 string Transfer = "";

		 Transfer += clsDate::GetDateAndTime() + Seperator;
		 Transfer += this->_AccontNumber + Seperator;
		 Transfer += DestinationClient.AccountNumber() + Seperator;
		 Transfer += to_string(Amount) + Seperator;
		 Transfer += to_string(this->GetAccountbalance()) + Seperator;
		 Transfer += to_string(DestinationClient.Accountbalance) + Seperator;
		 Transfer += CurrentUser.UserName;

		 return Transfer;
	 }
	

     public:
		 enum enSaveResults { SvFailEmptyObject = 0, SvSucceeded = 1, SvFailedAccountnumberExists = 2 };

		 struct sTransfer
		 {
			 string AccountSoure;
			 string AccountDestination;

			 double BalancetSoure;
			 double BalanceDestination;

			 string DateTarnsfer;
			 string UserNameTarnsfer;
			 double Amount;
		 };

		 static sTransfer  _ConvertTransferDataToStruct(string lines, string Delimter = "#//#")
		 {
			 sTransfer TData;
			 vector<string> SplitTrnsfer;

			 SplitTrnsfer = clsString::Split(lines, Delimter);

			 TData.DateTarnsfer =( SplitTrnsfer[0]);

			 TData.AccountSoure = (SplitTrnsfer[1]);
			 TData.AccountDestination = (SplitTrnsfer[2]);
			 TData.Amount = (stod((SplitTrnsfer[3])));
			 TData.BalancetSoure = stod((SplitTrnsfer[4]));
			 TData.BalanceDestination = stod((SplitTrnsfer[5]));
			 TData.UserNameTarnsfer = (SplitTrnsfer[6]);
			 return TData;
		 }
		 static vector<sTransfer> LoadTrasferDataFromFill()
		 {
			 vector <sTransfer> sp;

			 fstream fileclient;

			 fileclient.open("TransferLog.txt", ios::in);

			 if (fileclient.is_open())
			 {
				 string line;
				 while (getline(fileclient, line))
				 {
					 sTransfer Client = _ConvertTransferDataToStruct(line);


					 sp.push_back(Client);

				 }

				 fileclient.close();
			 }
			 return sp;
		 }


	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string phone, string AccountNumber
		, string Pincode, double AccountBalance) :
		clsPerson(FirstName, LastName, Email, phone)
	{
		this->_Mode = Mode;
		_AccontNumber = AccountNumber;
		_pincode = Pincode;
		_Accountbalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccontNumber;
	}
	void SetAccountbalance(double Accountbalance)
	{
		_Accountbalance = Accountbalance;
	}
	double GetAccountbalance()
	{
		return this->_Accountbalance;
	}

	void SetPincode(string PinCode)
	{
		_pincode = PinCode;
	}
	string GetPincode()
	{
		return _pincode;
	}

	bool MarkForDeleted()
	{
		return _MarkForDelete;
	}







	__declspec(property(get = GetPincode, put = SetPincode))string PinCode;
	__declspec(property(get = GetAccountbalance, put = SetAccountbalance))double Accountbalance;



	//Lookfor Client  only by AccontNumber 

	static	clsBankClient Find(string ClientAccountNumber)
	{
		fstream fileclient;

		fileclient.open("Clients.txt", ios::in);

		if (fileclient.is_open())
		{
			string line;
			while (getline(fileclient, line))
			{
				clsBankClient Client = _ConvertLineToClientObject(line);
				if (Client.AccountNumber() == ClientAccountNumber)
				{
					fileclient.close();
					return Client;
				}

			}

			fileclient.close();
		}
		return _GetEmptyClientObject();
	}
	//Lookfor Client by AccontNumber And PinCode 
	static	clsBankClient Find(string ClientAccountNumber, string ClientPinCode)
	{
		fstream fileclient;

		fileclient.open("Clients.txt", ios::in);

		if (fileclient.is_open())
		{
			string line;
			while (getline(fileclient, line))
			{
				clsBankClient Client = _ConvertLineToClientObject(line);
				if ((Client.AccountNumber() == ClientAccountNumber) && (Client.PinCode == ClientPinCode))
				{
					fileclient.close();
					return Client;
				}

			}

			fileclient.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExit(string ClientAccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(ClientAccountNumber);


		return (!Client.IsEmpty());
	}

	enSaveResults Save()
	{
		switch (_Mode)
		{
		   case enMode::EmptyMode: 
		  {
			   if (IsEmpty()) 
			   {
				   return enSaveResults::SvFailEmptyObject;
				   break;
			   }
		  }
		

		  case enMode::UpdataMode:
		  {
			_UpDateClient();
		     	return enSaveResults::SvSucceeded;
			break;
		  }

		   case enMode::AddNewMode:
		   {
			   if (clsBankClient::IsClientExit(_AccontNumber))
			   {
				   return enSaveResults::SvFailedAccountnumberExists;
			   }

			   else 
			   {
				   _AddNew();
				   this->_Mode = enMode::UpdataMode;
				   return enSaveResults::SvSucceeded;
			   }
		   }case enMode::DeleteMode:
		   {
			   if (!clsBankClient::IsClientExit(_AccontNumber))
			   {
				   return enSaveResults::SvFailedAccountnumberExists;
			   }

			   else 
			   {
				  // _Delete();
				   return enSaveResults::SvSucceeded;
			   }
		   }
		}
	}
   
	static clsBankClient GetAddNewClientObject(string  AccountNumber)
	{

		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> vClients = _LoadClientDataFromFill();
		
		for (clsBankClient& cl : vClients)
		{
			if (cl.AccountNumber() == _AccontNumber)
			{
				cl._MarkForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFill(vClients);
		*this = _GetEmptyClientObject();

		return true;

	}



	static vector<clsBankClient> GetClientList()
	{
		return _LoadClientDataFromFill();


	}

	static double GetTotalBalance()
	{
		vector<clsBankClient> _vClient;
		_vClient = GetClientList();

		double TotalBalance = 0;

		for (clsBankClient vc : _vClient)
		{
			TotalBalance += vc.Accountbalance;
		}
		return TotalBalance;
	}
	double GetTotalBalanceObject()
	{
		return GetTotalBalance();
	}

	void Deposit(double Amount)
	{
		_Accountbalance += Amount;
		  Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > _Accountbalance)
		{
			return false;
		}

		_Accountbalance -= Amount;
		  Save();
	}

	bool Tansfer(double Amount, clsBankClient &DestinationClient)
	{
		if (Amount > Accountbalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		RegisterTransfer(Amount, DestinationClient);
		return true;

	}
	void RegisterTransfer(double Amount, clsBankClient DestinationClient)
	{
		string TransferLine = _perpareTransferToline(Amount, DestinationClient);
		fstream Tarnsferfill;

		Tarnsferfill.open("TransferLog.txt", ios::out|ios::app);

		if (Tarnsferfill.is_open())
		{
			Tarnsferfill << TransferLine << endl;

			Tarnsferfill.close();
		}

	}

};

