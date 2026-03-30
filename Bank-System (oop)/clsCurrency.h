#pragma once
#include<iostream>
#include <fstream>
#include "clsString.h"
#include <vector>
class clsCurrency
{

private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _Country;
	string _CurrenctCode;
	string _CurrencyName;
	float _Rate;


	static clsCurrency  _ConvertLineToCurrencyObject(string Line, string d = "#//#")
	{


		vector<string> vClient;
		vClient = clsString::Split(Line, d);

		return clsCurrency(enMode::UpdateMode, vClient[0], vClient[1],vClient[2], stof(vClient[3]));


	}
	static clsCurrency  _GetEmptyCurrencyObject()
	{

		return clsCurrency(enMode::EmptyMode, " ", " ", " ", 0);
	}
	static string  _ConverCurrencyObjectToLine(clsCurrency Currency, string d = "#//#")
	{
		string Currencyline;

		Currencyline += Currency.GetCountry() + d;
		Currencyline += Currency.GetCurrencyCode() + d;
		Currencyline += Currency.GetCurrencyName() + d;
		Currencyline += to_string(Currency.GetRate()) ;
	

		return Currencyline;
	}
	static vector <clsCurrency>_LoadCurrencyDataFromFill()
	{
		vector <clsCurrency> sp;

		fstream fileclient;

		fileclient.open("Currencies.txt", ios::in);

		if (fileclient.is_open())
		{
			string line;
			while (getline(fileclient, line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(line);

				sp.push_back(Currency);

			}

			fileclient.close();
		}
		return sp;
	}


	void _UpdateCurrency()
	{
		vector <clsCurrency> Vcurrency = _LoadCurrencyDataFromFill();

		fstream file;
		string line;
		file.open("Currencies.txt", ios::out );

		if (file.is_open())
		{
			for (clsCurrency &c : Vcurrency)
			{
				if (this->GetCurrencyCode() == c.GetCurrencyCode())
				{
					c = *this;
				}
				line = _ConverCurrencyObjectToLine(c);
				
				file << line << endl;

			}

			file.close();
		}
	}

    public:
		clsCurrency(enMode Mode,string Country,  string CurrencyCode, string CurrencyName, float Rate)
		{
			_Mode = Mode;
			_Country = Country;
			_CurrenctCode = CurrencyCode;
			_CurrencyName = CurrencyName;
			_Rate = Rate;
		}

		string GetCurrencyCode()
		{
			return _CurrenctCode;
		}

	    string GetCurrencyName()
		{
			return _CurrencyName;
		}

		string GetCountry()
		{
			return _Country;
		}

		float GetRate()
		{
			return _Rate;
		}

	  

		static  vector <clsCurrency> GetCurrencies()
		{
			return _LoadCurrencyDataFromFill();
		}

		  bool IsEmpty()
		{
			return (_Mode == enMode::EmptyMode);
		}

	     static bool IsCurrencyExit(string CurrencyCode)
	     {

		  clsCurrency cu = clsCurrency::FindByCode(CurrencyCode);
		  
			  return ((!cu.IsEmpty()));
		 
         }

		 static	clsCurrency FindByCode(string CurrencyCode)
		{
			
			fstream currencyfill;
			currencyfill.open("Currencies.txt", ios::in);

			string line;
			
			if (currencyfill.is_open())
			{
				while (getline(currencyfill, line))
				{
					clsCurrency currency = _ConvertLineToCurrencyObject(line);
					if (currency.GetCurrencyCode() == clsString::UpperAllString(CurrencyCode))
					{
						return currency;
					}

				}
				
				return  _GetEmptyCurrencyObject();
			}



		}
		 static	clsCurrency FindByCountryName(string Country)
		 {

			 fstream currencyfill;
			 currencyfill.open("Currencies.txt", ios::in);

			 string line;

			 if (currencyfill.is_open())
			 {
				 while (getline(currencyfill, line))
				 {
					 clsCurrency currency = _ConvertLineToCurrencyObject(line);
					 if (clsString::UpperAllString(currency.GetCountry()) == clsString::UpperAllString(Country))
					 {
						 return currency;
					 }

				 }

				 return  _GetEmptyCurrencyObject();
			 }



		 }

		void UpdateRate(float Rate)
		{
			_Rate = Rate;
			_UpdateCurrency();
			
		}

		float ExchangeToUsd(float Amount)
		{
			return (Amount / this->GetRate());
		}
		
		float ExchangeToAnyCurrency(float Amount, clsCurrency ExchangeToCurrency)
		{
			Amount = ExchangeToUsd(Amount);
			if (ExchangeToCurrency.GetCurrencyCode() == "USD")
			{
				return  Amount;
			}

			return (Amount * ExchangeToCurrency.GetRate());
		}
};

