/***********************************************
* Serendipity Project
*
* invmenu.cpp
*
* Purpose: to manage each book stored on this 
*			  file
*
* By: Romewin Villacorte
************************************************/ 

#include "invmenu.h"

using namespace std;

void invmenu()
{
	
	int userChoice;
	userChoice = 0;

	do
	{

		cout << "██████████████████████████████████████████████████████████████████████████████" << endl;
		cout << "█" << setfill(' ') << setw(49) << "Serendipity Book Sellers" << setw(30) << "█" << endl;
		cout << "█" << setw(45) << "Inventory Database" << setw(34) << "█" << endl;

		cout << "█" << setw(79) << "█" << endl;

		cout << "█" << setw(24) << " " << "1. Look Up a Book" << setw(38) << "█" << endl;
		cout << "█" << setw(24) << " " << "2. Add a Book" << setw(42) << "█" << endl;
		cout << "█" << setw(24) << " " << "3. Edit a Book\'s Record" << setw(32) << "█" << endl;
		cout << "█" << setw(24) << " " << "4. Delete a Book" << setw(39) << "█" << endl;
		cout << "█" << setw(24) << " " << "5. Return to the Main Menu" << setw(29) << "█" << endl;
		cout << "█" << setw(79) << "█" << endl;
	
		// error checking
		
			cout << "█" << setw(24) << " " << "Enter Your Choice: ";
			cin  >> userChoice;
			cin.ignore(10000,'\n');
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(10000,'\n');
				cout << "█" << setw(79) << "█" << endl;
				cout << "█" << setw(24) << " " << "Please enter a number in the range 1 - 5" << setw(15) << "█" << endl;
				cout << "█" << setw(24) << " " << "Press ENTER to continue ..." << setw(28) << "█" << endl;
				cout << "██████████████████████████████████████████████████████████████████████████████";
				cin.get();
				system("clear");
				continue;

			}

		// Menu navigation
		switch(userChoice)
		{

		case 1:
			cout << "█" << setw(24) << " " << "You selected item 1." << setw(35) << "█" << endl;

			break;
		case 2:
			cout << "█" << setw(24) << " " << "You selected item 2." << setw(35) << "█" << endl;

			break;
		case 3:
			cout << "█" << setw(24) << " " << "You selected item 3." << setw(35) << "█" << endl;

			break;
		case 4:
			cout << "█" << setw(24) << " " << "You selected item 4." << setw(35) << "█" << endl;

			break;
		case 5:
			cout << "█" << setw(24) << " " << "You selected item 5." << setw(35) << "█" << endl;
			
			break;

		default:
			cout << "█" << setw(79) << "█" << endl;
			cout << "█" << setw(24) << " " << "Please enter a number in the range 1 - 5" << setw(15) << "█" << endl;


		}

		cout << "█" << setw(24) << " " << "Press ENTER to continue ..." << setw(28) << "█" << endl;
		cout << "██████████████████████████████████████████████████████████████████████████████";
		cin.ignore(10000,'\n');
		system("clear");

	}while(userChoice != 5);


	return 0;
}
