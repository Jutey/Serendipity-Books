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

		cout << "██████████████████████████████████████████████████████████████████████████████" << endl;

		cout << "█" << setw(24) << " " << setw(54) << " " << "█" << endl;
		cout << "█" << setw(78) << " " << "█" << endl;
		cout << "█" << setw(28) << " " << setw(50) << "Serendipity Book Sellers" << "█" << endl;
		cout << "█" << setw(35) << " " << setw(43) << "Inventory Database" << "█" << endl;
		cout << "█" << setw(24) << " " << setw(54) << "1. Look Up a Book" << "█" << endl;
		if (bookCount > DBSIZE){
			cout << "█" << setw(24) << " " << setw(54) << "2. Add a Book" << "█" << endl;
		} else {
			cout << "█" << setw(24) << " " << setw(54) << "2. Add a Book\033[38;5;244m(DISABLED)\033[0m\n--\033[38;5;238m(20 books in inventory)\033[0m\n" << "█" << endl;
		}
		cout << "█" << setw(24) << " " << setw(54) << "3. Edit a Book\'s Record" << "█" << endl;
		cout << "█" << setw(24) << " " << setw(54) << "4. Delete a Book" << "█" << endl;
  		cout << "█" << setw(24) << " " << setw(63) << "\033[32m5. Return to Main Menu\033[0m " << "█" << endl;
		cout << "█" << setw(78) << " " << "█" << endl;
		cout << "█" << setw(78) << " " << "█" << endl;
		cout << "█" << setw(78) << " " << "█" << endl;
		cout << "█" << setw(78) << " " << "█" << endl;
	
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
			addBook(bookInfo, bookCount, DBSIZE);
    if (bookCount < DBSIZE) {
			addBook(bookInfo, bookCount, DBSIZE);
    } else {
			cout << "Cannot add more books. Inventory is full!\n";\
	 }

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
		cout << "\033[2J\033[1;1H";

	}while(userChoice != 5);



}
