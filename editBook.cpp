#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "bookType.h" 
#include "int_input_checked.h"
#include "editBook.h"
#include "lookUpBook.h"

using namespace std;


//bookCount is a variable that should be addressed and initialized within main
//Default array/vector name is bookInfo if that's easiest, otherwise update lines 138-145
//Also, make sure this vvvvvvvv filler parameter gets updated, wasn't sure what we were using
void editBook(vector<bookType> &bookInfo, int &bookCount, const int DBSIZE)
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


  if (bookCount == 0)
  {
    cout << "Book database is empty! Cannot edit" << DBSIZE << " books.\n";
    return;
  }
  
  do
  {
    cout << "\033[2J\033[1;1H";
    cout << endl << endl;
    //cout << setfill("█") << setw(80) << "#" << endl;
    cout << left;
    cout << "████████████████████████████████████████████████████████████████████████████████";
    cout << right << endl;
    cout << "█" << setw(53) << "SERENDIPITY  BOOKSELLERS" << setw(25) << " " << "█" << endl;
    cout << "█" << setw(45) << "EDIT BOOK"         << setw(33) << " " << "█" << endl;
    cout << "█" << setw(78) << " " << "█" << endl;
    cout << "█" << setw(45) << "DATABASE SIZE:"       << setw(4)  << "  20"
          << setw(20) << "CURRENT BOOK COUNT:"    << setw(4)  << bookCount
          << setw(5)  << " " << "█" << endl;
    cout << "█" << setw(78) << " " << "█" << endl;
    cout << "█" << setw(70) << "--PENDING VALUES"     << setw(8)  << " " << "█" << endl;

    cout << left;

    cout << "█"   << " "        << setw(34)           << "<1> Update Book Title"        << ">  --"
          << setw(38)     << bookInfo[i].getBookTitle() << "█" << endl;
    cout << "█"   << " "        << setw(34)           << "<2> Update ISBN"          << ">  --"
          << setw(38)     << bookInfo[i].getIsbn()    << "█" << endl;
    cout << "█"   << " "        << setw(34)           << "<3> Update Author"          << ">  --"
          << setw(38)     << bookInfo[i].getAuthor()  << "█" << endl;
    cout << "█"   << " "        << setw(34)           << "<4> Update Publisher"         << ">  --"
          << setw(38)     << bookInfo[i].getPublisher() << "█" << endl;
    cout << "█"   << " "        << setw(34)           << "<5> Date Last Updated <mm/dd/yyyy>" << ">  --"
          << setw(38)     << bookInfo[i].getDateAdded() << "█" << endl;
    cout << "█"   << " "        << setw(34)           << "<6> Update Quantity on Hand"    << ">  --"
          << setw(38)     << bookInfo[i].getQtyOnHand() << "█" << endl;
    cout << fixed << setprecision(2);
    cout << "█"   << " "        << setw(34)           << "<7> Update Wholesale Cost"      << ">  --$"
          << setw(37)     << bookInfo[i].getWholesale() << "█" << endl;
    cout << "█"   << " "        << setw(34)           << "<8> Update Retail Price"      << ">  --$"
            << setw(37)     << bookInfo[i].getRetail()  << "█" << endl;

   cout.unsetf(ios::fixed);
    cout << setprecision(6);
    cout << "█" << setw(1)  << " " << setw(36) << "<9> Return to Inventory Menu" << setw(41) << " " << "█" << endl;

    cout << "█" << setw(78) << " " << "█" << endl;

    cout << "████████████████████████████████████████████████████████████████████████████████";
    cout << endl;

    choice = intInputChecked("    Choice<0-9>", 0, 9);


    switch(choice)
    {

      case 1:
        cout << "Enter Book Title: ";
        getline(cin, tmpTitle);
        bookInfo[i].setBookTitle(tmpTitle);
        cout << "\033[2J\033[1;1H";
        break;
      case 2:
        cout << "Enter ISBN: ";
        getline(cin, tmpIsbn);
       bookInfo[i].setIsbn(tmpIsbn);
        cout << "\033[2J\033[1;1H";
        break;
      case 3:
        cout << "Enter Author: ";
        getline(cin, tmpAuthor);
        bookInfo[i].setAuthor(tmpAuthor);
        cout << "\033[2J\033[1;1H";
        break;
      case 4:
        cout << "Enter Publisher: ";
        getline(cin, tmpPublisher);
        bookInfo[i].setPublisher(tmpPublisher);
        cout << "\033[2J\033[1;1H";
        break;
      case 5:
        cout << "Enter Date Added: ";
        getline(cin, tmpDateAdded);
        bookInfo[i].setDateAdded(tmpDateAdded);
        cout << "\033[2J\033[1;1H";
        break;
      case 6:
        cout << "Enter Quantity on Hand: ";
        cin >> tmpQtyOnHand;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bookInfo[i].setQtyOnHand(tmpQtyOnHand);
        cout << "\033[2J\033[1;1H";
        break;
      case 7:
        cout << "Enter Wholesale Cost: ";
        cin  >> tmpWholesale;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bookInfo[i].setWholesale(tmpWholesale);
        cout << "\033[2J\033[1;1H";
        break;
      case 8:
        cout << "Enter Retail Price: ";
        cin  >> tmpRetail;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bookInfo[i].setRetail(tmpRetail);
        cout << "\033[2J\033[1;1H";
        break;
      case 9:
        cout << "\033[2J\033[1;1H";
        break;
      default:
        cout << "Please enter a number from the range of 1-9" << endl;

    }

    cout << "\033[2J\033[1;1H";

  } while(choice != 9);

  return;
}
