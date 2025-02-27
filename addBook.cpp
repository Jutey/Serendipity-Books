#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "bookType.h" //struct header here
#include "addBook.h"
#include "int_input_checked.h"

using namespace std;


//bookCount is a variable that should be addressed and initialized within main
//Default array/vector name is bookInfo if that's easiest, otherwise update lines 138-145
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

  do
  {
    cout << "\033[2J\033[1;1H";
    cout << endl << endl;
    //cout << setfill("█") << setw(80) << "#" << endl;
    cout << left;
    cout << "████████████████████████████████████████████████████████████████████████████████";
    cout << right << endl;
    cout << "█" << setw(53) << "SERENDIPITY  BOOKSELLERS" << setw(25) << " " << "█" << endl;
    cout << "█" << setw(45) << "ADD BOOK"         << setw(33) << " " << "█" << endl;
    cout << "█" << setw(78) << " " << "█" << endl;
    cout << "█" << setw(45) << "DATABASE SIZE:"       << setw(4)  << "  20"
         << setw(20) << "CURRENT BOOK COUNT:"    << setw(4)  << bookCount
         << setw(5)  << " " << "█" << endl;
    cout << "█" << setw(78) << " " << "█" << endl;
    cout << "█" << setw(70) << "--PENDING VALUES"     << setw(8)  << " " << "█" << endl;

    cout << left;

    cout << "█" << setw(1)  << " " << setw(34) << "<1> Enter Book Title"        << ">  --"
          << setw(38) <<tempBook.getBookTitle() << "█" << endl;
    cout << "█" << setw(1)  << " " << setw(34) << "<2> Enter ISBN"          << ">  --"
          << setw(38) << tempBook.getIsbn()    << "█" << endl;
    cout << "█" << setw(1)  << " " << setw(34) << "<3> Enter Author"          << ">  --"
          << setw(38) << tempBook.getAuthor()  << "█" << endl;
    cout << "█" << setw(1)  << " " << setw(34) << "<4> Enter Publisher"         << ">  --"
          << setw(38) << tempBook.getPublisher() << "█" << endl;
    cout << "█" << setw(1)  << " " << setw(34) << "<5> Enter Date Added <mm/dd/yyyy>" << ">  --"
          << setw(38) << tempBook.getDateAdded() << "█" << endl;
    cout << "█" << setw(1)  << " " << setw(34) << "<6> Enter Quantity on Hand"    << ">  --"
          << setw(38) << tempBook.getQtyOnHand() << "█" << endl;
    cout << fixed << setprecision(2);
    cout << "█"   << setw(1)  << " " << setw(34) << "<7> Enter Wholesale Cost"      << ">  --$"
          << setw(37) << tempBook.getWholesale() << "█" << endl;
    cout << "█"   << setw(1)  << " " << setw(34) << "<8> Enter Retail Price"      << ">  --$"
          << setw(37) << tempBook.getRetail()  << "█" << endl;
    cout.unsetf(ios::fixed);
    cout << setprecision(6);
    cout << "█" << setw(1)  << " " << setw(36) << "<9> Save Book To Database"  << setw(41) << " " << "█" << endl;
    cout << "█" << setw(1)  << " " << setw(36) << "<0> Return to Inventory Menu" << setw(41) << " " << "█" << endl;

    cout << "█" << setw(78) << " " << "█" << endl;

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
        cout << "\033[2J\033[1;1H";
        break;
    }

    cout << "\033[2J\033[1;1H";

  } while(choice != 0 && bookCount < 20);

  return;
}
