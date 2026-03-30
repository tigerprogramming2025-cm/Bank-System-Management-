
#include <iostream>
#include "clsLoginScreen.h"
#include "clsMainScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


using namespace std;
int main()
{
   
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}
	
}

