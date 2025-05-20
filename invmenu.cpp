/************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Author: Kenny Strawn
* Due Date: 5/21/2025
************************************************/
#include <vector>
#include "invmenu.h"
#include "addBook.h"
#include "bookType.h"
#include "lookUpBook.h"
#include "int_input_checked.h"
#include "editBook.h"
#include "deleteBook.h"
#include "setw_consts.h"
#include "book_info_deref.h"

using namespace std;

void invmenu(orderedLinkedList<bookType> &bookInfo, int &bookCount, const int DBSIZE)
{
  
  int userChoice;
  userChoice = 0;
  cout << "\033[2J\033[1;1H";
  do
  {
    cout << left;

    cout << "████████████████████████████████████████████████████████████████████████████████" << endl;

    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(MENU_HEAD_PADDING - 6) << " " << setw(MENU_HEAD_WIDTH + 6) << "Serendipity Book Sellers" << "█" << endl;
    cout << "█" << setw(MENU_SUBHEAD_PADDING) << " " << setw(MENU_SUBHEAD_WIDTH) << "Inventory Database" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "1. Look Up a Book" << "█" << endl;

    if (bookCount < DBSIZE)
    {
      cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "2. Add a Book" << "█" << endl;
    }
    else
    {
      cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(BOOK_ADD_DISABLED_PADDING) << "2. Add a Book\033[38;5;244m(DISABLED)\033[0m" << "█" << endl;
      cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    }
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "3. Edit a Book\'s Record" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "4. Delete a Book" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_EXIT_PADDING) << "\033[32m5. Return to Main Menu\033[0m " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "████████████████████████████████████████████████████████████████████████████████" << endl << endl;

    if (bookInfo.isEmptyList())
    {
      new (&bookInfo) orderedLinkedList<bookType>();
    }

    // error checking
    userChoice = intInputChecked("Enter Your Choice", 1, 5);

    // Menu navigation
    switch(userChoice)
    {
      case 1:
        cout << "█" << setw(MENU_BODY_PADDING) << " " << "You selected item 1." << setw(35) << "█" << endl;
        lookUpBook(bookInfo);
        break;
      case 2:
        if (bookCount < DBSIZE)
        {
          cout << " ";
          addBook(bookInfo, bookCount, DBSIZE);
        }
        else
        {
            cout << "Cannot add more books. Inventory is full!\n";
            if (bookInfo.isEmptyList())
            {
              cout << "█" << setw(MENU_BODY_PADDING) << " " << "The database is empty. Please add a book." << setw(15) << "█" << endl;
            }
            else
            {`
              cout << "█" << setw(MENU_BODY_PADDING) << " " << "The database is full. Please delete a book." << setw(15) << "█" << endl;
            }
        }

        break;
      case 3:
        editBook(bookInfo, bookCount, DBSIZE);
        break;
      case 4:
        deleteBook(bookInfo, bookCount);
        break;
      case 5:
        break;

      default:
        cout << "█" << setw(79) << "█" << endl;
        cout << "█" << setw(MENU_BODY_PADDING) << " " << "Please enter a number in the range 1 - 5" << setw(15) << "█" << endl;
        continue;
    }

    cout << "\033[2J\033[1;1H";

  } while(userChoice != 5);
}
