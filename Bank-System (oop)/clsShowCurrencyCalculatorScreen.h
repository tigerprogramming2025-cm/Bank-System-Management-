#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"
class clsShowCurrencyCalculatorScreen:protected clsScreen
{
private:

    static void prinCurency(clsCurrency curncy ,string mas= "Currency Card:")
    {
        cout << mas;
        cout << "\n\n-----------------------------------------------\n";
        cout << "Countrt Name   : " << curncy.GetCountry() << endl;
        cout << "Currency Code  : " << curncy.GetCurrencyCode() << endl;
        cout << "Currency Name  : " << curncy.GetCurrencyName() << endl;
        cout << "Rate(1$)     = : " << curncy.GetRate() << endl;
        cout << "-----------------------------------------------\n";

    }

     static clsCurrency GetCurrecncy(string Massage="Please Enter Currency code ")
     {
          string CuCode;
          cout << Massage<< endl;
         CuCode = clsInputValidate::ReadString();
          while (!clsCurrency::IsCurrencyExit(CuCode))
         {
            cout << "sorry, Currency Code is not found try agin ? " << endl;
            CuCode = clsInputValidate::ReadString();
          }
          clsCurrency cur1 = clsCurrency::FindByCode(CuCode);

        return cur1;
    }

     static float _ResdAmount()
     {
         float Amount;
         cout << "Enter Amount To Exxchange:  ";
         Amount = clsInputValidate::ReadFloatNumber();
         return Amount;
     }

     static void _PrintCalculationResults(float Amount, clsCurrency cur1, clsCurrency cur2)
     {


         float Exchange = 0;

         if (cur1.GetCurrencyCode() != "USD") 
         {
             prinCurency(cur1, "\n\nCounver From:\n");

             Exchange = cur1.ExchangeToUsd(Amount);

             cout << Amount << " " << cur1.GetCurrencyCode() << " = " << Exchange
                 << " USD" << endl;
         }


         if (clsString::UpperAllString(cur2.GetCurrencyCode()) == clsString::UpperAllString("usd"))
         {
             return;
         }
        
             cout << "\n\nCounver From Usd To:\n\n";
             prinCurency(cur2,"To");
             Exchange = cur1.ExchangeToAnyCurrency(Amount, cur2);
             cout << Amount << " " << cur1.GetCurrencyCode() << " = " << Exchange << " "
                 << cur2.GetCurrencyCode() << endl;
        

     }
public:

    static void ShowCurrencyCalculatorScreen()
    {

        string Title = "\tCurrency Calculator Screen ";
        clsScreen::_DrawScreenHeader(Title);  

        clsCurrency cur1 = GetCurrecncy("\nPlease Enter Currency 1 Code ? ");
        clsCurrency cur2 = GetCurrecncy("\nPlease Enter Currency 2 Code ? ");
        float Amount = _ResdAmount();
      

        _PrintCalculationResults(Amount, cur1, cur2);
    }

};

