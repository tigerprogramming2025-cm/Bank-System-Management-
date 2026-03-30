#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include <iomanip>
#include  "clsShowListCurrenciesScreen.h"
#include  "clsShowFindCurrencyScreen.h"
#include "clsShowUpdateScreen.h"
#include "clsShowCurrencyCalculatorScreen.h"
class clsCurrencyScreen:protected clsScreen
{

 private:
     enum enCurrencyOptions{ListCurrency=1 ,FindCurrency=2,UpateRate=3,
              CalculateCurrency=4,MainMenue=5};


     static short _ReadCurrencyOption()
     {
         cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
         short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
         return Choice;
     }


     static void _ComeBackToCurrencyScreen()
     {
         cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Screen...\n";

         system("pause>0");
         ShowCurrencyScreen();
     }


     static void _showListCurencyScreen()
     {
         //cout << "\nList Currency Will be here...\n";
         clsShowListCurrenciesScreen::ShowListCurrencyScreen();
     }

     static void _showFindCurencyScreen()
     {
       //  cout << "\n Find Currency Will be here...\n";
         clsShowFindCurrencyScreen::ShowFindCurrencyScreen();
     }

     static void _showUpDateRateScreen()
     {
         //cout << "\n UpDate Currency Will be here...\n";
         clsShowUpdateScreen::ShowUpDateCurrencyRate();
     }

     static void _showCalculateCurencyScreen()
     {
        // cout << "\n Calculate Currency Will be here...\n";

         clsShowCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
     }
     static void _PerformCurrencyOptions(enCurrencyOptions Option)
     {
       switch (Option)
       {
         case enCurrencyOptions::ListCurrency:
         {
             system("cls");
             _showListCurencyScreen();
             _ComeBackToCurrencyScreen();
             break;
         }
         case enCurrencyOptions::FindCurrency:
         {
             system("cls");
             _showFindCurencyScreen();
             _ComeBackToCurrencyScreen();
             break;
         }

         case enCurrencyOptions::UpateRate:
         {
             system("cls");
             _showUpDateRateScreen();
             _ComeBackToCurrencyScreen();
             break;
         }

         case enCurrencyOptions::CalculateCurrency:
         {   system("cls");
         _showCalculateCurencyScreen();
         _ComeBackToCurrencyScreen();
         break;
         }

           case enCurrencyOptions::MainMenue:
           {

           }


           
       }
      }
public:

    static void ShowCurrencyScreen()
	{

        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Menue Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\t Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currency .\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency  Calculator \n";
        
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformCurrencyOptions((enCurrencyOptions)_ReadCurrencyOption());

	}

};

