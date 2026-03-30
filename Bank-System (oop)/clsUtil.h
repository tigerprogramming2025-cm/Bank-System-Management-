#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;

class clsUtil
{

public:


	   static void Srand()
	{
		srand((unsigned)time(NULL));
	}
     	enum enCharType
	{
		CapitalLetter = 1, SmallLetter = 2, Digit = 3, MixChars = 4, SpecialChar = 5
	};


	static int RandomNumber(int From, int To)
	{
		int RandNum;

		RandNum = rand() % (To - From + 1) + From;

		return RandNum;
	}

	static char GetRandomCharacter(enCharType CharType)
	{
		if (CharType == MixChars)
		{
			CharType = (enCharType)RandomNumber(1, 3);
		}

		switch (CharType)
		{
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SmallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		case enCharType::SpecialChar:
		{
			return char(RandomNumber(33, 47));
			break;
		}

	default:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		}
	}
	
	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;

		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}

		return Word;
	}

	static string GenerateKey(enCharType CharType = CapitalLetter)
	{
		string Key = "";

		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4);

		return Key;
	}

	static void GenerateKeys(enCharType CharType , short NumberOfKeys)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}

	}

	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, short From, short To)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short WordLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateWord(CharType, WordLength);
		}
	}

	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey(CharType);
		}
	}

	static void Swap(int &A, int &B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(clsDate &A, clsDate& B)
	{
		clsDate Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static string Tabs(short NumberOfTabs)
	{
		string Tab = "";

		for (int i = 0; i < NumberOfTabs; i++)
		{
			Tab = Tab + "\t";
			cout << Tab;
		}
		
		return Tab;
    }

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}

		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}

		return Text;
	}

	static string NumberToText(long int n)
	{
		if (n == 0)
		{
			return "";
		}

		if (n >= 1 && n <= 19)
		{
			string arrystring[] = { " ","One","Two","Three","Four","Five","six","seven",
			"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fifteen","Sixteen","Seventten","Eighteen","Ninteen" };
			return arrystring[n] + "";
		}

		if (n >= 20 && n <= 99)
		{
			string arrystring[] = { "","","Twenity","Thirty","Forty","Fifty","sixty","seventy",
		   "Eighty","Ninty" };
			return arrystring[n / 10] + " " + NumberToText(n % 10);
		}

		if (n >= 100 && n <= 199)
		{
			return   " One Hundred " + NumberToText(n % 100);
		}

		if (n >= 200 && n <= 999)
		{
			return NumberToText(n / 100) + " Hundreds " + NumberToText(n % 100);
		}


		if (n >= 1000 && n <= 1999)
			return " One Thousand " + NumberToText(n % 1000);

		if (n >= 2000 && n <= 999999)
		{
			return NumberToText(n / 1000) + " Thousands " + NumberToText(n % 1000);

		}

		if (n >= 1000000 && n <= 1999999)
		{
			return  " One Million " + NumberToText(n % 1000000);

		}

		if (n >= 2000000 && n <= 999999999)
		{


			return  NumberToText(n / 1000000) + " Millions " + NumberToText(n % 1000000);

		}
		if (n >= 1000000000 && n <= 1999999999)
		{
			return  " One Billion " + NumberToText(n % 1000000000);

		}
		else
		{
			return  NumberToText(n / 1000000000) + " Billions " + NumberToText(n % 100000000);

		}


	}

};