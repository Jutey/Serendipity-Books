#include <iostream>
#include <iomanip>
#include <limits>

#include "invmenu.h"
#include "cashier.h"
#include "reports.h"
#include "bookType.h" // DBSIZE
#include "int_input_checked.h"
#include "setw_consts.h"

using namespace std;  

int main()
{

  int choice;
  vector<bookType> bookInfo;
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

    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "1. Cashier Module" << "█" << endl;
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
    
    switch(choice)
    {
      case 1:
        cashier();
        cout << "\033[2J\033[1;1H";
        break;
      case 2:
        invmenu(bookInfo, bookCount, DBSIZE);
        cout << "\033[2J\033[1;1H";
        break;
      case 3:
        reports();
        cout << "\033[2J\033[1;1H";
        break;
      case 4:
        break;
      default:
        cout << "Please enter a number from the range of 1-4" << endl;
    }

  cout << "\033[2J\033[1;1H";

  } while(choice != 4);

  return 0;

}
