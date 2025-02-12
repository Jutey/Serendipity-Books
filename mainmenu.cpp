#include <iostream>
#include <iomanip>
#include "invmenu.h"
#include "cashier.h"
#include "reports.h"

using namespace std;

int main() {
	int choice;
	do{
	cout << "\033[2J\033[1;1H";
	cout << endl << endl;
	//cout << setfill("█") << setw(80) << "#" << endl;
	cout << left;
	cout << "████████████████████████████████████████████████████████████████████████████████";
	cout << endl;
	cout << "█" << setw(24) << " " << setw(54) << " " << "█" << endl;
	cout << "█" << setw(78) << " " << "█" << endl;
	cout << "█" << setw(28) << " " << setw(50) << "Serendipity Book Sellers" << "█" << endl;
	cout << "█" << setw(35) << " " << setw(43) << "Main Menu" << "█" << endl;

	cout << "█" << setw(78) << " " << "█" << endl;

	cout << "█" << setw(24) << " " << setw(54) << "1. Cashier Module" << "█" << endl;
	cout << "█" << setw(24) << " " << setw(54) << "2. Inventory Database Module" << "█" << endl;
	cout << "█" << setw(24) << " " << setw(54) << "3. Report Module" << "█" << endl;
	cout << "█" << setw(24) << " " << setw(63) << "\033[31m4. Exit\033[0m " << "█" << endl;
	cout << "█" << setw(78) << " " << "█" << endl;
	cout << "█" << setw(78) << " " << "█" << endl;
	cout << "█" << setw(78) << " " << "█" << endl;
	cout << "█" << setw(78) << " " << "█" << endl;


	cout << "████████████████████████████████████████████████████████████████████████████████";
	cout << endl << endl << endl;


	cout << "Enter Your Choice: ";
	cin >> choice;
   cin.ignore(10000, '\n');


	    if (cin.fail()) {
            cin.clear();  
            cin.ignore(10000, '\n');
            cout << "Please enter a valid number from the range of 1-4." << endl;
            continue;
        }

		switch(choice)
	{

		case 1:
			cout << "You selected item 1." << endl;
			cout << "Press ENTER to continue ...";
			cin.ignore(10000, '\n');
			cashier();
			cout << "\033[2J\033[1;1H";
			break;
		case 2:
			cout << "You selected item 2." << endl;
			cout << "Press ENTER to continue ...";
			cin.ignore(10000, '\n');
			invmenu();
			cout << "\033[2J\033[1;1H";
			break;
		case 3:
			cout << "You selected item 3." << endl;
			cout << "Press ENTER to continue ...";
			cin.ignore(10000, '\n');
			reports();
			cout << "\033[2J\033[1;1H";
			break;
		case 4:
			break;
		default:
			cout << "Please enter a number from the range of 1-4" << endl;

	}

	cout << "\033[2J\033[1;1H";

  }while(choice != 4);

  return 0;

}













