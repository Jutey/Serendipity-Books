// Author: Cade Coxon || Awesomoose

#include "cashier.h"

using namespace std;


// Testing the function
/*--------------------*
 |int main()          |
 |{                   |
 |	cashier();    |
 |                    |
 |	return 0;     |
 |}                   |
 *--------------------*/
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
	string userChoice;

	do //while (toupper(userChoice[0]) == 'Y')
	{
		// clear the screen
		cout << "\033[2J\033[1;1H";

		// start printing an input menu
		cout << "████████████████████████████████████████████████████████████████████████████████\n";
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
		cout << "████████████████████████████████████████████████████████████████████████████████\n";

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
		cout << "████████████████████████████████████████████████████████████████████████████████\n";
		cout << "█Serendipity Book Sellers                                                      █\n"
			  << "█                                                                              █\n";
		cout << "█ Date: "   << left << setw(70) << date <<                                   " █\n"
			  << "█                                                                              █\n";
		cout << left << "█"  << setw(5)  << "Qty"
			  			         << setw(14) << "ISBN"
						         << setw(38) << "Title"
						         << setw(12) << "Price"
						         << setw(8)  << "Total"    << " █\n";
		cout << "█" << setfill('-')      << setw(78)   <<  '-'    << setfill(' ') <<           "█\n";
		cout << "█" << right << setw(3)  << quantity   << "  "
			  			<< left	<< setw(14) << isbn
									<< setw(38) << title
			  << '$'	<< right	<< setw(7)  << pricePer   << "    "
	<< left << '$'	<< right	<< setw(7)  << totalPrice << " █\n";
		cout << "█                                                                              █\n"
			  << "█                                                                              █\n";
		cout << left  << setw(60) << "█" << left  << setw(13)
			  << "Subtotal    $"          << right << setw(7)
			  << totalPrice                        << " █\n";
		cout << left  << setw(60) << "█" << left  << setw(13)
			  << "Tax         $"          << right << setw(7)
			  << totalPrice * SALESTAX             << " █\n";
		cout << left  << setw(60) << "█" << left  << setw(13)
			  << "Total       $"          << right << setw(7)
			  << totalSale                << left  << " █\n";
		cout << "█                                                                              █\n";
		cout << "█ Thank You for Shopping at Serendipity!                                       █\n";
		cout << "████████████████████████████████████████████████████████████████████████████████\n";

		// ask the user if they would like to make another purchase
		cout << "Would you like to make another purchase? (Y/N): ";
		getline(cin, userChoice);

	} while (toupper(userChoice[0]) == 'Y');

	//clear the screen
	cout << "\033[2J\033[1;1H";

	return;
}
