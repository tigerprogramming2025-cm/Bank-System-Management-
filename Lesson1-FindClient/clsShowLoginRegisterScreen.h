#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include <iomanip>


using namespace std;
class clsShowLoginRegisterScreen:protected clsScreen
{
    private:
        static void _PrintLoginregisterRecordLine(clsUser::sRegisterLogin h)
        {
            cout << setw(8) << left << "" << "| " << setw(35) << left << h.DateAndTime;

            cout << "| " << setw(20) << left << h.LoUserName;
            cout << "| " << setw(20) << left << h.LoPassWord;
            cout << "| " << setw(10) << left << h.LoPermission;



        }


public:
        static	void ShowLoginRegisterScreen()
        {

            if (!CheckAccessRights(clsUser::Users_Permissions::ULoginRegister))
            {
                return;
            }
            system("cls");
            vector <clsUser::sRegisterLogin> vClient = clsUser::GetRegisterDataUserLogin();

            string Title = "\tLogin Register List Screen ";
            string SubTitle = " \t   (" + to_string(vClient.size()) + ") Record(s) ";

            clsScreen::_DrawScreenHeader(Title, SubTitle);
            cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________"
                "________________________\n\n";
            cout << setw(8) << left << "" << "| " << setw(35) << left << "Date/Time ";
            cout << "| " << setw(20) << left << "User Name";
            cout << "| " << setw(20) << left << "PassWord";
            cout << "| " << setw(10) << left << "Permission ";

            cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________"
                "________________________\n";
            if (vClient.size() == 0)
                cout << "\n\t\t\t\tThere is not Record in the system\n";
            else


                for (clsUser::sRegisterLogin& j : vClient)
                {
                    _PrintLoginregisterRecordLine(j);
                    cout << endl;
                }
            cout << setw(8) << left << "" << "\n\t___________________________________________________________________________________"
                "________________________\n";

        }





};

