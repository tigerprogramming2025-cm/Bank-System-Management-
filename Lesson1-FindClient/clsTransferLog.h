
#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"


using namespace std;

class clsTransferLog :protected clsScreen
{

private:
    static void _PrintTransferLogRecordLine(clsBankClient::sTransfer h)
    {
        cout << setw(8) << left << "" << "| " << setw(25) << left << h.DateTarnsfer;

        cout << "| " << setw(10) << left << h.AccountSoure;
        cout << "| " << setw(10) << left << h.AccountDestination;
        cout << "| " << setw(10) << left << h.Amount;
        cout << "| " << setw(10) << left << h.BalancetSoure;
        cout << "| " << setw(10) << left << h.BalanceDestination;
        cout << "| " << setw(10) << left << h.UserNameTarnsfer;



    }


public:


    static void ShowTransferRecords()
    {
        vector <clsBankClient::sTransfer> TransferRecord;
        TransferRecord = clsBankClient::LoadTrasferDataFromFill();


        string Title = "\tTransfer Log List Screen ";
        string SubTitle = " \t   (" + to_string(TransferRecord.size()) + ") Record(s) ";

        clsScreen::_DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________"
            "________________________\n\n";
        cout << setw(8) << left << "" << "| " << setw(25) << left << "Date/Time ";
        cout << "| " << setw(10) << left << " s.Acct";
        cout << "| " << setw(10) << left << "d.Acct";
        cout << "| " << setw(10) << left << "Amount";
        cout << "| " << setw(10) << left << "s.Balance";
        cout << "| " << setw(10) << left << "d.Balance";
        cout << "| " << setw(10) << left << "User";
        cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________"
            "________________________\n";
        if (TransferRecord.size() == 0)
            cout << "\n\t\t\t\tThere is not Record in the system\n";
        else


            for (clsBankClient::sTransfer& j : TransferRecord)
            {
                _PrintTransferLogRecordLine(j);
                cout << endl;
            }
        cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________"
            "________________________\n";

    }
};
