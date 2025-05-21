#include "cashier.h"
#include "int_input_checked.h"
#include "bookType.h"
#include "lookUpBook.h"
#include "book_info_deref.h" // for bookInfoDeref
#include "orderedLinkedList.h"
#include "setw_consts.h"

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
void cashier(orderedLinkedList<bookType*> &bookInfo)
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

  int index;
  int availableStock;

  // Struct to track purchases
  struct Purchase {
    string isbn;
    string title;
    int quantity;
    double price;

    bool operator>=(const Purchase &other) const {
      return isbn >= other.isbn;
    }

    bool operator==(const Purchase &other) const {
      return isbn == other.isbn;
    }
  };

  orderedLinkedList<Purchase> shoppingCart;

  do
  {
    cout << "\033[2J\033[1;1H";
    bool hasPurchased = false;

    // Reset for this purchase
    shoppingCart.initializeList();
    totalPrice = 0;
    totalSale = 0;

    index = lookUpBook(bookInfo);

    // Check if lookUpBook returned -1 (segmentation fault fix)
    if (index == -1)
    {
      cout << "No book selected. Returning to the main menu.\n";
      break; // Exit the purchase loop
    }

    do
    {
      bookType* selectedBook = *bookInfo.get(index);
      availableStock = selectedBook->getQtyOnHand();

      if (availableStock == 0)
      {
        cout << "Sorry, " << selectedBook->getBookTitle() << " is out of stock.\n";
        break; // Exit the inner loop
      }

      cout << "How many do you want to purchase? ";

      quantity = intInputChecked("> ", 0, availableStock);

      if (quantity > availableStock)
      {
        cout << "Only " << availableStock << " available. Purchasing all " << availableStock << " copies.\n";
        quantity = availableStock;
      }

      cout << "Purchase Request: " << quantity << " x " << selectedBook->getBookTitle() << "\n";
      totalPrice += selectedBook->getRetail() * quantity;
      selectedBook->setQtyOnHand(selectedBook->getQtyOnHand() - quantity);
      hasPurchased = true;
      availableStock = selectedBook->getQtyOnHand();

      // Add to shopping cart
      shoppingCart.insert({
        selectedBook->getIsbn(),
        selectedBook->getBookTitle(),
        quantity,
        selectedBook->getRetail()
      });

      cout << "Do you want to add another book to this purchase? (Y/N): ";
      getline(cin, userChoice);

      if (toupper(userChoice[0]) == 'Y')
      {
        index = lookUpBook(bookInfo);

        // Check if lookUpBook returned -1 again (segmentation fault fix)
        if (index == -1)
        {
          cout << "No book selected. Returning to the main menu.\n";
          break; // Exit the inner loop
        }
      }

    } while (toupper(userChoice[0]) == 'Y');

    totalSale = totalPrice + totalPrice * SALESTAX;

    // Print the sales slip
    cout << setprecision(2) << fixed;
    cout << "███████████████████████████████████████████████████████████████████████████████████\n";
    cout << "█" << setw((WINDOW_OUTER - 25) / 2) << "" << "Serendipity Book Sellers" 
       << setw((WINDOW_OUTER - 25) / 2 + (WINDOW_OUTER - 25) % 2 + 2) << "" << "█\n";
    cout << "█" << setw(WINDOW_OUTER + 1) << "" << "█\n";
    cout << "█ Date: " << left << setw(WINDOW_OUTER - 6) << " " << date << "█\n";
    cout << "█" << setw(WINDOW_OUTER + 1) << "" << "█\n";
    cout << left << "█" << setw(6) << "Qty"
       << setw(14) << "ISBN"
       << setw(WINDOW_OUTER - 40) << "Title"
       << setw(12) << "Price"
       << setw(9) << "Total" << "█\n";
    cout << "█" << setfill('-') << setw(WINDOW_OUTER + 1) << '-' << setfill(' ') << "█\n";

    for (linkedListIterator<Purchase> it = shoppingCart.begin(); it != shoppingCart.end(); ++it) {
      const Purchase &item = *it;
      cout << "█" << right << setw(4) << item.quantity << "  "
         << left << setw(14) << item.isbn
         << setw(WINDOW_OUTER - 40) << item.title.substr(0, WINDOW_OUTER - 41)
         << '$' << right << setw(8) << item.price << " "
         << '$' << right << setw(9) << item.quantity * item.price << " █\n";
    }

    cout << "█" << setw(WINDOW_OUTER + 1) << "" << "█\n";
    cout << "█" << setw(WINDOW_OUTER + 1) << "" << "█\n";
    cout << left << setw(WINDOW_OUTER - 19) << "█" << left << setw(13)
       << "Subtotal  $" << right << setw(9)
       << totalPrice << " █\n";
    cout << left << setw(WINDOW_OUTER - 19) << "█" << left << setw(13)
       << "Tax     $" << right << setw(9)
       << totalPrice * SALESTAX << " █\n";
    cout << left << setw(WINDOW_OUTER - 19) << "█" << left << setw(13)
       << "Total     $" << right << setw(9)
       << totalSale << left << " █\n";
    cout << "█" << setw(WINDOW_OUTER + 1) << "" << "█\n";
    cout << "█" << setw((WINDOW_OUTER - 36) / 2) << "" << "Thank You for Shopping at Serendipity!" 
       << setw((WINDOW_OUTER - 36) / 2 + (WINDOW_OUTER - 36) % 2 - 1) << "" << "█\n";
    cout << "███████████████████████████████████████████████████████████████████████████████████\n";

    // Ask the user if they would like to make another purchase
    cout << "Would you like to make another purchase? (\033[32mY\033[0m/\033[31mN\033[0m): ";
    getline(cin, userChoice);

  } while (toupper(userChoice[0]) == 'Y');

  // Clear the screen
  cout << "\033[2J\033[1;1H";

  return;
}
