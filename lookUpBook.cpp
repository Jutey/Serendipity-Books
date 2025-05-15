/************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Author: Kenny Strawn
* Due Date: 5/21/2025
************************************************/

#include "lookUpBook.h"
#include "book_info_deref.h" // for bookInfoDeref
#include "linkedlist.h" // for linkedListIterator class
#include "orderedLinkedList.h" // for orderedLinkedList class

using namespace std;

void cls()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

int lookUpBook(orderedLinkedList<bookType> db)
{
  string query;
  char foundResponse;
  char retryResponse;
  int out = -1;
  bool found = false;

  do
  {
    cls();

    cout << "Search: ";
    getline(cin, query);

    // Convert query to lowercase for case-insensitive search
    transform(query.begin(), query.end(), query.begin(), ::tolower);

    int counter = 0;
    found = false;

    for (linkedListIterator<bookType> it = db.begin(); it != db.end(); ++it, ++counter)
    {
      const bookType& book = *it;
      string title = book.getBookTitle();
      string lowerTitle = title;
      transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);

      if (lowerTitle.find(query) != string::npos)
      {
        cout << "Found title: " << title << endl;
        cout << "Is this the book you're looking for? (y/n) ";
        cin.get(foundResponse);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        foundResponse = tolower(foundResponse);

        if (foundResponse == 'y')
        {
          book.print();
          cout << endl;
          out = counter;
          found = true;
          cout << "Press Enter to continue ..." << endl;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          break;
        }
        else if (foundResponse != 'n')
        {
          cout << "Error: invalid response. Please enter either y or n." << endl;
          continue;
        }
      }
    }

    if (!found)
    {
      cout << "Book not found. Would you like to search for another book? (y/n) ";
      cin.get(retryResponse);
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      if (tolower(retryResponse) != 'y')
        return -1;
    }
  }
  while (out == -1);

  return out;
}
