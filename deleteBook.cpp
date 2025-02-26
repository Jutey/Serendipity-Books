#include <iostream>
#include <vector>
#include "deleteBook.h"
#include "lookUpBook.h"

using namespace std;

void deleteBook(vector<bookType> &bookInfo, int &bookCount) {

	 int index = lookUpBook(bookInfo);  

    if (bookCount == 0) {
        cout << "Book database is empty! Cannot delete a book.\n";
        return;
    }


    if (index == -1) {
        cout << "No book selected for deletion.\n";
        return;
    }

    bookInfo.at(index) = bookInfo.at(bookCount - 1);
    bookCount--;

    cout << "\033[2J\033[1;1H";

    cout << "Book deleted successfully.\n";
    cout << "Press ENTER to return to Inventory Menu...";
    cin.ignore();

    return;
}
