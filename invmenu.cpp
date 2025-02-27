/***********************************************
* Serendipity Project
*
* invmenu.cpp
*
* Purpose: to manage each book stored on this 
*        file
*
  * By: Romewin Villacorte
************************************************/ 
#include <vector>
#include "invmenu.h"
#include "addBook.h"
#include "bookType.h"
#include "lookUpBook.h"
#include "int_input_checked.h"
#include "editBook.h"
#include "deleteBook.h"

using namespace std;

void invmenu(vector<bookType> &bookInfo, int &bookCount, const int DBSIZE)
{
  
  int userChoice;
  userChoice = 0;
  cout << "\033[2J\033[1;1H";
  do
  {
    cout << left;

    cout << "████████████████████████████████████████████████████████████████████████████████" << endl;

    cout << "█" << setw(24) << " " << setw(54) << " " << "█" << endl;
    cout << "█" << setw(78) << " " << "█" << endl;
    cout << "█" << setw(28) << " " << setw(50) << "Serendipity Book Sellers" << "█" << endl;
    cout << "█" << setw(31) << " " << setw(47) << "Inventory Database" << "█" << endl;
    cout << "█" << setw(24) << " " << setw(54) << "1. Look Up a Book" << "█" << endl;

    if (bookCount < DBSIZE)
    {
      cout << "█" << setw(24) << " " << setw(54) << "2. Add a Book" << "█" << endl;
    }
    else
    {
      cout << "█" << setw(24) << " " << setw(54) << "2. Add a Book\033[38;5;244m(DISABLED)\033[0m\n" << "█" << endl;
      cout << "█" << setw(24) << " " << setw(54) << " " << "█" << endl;

    }
    cout << "█" << setw(24) << " " << setw(54) << "3. Edit a Book\'s Record" << "█" << endl;
    cout << "█" << setw(24) << " " << setw(54) << "4. Delete a Book" << "█" << endl;
    cout << "█" << setw(24) << " " << setw(63) << "\033[32m5. Return to Main Menu\033[0m " << "█" << endl;
    cout << "█" << setw(78) << " " << "█" << endl;
    cout << "█" << setw(78) << " " << "█" << endl;
    cout << "█" << setw(78) << " " << "█" << endl;
    cout << "█" << setw(78) << " " << "█" << endl;
    cout << "████████████████████████████████████████████████████████████████████████████████" << endl << endl;

    // error checking
    userChoice = intInputChecked("Enter Your Choice", 1, 5);
    
    // Menu navigation
    switch(userChoice)
    {
      case 1:
        cout << "█" << setw(24) << " " << "You selected item 1." << setw(35) << "█" << endl;
        lookUpBook(bookInfo);
        break;
      case 2:
        addBook(bookInfo, bookCount, DBSIZE);
        if (bookCount < DBSIZE)
        {
            addBook(bookInfo, bookCount, DBSIZE);
        }
        else
        {
            cout << "Cannot add more books. Inventory is full!\n";
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
        cout << "█" << setw(24) << " " << "Please enter a number in the range 1 - 5" << setw(15) << "█" << endl;
        continue;
    }

    cout << "█" << setw(24) << " " << "Press ENTER to continue ..." << setw(28) << "█" << endl;
    cout << "██████████████████████████████████████████████████████████████████████████████";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "\033[2J\033[1;1H";

  } while(userChoice != 5);
}
