#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
class clsShowListCurrenciesScreen :protected clsScreen
{
   private:
        static void _PrintCurrencyLine(clsCurrency h)
       {
           cout << setw(15) << left << "" << "| " << setw(27) << left << h.GetCountry();

           cout << "| " << setw(17) << left << h.GetCurrencyCode();
           cout << "| " << setw(40) << left << h.GetCurrencyName();
           cout << "| " << setw(10) << left << h.GetRate();
           ;



       }




public:
    static  void ShowListCurrencyScreen()
       {
           vector <clsCurrency> CurrencyList;
           CurrencyList = clsCurrency::GetCurrencies();


           string Title = "\tCurrencies  List Screen ";
           string SubTitle = " \t   (" + to_string(CurrencyList.size()) + ") Currency(s) ";

           clsScreen::_DrawScreenHeader(Title, SubTitle);
           cout << setw(15) << left << "" << "\n\t___________________________________________________________________________________"
               "________________________\n\n";
           cout << setw(15) << left << "" << "| " << setw(27) << left << "Countrt Name ";
           cout << "| " << setw(17) << left << "Currency Code";
           cout << "| " << setw(40) << left << "Currency Name";
           cout << "| " << setw(10) << left << "Rate";
           cout << setw(15) << left << "" << "\n\t___________________________________________________________________________________"
               "________________________\n";
           if (CurrencyList.size() == 0)
               cout << "\n\t\t\t\tThere is not Currency in the system\n";
           else


               for (clsCurrency& j : CurrencyList)
               {
                   _PrintCurrencyLine(j);
                   cout << endl;
               }
             cout << setw(15) << left << "" << "\n\t___________________________________________________________________________________"
               "________________________\n";
       }
};

