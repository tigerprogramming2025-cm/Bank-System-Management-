#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsMainScreen.h"

class clsLoginScreen:protected clsScreen
{
private:
	static bool  _Login()
	{
		string PassWord, UserName;
		bool LoginFiald = false;
		short Try = 3;


		do {
			

			if (LoginFiald) {

				Try--;

				cout << "\nInvalid [ User Name ] / [ User PassWord ] ! \n";
				cout << "You have "<< Try<<" Tralis to login :-( \n\n";
			}


			if (Try == 0)
			{
				cout << "Your are Locked after 3 faild trails \n";
				return false ;

			}

			cout<<"Enter  User Name ? ";
			UserName = clsInputValidate::ReadString();

			cout<<"Enter User PassWord ? ";
			PassWord = clsInputValidate::ReadString();
			CurrentUser = clsUser::Find(UserName, PassWord);
			LoginFiald = CurrentUser.IsEmpty();
		} while (LoginFiald);
		CurrentUser.RegisterDateUserLogin();
		clsMainScreen::ShowMainMenue();
		//ShowLoginScreen();
		return true;
	
	}
public:

	static bool ShowLoginScreen()
	{
		system("color 4F");
		system("cls");
		_DrawScreenHeader("\t\t\Login Screen ");
		return _Login();
	}




};

