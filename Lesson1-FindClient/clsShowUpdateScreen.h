#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"

class clsShowUpdateScreen :protected  clsScreen
{


  private:  
      static void prinCurency(clsCurrency curncy)
  {
      cout << "Currency Card:";
      cout << "\n\n-----------------------------------------------\n";
      cout << "Countrt Name   : " << curncy.GetCountry() << endl;
      cout << "Currency Code  : " << curncy.GetCurrencyCode() << endl;
      cout << "Currency Name  : " << curncy.GetCurrencyName() << endl;
      cout << "Rate(1$)     = : " << curncy.GetRate() << endl;
      cout << "-----------------------------------------------\n";

  }
      static float _ReadNewRate()
      {  
          float Rate;
          cout << "\nUpdate Currency Rate :\n";
          cout << "_____________________________\n\n";
          cout << "Enter new Rate ? ";
          Rate = clsInputValidate::ReadFloatNumber();
          return Rate;

      }

   public :
     static void ShowUpDateCurrencyRate()
    {
         _DrawScreenHeader("\tUpDate Currency Screen");

         string CuCode;
         cout << "Enter Currency Code " << endl;
         CuCode = clsInputValidate::ReadString();
         while (!clsCurrency::IsCurrencyExit(CuCode))
         {
             cout << "sorry, Currency Code is not found try agin ? " << endl;
             CuCode = clsInputValidate::ReadString();
         }

         clsCurrency cur = clsCurrency::FindByCode(CuCode);
         prinCurency(cur);
          
         if (clsInputValidate::IsSoureYesOrNo("\n Are you sure you want to updata the rate of this currency"))
         {
             cur.UpdateRate( _ReadNewRate());
             cout << "\nUpdate Currency Rate Successfully :-)\n\n";
             prinCurency(cur);


         }
    }

};

