// Author: Cade Coxon || Awesomoose
#include "cashier.h"
using namespace std;

void cashier()
{
	const double SALESTAX = 0.06;

	string date;
	string isbn;
	string title;
	int    quantity;
	double pricePer;
	double totalPrice;
	double totalSale;

	// inform the user of their choice
	cout << "You selected 1 to go to the cashier module\n"
		  << "Press ENTER to continue...";
	cin.ignore(10000, '\n');

	// clear the screen
	cout << "\033[2J\033[1;1H";

	// start printing an input menu
	cout << setfill('#') << setw(80) << '#' << setfill(' ') << endl;
	cout << "Serendipity Booksellers\n Cashier Module\n\n";

	// ask the user for their input
	cout << "Date: ";
	getline(cin, date);

	cout << "Quantity of Book: ";
	cin  >> quantity;
	cin.ignore(10000, '\n');

	cout << "ISBN: ";
	getline(cin, isbn);

	cout << "Title: ";
	getline(cin, title);

	cout << "Price: ";
	cin  >> pricePer;
	cin.ignore(10000, '\n');
	cout << endl << endl;

	// finish the input menu
	cout << setfill('#') << setw(80) << '#' << setfill(' ') << endl;

	// ask the user to confirm
	cout << "Press ENTER to continue...";
	cin.ignore(10000, '\n');

	// clear the screen
	cout << "\033[2J\033[1;1H";

	// calculate totalSale and totalPrice
	totalPrice = pricePer   * quantity;
	totalSale  = totalPrice + totalPrice * SALESTAX;

	// print the sales slip
	cout << setprecision(2)          << fixed;
	cout << setfill('#') << setw(80) << '#' << setfill(' ') << endl;
	cout << " Serendipity Book Sellers\n\n";
	cout << " Date: " << date << endl << endl;
	cout << left << ' '  << setw(5)  << "Qty"
		  			         << setw(14) << "ISBN"
					         << setw(38) << "Title"
					         << setw(12) << "Price"
					         << setw(8)  << "Total" << endl;
	cout << setfill('-') << setw(80) << '-' << setfill(' ') << endl;
	cout << ' ' << right << setw(3)  << quantity   << "  "
		  			<< left	<< setw(14) << isbn
								<< setw(38) << title
		  << '$'	<< right	<< setw(7)  << totalPrice << "    "
<< left << '$'	<< right	<< setw(7)  << totalPrice << endl;
	cout << endl  << endl;
	cout << right << setw(57) << ' ' << left  << setw(13)
		  << "Subtotal     $"         << right << setw(7)
		  << totalPrice                        << endl;
	cout << right << setw(57) << ' ' << left  << setw(13)
		  << "Tax          $"         << right << setw(7)
		  << totalPrice * SALESTAX             << endl;
	cout << right << setw(57) << ' ' << left  << setw(13)
		  << "Total        $"         << right << setw(7)
		  << totalSale                << left  << endl       << endl;
	cout << "  Thank You for Shopping at Serendipity!"      << endl;
	cout << setfill('#') << setw(80) << '#' << setfill(' ') << endl;

	// ask the user to confirm
	cout << "Press ENTER to continue...";
	cin.ignore(10000, '\n');

	// clear the screen
	cout << "\033[2J\033[1;1H";
	cout << right;

	return;
}

