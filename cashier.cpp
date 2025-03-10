// Author: Cade Coxon || Awesomoose

#include "cashier.h"
#include "int_input_checked.h"
#include "bookType.h"
#include "lookUpBook.h"

using namespace std;


// Testing the function
/*--------------------*
 |int main()      |
 |{           |
 |  cashier();  |
 |          |
 |  return 0;   |
 |}           |
 *--------------------*/
void cashier(vector<bookType>& bookInfo)
{
  const double SALESTAX = 0.06;

  string date;
  string isbn;
  string title;
  int  quantity;
  double pricePer;
  double totalPrice;
  double totalSale;
  string userChoice;

  do //while (toupper(userChoice[0]) == 'Y')
  {
    cout << "\033[2J\033[1;1H";

	  double totalPrice = 0.0;
	  bool hasPurchased = false;

    int index = lookUpBook(bookInfo);
    do 
    { //inner for loop
      
	    bookType& selectedBook = bookInfo[index];
	    int availableStock = selectedBook.getQtyOnHand();

	    if (availableStock == 0) 
	    {
	  	  cout << "Sorry, " << selectedBook.getBookTitle() << " is out of stock.\n";
	  	  continue;
	    }

	    cout << "How many do you want to purchase? ";

	    int quantity = intInputChecked("> ", 0, availableStock);

	    if (quantity > availableStock) 
	    {
		    cout << "Only " << availableStock << " available. Purchasing all " << availableStock << " copies.\n";
		    quantity = availableStock;
    	}

  	  cout << "Purchase Request: " << quantity << " x " << selectedBook.getBookTitle() << "\n";
  	  totalPrice += selectedBook.getRetail() * quantity;
	    selectedBook.setQtyOnHand(selectedBook.getQtyOnHand() - quantity);
  	  hasPurchased = true;

  	  cout << "Do you want to add another book to this purchase? (Y/N): ";
	    getline(cin, userChoice);

	  } while (toupper(userChoice[0]) == 'Y');


    totalSale  = totalPrice + totalPrice * SALESTAX;

    // print the sales slip
    cout << setprecision(2)      << fixed;
    cout << "████████████████████████████████████████████████████████████████████████████████\n";
    cout << "█Serendipity Book Sellers                            █\n"
         << "█                                        █\n";
    cout << "█ Date: "   << left << setw(70) << date <<                   " █\n"
         << "█                                        █\n";
    cout << left << "█"  << setw(5)  << "Qty"
                 << setw(14) << "ISBN"
                 << setw(38) << "Title"
                 << setw(12) << "Price"
                 << setw(8)  << "Total"  << " █\n";
    cout << "█"  << setfill('-')      << setw(78)   <<  '-'  << setfill(' ') <<       "█\n";
    cout << "█"  << right << setw(3)  << quantity   << "  "
         << left << setw(14) << bookInfo[index].getIsbn()
                 << setw(38) << bookInfo[index].getBookTitle()
         << '$'  << right    << setw(7)  << pricePer   << "  "
         << left << '$'      << right    << setw(7)  << totalPrice << " █\n";
    cout << "█                                        █\n"
         << "█                                        █\n";
    cout << left  << setw(60) << "█" << left  << setw(13)
         << "Subtotal  $"      << right << setw(7)
         << totalPrice            << " █\n";
    cout << left  << setw(60) << "█" << left  << setw(13)
         << "Tax     $"      << right << setw(7)
         << totalPrice * SALESTAX       << " █\n";
    cout << left  << setw(60) << "█" << left  << setw(13)
         << "Total     $"      << right << setw(7)
         << totalSale        << left  << " █\n";
    cout << "█                                        █\n";
    cout << "█ Thank You for Shopping at Serendipity!                     █\n";
    cout << "████████████████████████████████████████████████████████████████████████████████\n";

    // ask the user if they would like to make another purchase
    cout << "Would you like to make another purchase? (\033[32mY\033[0m/\033[31mN\033[0m): ";
    getline(cin, userChoice);

  } while (toupper(userChoice[0]) == 'Y');

  //clear the screen
  cout << "\033[2J\033[1;1H";

  return;
}
