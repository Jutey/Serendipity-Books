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
#include <vector>
#include "invmenu.h"
#include "addBook.h"
#include "bookType.h"

using namespace std;

void invmenu(vector<bookType> &bookInfo, int &bookCount, const int DBSIZE)
{
	
	int userChoice;
	userChoice = 0;
	cout << "\033[2J\033[1;1H";
	do
	{
		cout << left;

		cout << "████████████████████████████████████████████████████████████████████████████████" << endl;
		cout << "█" << setw(24) << " " << setw(54) << " " << "█" << endl;
		cout << "█" << setw(78) << " " << "█" << endl;
		cout << "█" << setw(28) << " " << setw(50) << "Serendipity Book Sellers" << "█" << endl;
		cout << "█" << setw(31) << " " << setw(47) << "Inventory Database" << "█" << endl;
		cout << "█" << setw(24) << " " << setw(54) << "1. Look Up a Book" << "█" << endl;
		if (bookCount > DBSIZE){
			cout << "█" << setw(24) << " " << setw(54) << "2. Add a Book" << "█" << endl;
		} else {
			cout << "█" << setw(24) << " " << setw(84) << "2. Add a Book\033[38;5;244m(DISABLED)\033[0m --\033[38;5;238m(20 books in inventory)\033[0m" << "█" << endl;
		}
		cout << "█" << setw(24) << " " << setw(54) << "3. Edit a Book\'s Record" << "█" << endl;
		cout << "█" << setw(24) << " " << setw(54) << "4. Delete a Book" << "█" << endl;
  		cout << "█" << setw(24) << " " << setw(63) << "\033[32m5. Return to Main Menu\033[0m " << "█" << endl;
		cout << "█" << setw(78) << " " << "█" << endl;
		cout << "█" << setw(78) << " " << "█" << endl;
		cout << "█" << setw(78) << " " << "█" << endl;
		cout << "█" << setw(78) << " " << "█" << endl;
		cout << "████████████████████████████████████████████████████████████████████████████████" << endl << endl;

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
			addBook(bookInfo, bookCount, DBSIZE);
   		 if (bookCount < DBSIZE) {
			addBook(bookInfo, bookCount, DBSIZE);
    } else {
			cout << "Cannot add more books. Inventory is full!\n";\
	 }

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
