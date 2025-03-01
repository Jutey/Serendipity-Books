#include <iostream>
#include <iomanip>
#include <limits>

#include "reports.h"
#include "int_input_checked.h"
#include "setw_consts.h"

using namespace std;

void reports()
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
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(63) << "\033[32m7. Return to Main Menu\033[0m " << "█" << endl;
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
        cout << "You selected item 1." << endl;
        cout << "Press ENTER to continue ...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;

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
