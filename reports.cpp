#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

#include "reports.h"
#include "int_input_checked.h"
#include "setw_consts.h"
#include "bookType.h"
#include "book_info_deref.h" // for bookInfoDeref
#include "linkedlist.h"
#include "orderedLinkedList.h"
#include "book_info_deref.h"

using namespace std;
void repListing(orderedLinkedList<bookType*> &bookInfo){
  // Pull the current Date from the system
  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  int year = localTime->tm_year + 1900;
  int month = localTime->tm_mon + 1;
  int day = localTime->tm_mday;
  string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

  int totalBooks = bookInfo.length();
  int totalPages = (totalBooks + 9) / 10;
  int currentPage = 1;
  string choice;

  do {
    int startingIndex = (currentPage - 1) * 10;
    int endingIndex = min(startingIndex + 10, totalBooks);

    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"
      << endl;
    cout << "█" << setw(118) << right << "█" << endl;
    cout << "█" << setw(65) << right << "SERENDIPITY BOOKSELLERS" << setw(54) << right << "█" << endl;
    cout << "█" << setw(62) << right << "REPORT LISTING" << setw(57) << right << "█" << endl;
    cout << "█" << setw(118) << right << "█" << endl;
    cout << "█"  << date     <<      "PAGE:" << currentPage << " of " << totalPages <<    " DATABASE SIZE: 20     CURRENT BOOK COUNT: 20           █" << endl;
    cout << "█" << setw(118) << right << "█" << endl;

    cout << "█  TITLE                          ISBN         AUTHOR              PUBLISHER   DATE ADDED QTY O/H WHOLESALE RETAIL █" << endl;
    cout << "█  ----------------------------  ----------   -------------------  ----------  ----------- ------- --------- -------█" << endl;

    int idx = 0;
    int printed = 0;
    for (linkedListIterator<bookType*> it = bookInfo.begin(); it != bookInfo.end(); ++it, ++idx) {
      if (idx < startingIndex) continue;
      if (idx >= endingIndex) break;
      const bookType& book = **it;
      cout << "█  " << left << setw(30) << book.getBookTitle().substr(0, 30)
        << setw(12) << book.getIsbn().substr(0, 12)
        << setw(21) << book.getAuthor().substr(0, 21)
        << setw(12) << book.getPublisher().substr(0, 12)
        << setw(12) << book.getDateAdded()
        << setw(8)  << book.getQtyOnHand()
        << "$" << right << setw(7) << fixed << setprecision(2) << book.getWholesale()
        << "   $" << right << setw(7) << book.getRetail()
        << " █" << endl;
      ++printed;
    }

    if (currentPage < totalPages) {
      cout << "█  Type \"2\" to go to the next page, or any other key to return...                          █" << endl;
    } else {
      cout << "█  Press any key to return...                                                                █" << endl;
    }
    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████" << endl;

    getline(cin, choice);
    if (choice == "2" && currentPage < totalPages) {
      currentPage++;
    } else {
      break;
    }
  } while (true);
}


void reports(const orderedLinkedList<bookType*> &bookInfo)
{
  int choice;
  do
  {
    cout << "\033[2J\033[1;1H";
    cout << endl << endl;
    //cout << setfill("█") << setw(80) << "#" << endl;
    cout << left;
    cout << "████████████████████████████████████████████████████████████████████████████████";
    cout << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(MENU_HEAD_PADDING) << " " << setw(MENU_HEAD_WIDTH) << "Serendipity Book Sellers" << "█" << endl;
    cout << "█" << setw(BOOK_INFO_SUBTITLE_PADDING) << " " << setw(BOOK_INFO_SUBTITLE_WIDTH) << "Reports" << "█" << endl;

    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;

    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "1. Inventory Listing" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "2. Inventory Wholesale Value" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "3. Inventory Retail Value" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "4. Listing by Quantity" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "5. Listing by Cost" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "6. Listing by Age" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_EXIT_PADDING) << "\033[32m7. Return to Main Menu\033[0m " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;


    cout << "████████████████████████████████████████████████████████████████████████████████";
    cout << endl << endl << endl;

    choice = intInputChecked("Enter Your Choice", 1, 7);

    switch(choice)
    {

      case 1:
      //  cout << "You selected item 1." << endl;
      //  cout << "Press ENTER to continue ...";
      //  cin.ignore(numeric_limits<streamsize>::max(), '\n');
      if (bookInfo.isEmptyList())
      {
        cout << "█" << setw(MENU_BODY_PADDING) << " " << "The database is empty. Please add a book." << setw(35) << "█" << endl;
      }
      else
      {
        repListing(bookInfo);
      }

      case 2:
        cout << "You selected item 2." << endl;
        cout << "Press ENTER to continue ...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;

      case 3:
        cout << "You selected item 3." << endl;
        cout << "Press ENTER to continue ...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;

      case 4:
        cout << "You selected item 4." << endl;
        cout << "Press ENTER to continue ...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
      case 5:
        cout << "You selected item 5." << endl;
        cout << "Press ENTER to continue ...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
      case 6:
        cout << "You selected item 6." << endl;
        cout << "Press ENTER to continue ...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
      case 7:
        break;
      default:
        cout << "Please enter a number from the range of 1-7" << endl;

    }
    cout << "\033[2J\033[1;1H";

  } while(choice != 7);
}

