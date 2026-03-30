#pragma once
#include <iostream>
#include "clsDate.h"
#include "Global.h"


using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
       cout << "\t\t\t\t\t User: "<<CurrentUser.UserName;
       cout << "\n\t\t\t\t\t Date: "<< clsDate::DateToString(clsDate()) << "\n\n";
    }

    static bool CheckAccessRights(clsUser::Users_Permissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t________________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact Your Admin";
            cout << "\n\t\t\t\t\t________________________________________\n\n";
            return false;

        }
        else
        {
            return true;
        }
    }

};

