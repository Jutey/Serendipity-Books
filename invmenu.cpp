/******************************************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Authors: Kenny Strawn, Romewin Villacorte, William Donnell-Crume, Cade Coxon
* Due Date: 5/21/2025
*******************************************************************************/
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

void invmenu(orderedLinkedList<bookType*> &bookInfo, int &bookCount)
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

  cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "2. Add a Book" << "█" << endl;
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
    cout << " ";
    addBook(bookInfo, bookCount);
    break;
    case 3:
    editBook(bookInfo, bookCount);
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
