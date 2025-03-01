#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "bookType.h" //struct header here
#include "addBook.h"
#include "int_input_checked.h"
#include "setw_consts.h"

using namespace std;


//bookCount is a variable that should be addressed and initialized within main
//Default array/vector name is bookInfo if that's easiest, otherwise update lines 1BOOK_EDITOR_BODY_PADDING-1BOOK_EDITOR_SUBTITLE_PADDING
//Also, make sure this vvvvvvvv filler parameter gets updated, wasn't sure what we were using
void addBook(vector<bookType> &bookInfo, int &bookCount, const int DBSIZE)
{
  bookType tempBook;
  int choice;

  if (bookCount >= DBSIZE)
  {
    cout << "Book database is full! Cannot add more than " << DBSIZE << " books.\n";
    return;
  }

  //initialize all filler variables
  tempBook = bookType();

  while(choice != 0 && bookCount < 20)
  {
    cout << "\033[2J\033[1;1H";
    cout << endl << endl;
    //cout << setfill("█") << setw(80) << "#" << endl;
    cout << left;
    cout << "████████████████████████████████████████████████████████████████████████████████";
    cout << right << endl;
    cout << "█" << setw(BOOK_EDITOR_TITLE_PADDING) << "SERENDIPITY  BOOKSELLERS" << setw(BOOK_EDITOR_TITLE_WIDTH) << " " << "█" << endl;
    cout << "█" << setw(BOOK_EDITOR_SUBTITLE_PADDING) << "ADD BOOK"         << setw(BOOK_EDITOR_SUBTITLE_WIDTH) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(BOOK_EDITOR_SUBTITLE_PADDING) << "DATABASE SIZE:"       << setw(DB_SIZE_PADDING)  << "  20"
          << setw(BOOK_COUNT_PADDING) << "CURRENT BOOK COUNT:"    << setw(DB_SIZE_PADDING)  << bookCount
          << setw(DB_SIZE_PADDING + 1)  << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(PENDING_VALUES_PADDING) << "--PENDING VALUES"     << setw(PENDING_VALUES_WIDTH)  << " " << "█" << endl;

    cout << left;

    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)             << "<1> Update Book Title"        << ">  --"
          << setw(BOOK_EDITOR_BODY_WIDTH)         << tempBook.getBookTitle()  << "█" << endl;
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)             << "<2> Update ISBN"          << ">  --"
          << setw(BOOK_EDITOR_BODY_WIDTH)         << tempBook.getIsbn()       << "█" << endl;
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)             << "<3> Update Author"          << ">  --"
          << setw(BOOK_EDITOR_BODY_WIDTH)         << tempBook.getAuthor()     << "█" << endl;
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)             << "<4> Update Publisher"         << ">  --"
          << setw(BOOK_EDITOR_BODY_WIDTH)         << tempBook.getPublisher()  << "█" << endl;
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)             << "<5> Date Last Updated <mm/dd/yyyy>" << ">  --"
          << setw(BOOK_EDITOR_BODY_WIDTH)         << tempBook.getDateAdded()  << "█" << endl;
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)             << "<6> Update Quantity on Hand"    << ">  --"
          << setw(BOOK_EDITOR_BODY_WIDTH)         << tempBook.getQtyOnHand()  << "█" << endl;
    cout << fixed << setprecision(2);
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)             << "<7> Update Wholesale Cost"      << ">  --$"
          << setw(BOOK_EDITOR_BODY_WIDTH - 1)     << tempBook.getWholesale()  << "█" << endl;
    cout << "█"   << " "        << setw(BOOK_EDITOR_BODY_PADDING)             << "<8> Update Retail Price"      << ">  --$"
            << setw(BOOK_EDITOR_BODY_WIDTH - 1)   << tempBook.getRetail()     << "█" << endl;

    cout.unsetf(ios::fixed);
    cout << setprecision(6);
    cout << "█" << setw(1)  << " " << setw(36) << "<9> Save Book To Database"  << setw(41) << " " << "█" << endl;
    cout << "█" << setw(1)  << " " << setw(36) << "<0> Return to Inventory Menu" << setw(41) << " " << "█" << endl;

    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;

    cout << "████████████████████████████████████████████████████████████████████████████████";
    cout << endl;

    choice = intInputChecked("    Choice<0-9>", 0, 9);

//    cout << "    Choice<0-9>";
//    cin >> choice;
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    if (cin.fail())
//    {
//      cin.clear();
//      cout << "Invalid entry. Please enter a number." << endl;

//      cout << "    Choice<0-9>";
//      cin >> choice;
//      cin.ignore(numeric_limits<streamsize>::max(), '\n');
//    }

    // Temporary variables to pass to setter methods
    string tmpTitle;
    string tmpIsbn;
    string tmpAuthor;
    string tmpPublisher;
    string tmpDateAdded;
    int tmpQtyOnHand;
    double tmpWholesale;
    double tmpRetail;

    switch(choice)
    {

      case 1:
        cout << "Enter Book Title: ";
        getline(cin, tmpTitle);
        tempBook.setBookTitle(tmpTitle);
        cout << "\033[2J\033[1;1H";
        break;
      case 2:
        cout << "Enter ISBN: ";
        getline(cin, tmpIsbn);
        tempBook.setIsbn(tmpIsbn);
        cout << "\033[2J\033[1;1H";
        break;
      case 3:
        cout << "Enter Author: ";
        getline(cin, tmpAuthor);
        tempBook.setAuthor(tmpAuthor);
        cout << "\033[2J\033[1;1H";
        break;
      case 4:
        cout << "Enter Publisher: ";
        getline(cin, tmpPublisher);
        tempBook.setPublisher(tmpPublisher);
        cout << "\033[2J\033[1;1H";
        break;
      case 5:
        cout << "Enter Date Added: ";
        getline(cin, tmpDateAdded);
        tempBook.setDateAdded(tmpDateAdded);
        cout << "\033[2J\033[1;1H";
        break;
      case 6:
        cout << "Enter Quantity on Hand: ";
        cin >> tmpQtyOnHand;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        tempBook.setQtyOnHand(tmpQtyOnHand);
        cout << "\033[2J\033[1;1H";
        break;
      case 7:
        cout << "Enter Wholesale Cost: ";
        cin  >> tmpWholesale;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        tempBook.setWholesale(tmpWholesale);
        cout << "\033[2J\033[1;1H";
        break;
      case 8:
        cout << "Enter Retail Price: ";
        cin  >> tmpRetail;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        tempBook.setRetail(tmpRetail);
        cout << "\033[2J\033[1;1H";
        break;
      case 9:
        //pass all filler information into the struct array/vector
        //adding all the book info into the vector
        bookInfo.push_back(tempBook);
        //update bookCount
        bookCount++;
        //re-initialize all filler variables
        tempBook = bookType();
        //clear screen
        cout << "\033[2J\033[1;1H";
        break;
      default:
        break;
    }
    cout << "\033[2J\033[1;1H";
  }

  return;
}
