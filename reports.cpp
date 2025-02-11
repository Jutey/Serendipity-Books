#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int choice;
	do{
	cout << endl << endl;
	//cout << setfill("█") << setw(80) << "#" << endl;
	cout << left;
	cout << "████████████████████████████████████████████████████████████████████████████████";
	cout << endl;
	cout << "█" << setw(24) << " " << setw(54) << " " << "█" << endl;
	cout << "█" << setw(78) << " " << "█" << endl;
	cout << "█" << setw(28) << " " << setw(50) << "Serendipity Book Sellers" << "█" << endl;
	cout << "█" << setw(35) << " " << setw(43) << "Reports" << "█" << endl;

	cout << "█" << setw(78) << " " << "█" << endl;

	cout << "█" << setw(24) << " " << setw(54) << "1. Inventory Listing" << "█" << endl;
	cout << "█" << setw(24) << " " << setw(54) << "2. Inventory Wholesale Value" << "█" << endl;
	cout << "█" << setw(24) << " " << setw(54) << "3. Inventory Retail Value" << "█" << endl;
	cout << "█" << setw(24) << " " << setw(54) << "4. Listing by Quantity" << "█" << endl;
	cout << "█" << setw(24) << " " << setw(54) << "5. Listing by Cost" << "█" << endl;
	cout << "█" << setw(24) << " " << setw(54) << "6. Listing by Age" << "█" << endl;
	cout << "█" << setw(24) << " " << setw(63) << "\033[32m7. Return to Main Menu\033[0m " << "█" << endl;
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
            cout << "Please enter a valid number from the range of 1-7." << endl;
            continue;
        }

		switch(choice)
	{

		case 1:
			cout << "You selected item 1." << endl;
			cout << "Press ENTER to continue ...";
			cin.ignore(10000, '\n');
			break;

		case 2:
			cout << "You selected item 2." << endl;
			cout << "Press ENTER to continue ...";
			cin.ignore(10000, '\n');
			break;

		case 3:
			cout << "You selected item 3." << endl;
			cout << "Press ENTER to continue ...";
			cin.ignore(10000, '\n');
			break;

		case 4:
			cout << "You selected item 4." << endl;
			cout << "Press ENTER to continue ...";
			cin.ignore(10000, '\n');
			break;
		case 5:
			cout << "You selected item 5." << endl;
			cout << "Press ENTER to continue ...";
			cin.ignore(10000, '\n');
			break;
		case 6:
			cout << "You selected item 6." << endl;
			cout << "Press ENTER to continue ...";
			cin.ignore(10000, '\n');
			break;
		case 7:
			exit(0);
		default:
			cout << "Please enter a number from the range of 1-7" << endl;

	}
	system("clear");

  }while(choice != 7);

  return 0;

}













