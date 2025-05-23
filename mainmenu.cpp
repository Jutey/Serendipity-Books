/******************************************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Authors: Kenny Strawn, Romewin Villacorte, William Donnell-Crume, Cade Coxon
* Due Date: 5/21/2025
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>

#include "invmenu.h"
#include "cashier.h"
#include "reports.h"
#include "bookType.h"
#include "int_input_checked.h"
#include "setw_consts.h"
#include "book_info_deref.h" // for bookInfoDeref

using namespace std;

int main()
{

  int choice;
  orderedLinkedList<bookType*> bookInfo;
  int bookCount = 0;

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
    cout << "█" << setw(BOOK_INFO_SUBTITLE_PADDING) << " " << setw(BOOK_INFO_SUBTITLE_WIDTH) << "Main Menu" << "█" << endl;

    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;

	if(bookCount > 0)
   {
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "1. Cashier Module" << "█" << endl;
	}
	else
	{
	  cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "1. Cashier Module (DISABLED)" << "█" << endl;
 	}

    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "2. Inventory Database Module" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "3. Report Module" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_EXIT_PADDING) << "\033[31m4. Exit\033[0m " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;


    cout << "████████████████████████████████████████████████████████████████████████████████";
    cout << endl << endl << endl;

    choice = intInputChecked("Enter Your Choice", 1, 4);
    
    vector<bookType> derefBookInfo; // Declare outside the switch to avoid bypassing initialization

    switch(choice)
    {
      case 1:
    if (bookCount > 0){
        cashier(bookInfo);
        cout << "\033[2J\033[1;1H";
        break;
    }
    else{
      cout << "please add books to inventory prior to entering cashier";
      break;
      }
      case 2:
        invmenu(bookInfo, bookCount);
        cout << "\033[2J\033[1;1H";
        break;
      case 3:
        reports(bookInfo); // pass the dereferenced vector to reports
        cout << "\033[2J\033[1;1H";
        break;
      case 4:
        break;
      default:
        cout << "Error: number out of the 1-4 range" << endl;
        cout << "Press Enter to try again with a valid choice...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\033[2J\033[1;1H";
    }

  cout << "\033[2J\033[1;1H";
  } while(choice != 4);

  // Memory cleanup: Delete all dynamically allocated bookType objects
  while (!bookInfo.isEmptyList()) {
      bookType* book = bookInfo.front(); // Get the first book pointer
      bookInfo.deleteNode(book);        // Remove the node from the list
      delete book;                      // Delete the dynamically allocated book
  }

  bookInfo.destroyList(); // Clean up the linked list structure
  cout << "Goodbye!" << endl;
  cout << "Press Enter to exit...";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "\033[2J\033[1;1H";
  return 0;
}
