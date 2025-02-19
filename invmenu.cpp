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
	cout << "\033[2J\033[1;1H";
	do
	{

		cout << "██████████████████████████████████████████████████████████████████████████████" << endl;
		cout << "█" << setw(24) << " " << setw(52) << "Serendipity Book Sellers"  << "█" << endl;
		cout << "█" << setw(28) << " " << setw(48) << "Inventory Database"        << "█" << endl;

		cout << "█" << setw(76) << " " << "█" << endl;

		cout << "█" << setw(24) << " " << setw(52) << "1. Look Up a Book"         << "█" << endl;
		cout << "█" << setw(24) << " " << setw(52) << "2. Add a Book"             << "█" << endl;
		cout << "█" << setw(24) << " " << setw(52) << "3. Edit a Book\'s Record"  << "█" << endl;
		cout << "█" << setw(24) << " " << setw(52) << "4. Delete a Book"          << "█" << endl;
		cout << "█" << setw(24) << " " << setw(61) << "\033[31m5. Return to the Main Menu\033[0m" << "█" << endl;
		cout << "█" << setw(76) << " " << "█" << endl;
		cout << "██████████████████████████████████████████████████████████████████████████████" << endl << endl;
	
		// error checking
		
			cout << "Enter Your Choice: ";
			cin  >> userChoice;
			cin.ignore(10000,'\n');
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(10000,'\n');
				cout << endl;
				cout << "Please enter a number in the range 1 - 5" << endl;
				cout << "Press ENTER to continue ..." << endl;
				cin.get();
				system("clear");
				continue;

			}

		// Menu navigation
		switch(userChoice)
		{

		case 1:
			cout << "You selected item 1." << endl;

			break;
		case 2:
			cout << "You selected item 2." << endl;

			break;
		case 3:
			cout << "You selected item 3." << endl;

			break;
		case 4:
			cout << "You selected item 4." << endl;

			break;
		case 5:
			cout << "You selected item 5." << endl;
			
			break;

		default:
			cout << endl;
			cout << "Please enter a number in the range 1 - 5" << endl;


		}

		cout << "\033[2J\033[1;1H";

	}while(userChoice != 5);



}
