#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsShowTransferScreen.h"
#include "clsShowTransferLog.h"
using namespace std;

class clsTransactionsMenue:protected clsScreen

{
private:

    enum enTransactions {
        Deposit = 1, Withdraw = 2,
        totalBalance = 3, Trasfer = 4, Transfer_Log = 5, backmainmenue = 6
    };

    static short _ReadTransactionMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 4? ");
        return Choice;
    }
    static void ComeBacktoTransaction()
    {
     
        cout << "\n\nPress any key to go back to Transactions  list ...";

        system("pause>0");
        ShowTransactionMenue();

    }

       

        static void _ShowWithdrawScreen()  
           
        {
            //cout << "\n Withdraw Screen will be here.... \n";
            clsWithdrawScreen::ShowWithdrawScreen();
        }
           
        
        static void _ShowDepositScreen()
        {
        //    cout << "\n Deposit Screen will be here.... \n";
            clsDepositScreen::ShowDepositScreen();
        }
     
        
        static void _ShowTotalBalanceScreen()
        {
        //cout << "\n Total Balance Screen will be here.... \n";
            clsTotalBalancesScreen::ShowTotalBalancesScreen();
        }
       
        
        static void _ShowTransferScreen()
        {
            clsShowTransferScreen::ShowDepositScreen();
        }

           static void _ShowTransferLogScreen()
        {
               clsTransferLog::ShowTransferRecordsScreen();
        }
        
        

    static   void _PerfromTransactionMenueOption(enTransactions TransAction)
    {
        switch (TransAction)
        {
        case enTransactions::Deposit:
            system("cls");
            _ShowDepositScreen();
            ComeBacktoTransaction();
            break;
        case enTransactions::Withdraw:
            system("cls");
            _ShowWithdrawScreen();
            ComeBacktoTransaction();
            break;

        case enTransactions::totalBalance:
            system("cls");
            _ShowTotalBalanceScreen();
            ComeBacktoTransaction();

            break;

        case enTransactions::Trasfer:
                system("cls");
                _ShowTransferScreen();
                ComeBacktoTransaction();
            break; 

        case enTransactions::Transfer_Log:
            system("cls");
                _ShowTransferLogScreen();
                ComeBacktoTransaction();
            break;
        case enTransactions::backmainmenue:
           
            break;
        }
    }

public:
   
   
    static void ShowTransactionMenue()
    {

        if (!CheckAccessRights(clsUser::Users_Permissions::UTransactions))
        {
            return;
        }
        system("cls");
        system("color 9F");
        _DrawScreenHeader("\tTransactions Menue Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransactions Menue Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n"; 
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromTransactionMenueOption((enTransactions)_ReadTransactionMenueOption());
    }

};

