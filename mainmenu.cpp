#include <iostream>
#include <iomanip>
#include <limits>
#include "invmenu.h"
#include "cashier.h"
#include "reports.h"

#include "bookType.h" // DBSIZE
#include "int_input_checked.h"

using namespace std;  

int main() {

    int choice;
    vector<bookType> bookInfo;
    int bookCount = 0;

    do{
        cout << "\033[2J\033[1;1H";
        cout << endl << endl;
        //cout << setfill("█") << setw(80) << "#" << endl;
        cout << left;
        cout << "████████████████████████████████████████████████████████████████████████████████";
        cout << endl;
        cout << "█" << setw(24) << " " << setw(54) << " " << "█" << endl;
        cout << "█" << setw(78) << " " << "█" << endl;
        cout << "█" << setw(28) << " " << setw(50) << "Serendipity Book Sellers" << "█" << endl;
        cout << "█" << setw(35) << " " << setw(43) << "Main Menu" << "█" << endl;

        cout << "█" << setw(78) << " " << "█" << endl;

        cout << "█" << setw(24) << " " << setw(54) << "1. Cashier Module" << "█" << endl;
        cout << "█" << setw(24) << " " << setw(54) << "2. Inventory Database Module" << "█" << endl;
        cout << "█" << setw(24) << " " << setw(54) << "3. Report Module" << "█" << endl;
        cout << "█" << setw(24) << " " << setw(63) << "\033[31m4. Exit\033[0m " << "█" << endl;
        cout << "█" << setw(78) << " " << "█" << endl;
        cout << "█" << setw(78) << " " << "█" << endl;
        cout << "█" << setw(78) << " " << "█" << endl;
        cout << "█" << setw(78) << " " << "█" << endl;


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

  }while(choice != 4);

  return 0;

}