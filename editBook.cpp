#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

#include "bookType.h" 
#include "int_input_checked.h"
#include "editBook.h"
#include "lookUpBook.h"
#include "setw_consts.h"
#include "book_info_deref.h"

using namespace std;


//bookCount is a variable that should be addressed and initialized within main
//Default array/vector name is bookInfo if that's easiest, otherwise update lines 1BOOK_EDITOR_BODY_PADDING-1BOOK_EDITOR_SUBTITLE_PADDING
//Also, make sure this vvvvvvvv filler parameter gets updated, wasn't sure what we were using
void editBook(vector<bookType*> bookInfo, int &bookCount, const int DBSIZE)
{
  int i = lookUpBook(bookInfo);
  int choice;
  string tmpTitle;
  string tmpIsbn;
  string tmpAuthor;
  string tmpPublisher;
  string tmpDateAdded;
  int tmpQtyOnHand;
  double tmpWholesale;
  double tmpRetail;
  vector<bookType> derefed = bookInfoDeref(bookInfo); // Dereference the bookInfo vector to get a vector of bookType objects

  if (bookCount == 0)
  {
    cout << "Book database is empty! Cannot edit" << DBSIZE << " books.\n";
    return;
  }
  
  while(choice != 9)
  {
	 if (i == -1)
    {
		cout << "Book not found. Returning to Inventory Menu.\n";
		cout << "Press ENTER to continue...";
		cin.ignore();
		return;  
    }
    cout << "\033[2J\033[1;1H";
    cout << endl << endl;
    //cout << setfill("█") << setw(80) << "#" << endl;
    cout << left;
    cout << "████████████████████████████████████████████████████████████████████████████████";
    cout << right << endl;
    cout << "█" << setw(BOOK_EDITOR_TITLE_PADDING) << "SERENDIPITY  BOOKSELLERS" << setw(BOOK_EDITOR_TITLE_WIDTH) << " " << "█" << endl;
    cout << "█" << setw(BOOK_EDITOR_SUBTITLE_PADDING) << "EDIT BOOK"         << setw(BOOK_EDITOR_SUBTITLE_WIDTH) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(BOOK_EDITOR_SUBTITLE_PADDING) << "DATABASE SIZE:"       << setw(DB_SIZE_PADDING)  << "  20"
          << setw(BOOK_COUNT_PADDING) << "CURRENT BOOK COUNT:"    << setw(DB_SIZE_PADDING)  << bookCount
          << setw(DB_SIZE_PADDING + 1)  << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(PENDING_VALUES_PADDING) << "--PENDING VALUES"     << setw(PENDING_VALUES_WIDTH)  << " " << "█" << endl;

    cout << left;

    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)               << "<1> Update Book Title"        << ">  --"
          << setw(BOOK_EDITOR_BODY_WIDTH)     << derefed[i].getBookTitle()     << "█" << endl;
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)               << "<2> Update ISBN"          << ">  --"
          << setw(BOOK_EDITOR_BODY_WIDTH)     << derefed[i].getIsbn()          << "█" << endl;
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)               << "<3> Update Author"          << ">  --"
          << setw(BOOK_EDITOR_BODY_WIDTH)     << derefed[i].getAuthor()        << "█" << endl;
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)               << "<4> Update Publisher"         << ">  --"
          << setw(BOOK_EDITOR_BODY_WIDTH)     << derefed[i].getPublisher()     << "█" << endl;
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)               << "<5> Date Last Updated <mm/dd/yyyy>" << ">  --"
          << setw(BOOK_EDITOR_BODY_WIDTH)     << derefed[i].getDateAdded()     << "█" << endl;
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)               << "<6> Update Quantity on Hand"    << ">  --"
          << setw(BOOK_EDITOR_BODY_WIDTH)     << derefed[i].getQtyOnHand()     << "█" << endl;
    cout << fixed << setprecision(2);
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)               << "<7> Update Wholesale Cost"      << ">  --$"
          << setw(BOOK_EDITOR_BODY_WIDTH - 1)     << derefed[i].getWholesale() << "█" << endl;
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)               << "<8> Update Retail Price"      << ">  --$"
            << setw(BOOK_EDITOR_BODY_WIDTH - 1)     << derefed[i].getRetail()  << "█" << endl;

    cout.unsetf(ios::fixed);
    cout << setprecision(6);
    cout << "█" << setw(1)  << " " << setw(36) << "<9> Return to Inventory Menu" << setw(41) << " " << "█" << endl;

    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;

    cout << "████████████████████████████████████████████████████████████████████████████████";
    cout << endl;

    choice = intInputChecked("    Choice<0-9>", 0, 9);


    switch(choice)
    {

      case 1:
        cout << "Enter Book Title: ";
        getline(cin, tmpTitle);
        derefed[i].setBookTitle(tmpTitle);
        cout << "\033[2J\033[1;1H";
        break;
      case 2:
        cout << "Enter ISBN: ";
        getline(cin, tmpIsbn);
       derefed[i].setIsbn(tmpIsbn);
        cout << "\033[2J\033[1;1H";
        break;
      case 3:
        cout << "Enter Author: ";
        getline(cin, tmpAuthor);
        derefed[i].setAuthor(tmpAuthor);
        cout << "\033[2J\033[1;1H";
        break;
      case 4:
        cout << "Enter Publisher: ";
        getline(cin, tmpPublisher);
        derefed[i].setPublisher(tmpPublisher);
        cout << "\033[2J\033[1;1H";
        break;
      case 5:
        cout << "Enter Date Added: ";
        getline(cin, tmpDateAdded);
        derefed[i].setDateAdded(tmpDateAdded);
        cout << "\033[2J\033[1;1H";
        break;
      case 6:
        cout << "Enter Quantity on Hand: ";
        cin >> tmpQtyOnHand;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        derefed[i].setQtyOnHand(tmpQtyOnHand);
        cout << "\033[2J\033[1;1H";
        break;
      case 7:
        cout << "Enter Wholesale Cost: ";
        cin  >> tmpWholesale;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        derefed[i].setWholesale(tmpWholesale);
        cout << "\033[2J\033[1;1H";
        break;
      case 8:
        cout << "Enter Retail Price: ";
        cin  >> tmpRetail;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        derefed[i].setRetail(tmpRetail);
        cout << "\033[2J\033[1;1H";
        break;
      case 9:
        cout << "\033[2J\033[1;1H";
        break;
      default:
        cout << "Please enter a number from the range of 1-9" << endl;

    }
    cout << "\033[2J\033[1;1H";
  }

  return;
}
