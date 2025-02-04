#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	cout << setfill('#') << setw(80) << "#" << endl;

	cout << setfill(' ') << setw(50) << "Serendipity Book Sellers" << endl;
	cout << setw(37) << "Main Menu" << endl;

	cout << "#" << setw(80) << " " << "#" << endl;

	cout << setw(25) << " " << "1. Cashier Module";
	cout << setw(25) << " " << "2. Inventory Database Module";
	cout << setw(25) << " " << "3. Report Module";
	cout << setw(25) << " " << "4.\033[31mExit\033[0m ";
	cout << endl << endl << endl << endl;
	













	cout << setfill('#') << setw(80) << "#" << endl;

	return 0;
}
