#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	char choice;
	
	cout << endl << endl;
	//cout << setfill("█") << setw(80) << "#" << endl;
	cout << left;
	cout << "████████████████████████████████████████████████████████████████████████████████";
	cout << "█" << setw(78) << " " << "█";
	cout << "█" << setw(78) << " " << "█" << endl;
	cout << "█" << setw(28) << " " << setw(52) << "Serendipity Book Sellers" << "█" << endl;
	cout << "█" << setw(35) << " " << setw(45) << "Main Menu" << "█" << endl;

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
	
	choice = toupper(choice);
do{
	cout << "Enter Your Choice: ";
	cin >> choice;

		switch(choice)
	{

		case '1' :
			cout << "You selected item 1." << endl;
			cout << "Press ENTER to continue ...";
			cin.ignore();
			break;
		case '2' :
			cout << "You selected item 2." << endl;
			cout << "Press ENTER to continue ...";
			cin.ignore();
			break;
		case '3' :
			cout << "You selected item 3." << endl;
			cout << "Press ENTER to continue ...";
			cin.ignore();
		case '4':
			exit(0);
			break;
		default:
			cout << "Please enter a number from the range of 1-4" << endl;

	}


  }while(choice != '4');

  return 0;

}













