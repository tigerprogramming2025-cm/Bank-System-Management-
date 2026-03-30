#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"
class clsShowFindCurrencyScreen:protected clsScreen
{  private:


             enum enFindType{eFindByCode=1,eFindByCountry=2 };

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

             static void _ShowRasulte(clsCurrency curncy)
        {
            if (!curncy.IsEmpty())
            {
                cout << "\nCurrency Found :-)\n";
                prinCurency(curncy);
            }
            else 
            {
                cout << "\nCurrency Was not Found :-(\n";
            }

          
        }
        
      
		 public:
             static void ShowFindCurrencyScreen()
             {
                 string Title = "\t\tFind  Currency Screen ";
                 clsScreen::_DrawScreenHeader(Title);
     
                 short stypFind;
                 cout << "Find by Code Enter [1],or Find By Country Enter [2] ?" << endl;
                 stypFind = clsInputValidate::ReadIntNumber();

                 string CuCode;

                 switch (stypFind )
                 {
                   case enFindType::eFindByCode: 
                   {
                       cout << " please Enter Currency code : " << endl;
                       CuCode = clsInputValidate::ReadString();
                       clsCurrency cur = clsCurrency::FindByCode(CuCode);
                       _ShowRasulte( cur );

                     break;
                   }

                    case enFindType::eFindByCountry:
                   {
                        cout << " please Enter Country Name: " << endl;
                     CuCode = clsInputValidate::ReadString();
                     clsCurrency cur = clsCurrency::FindByCountryName(CuCode);
                     _ShowRasulte(cur);

                     break;
                   }
                 }
             }

};

