#include <iostream>
#include <vector>
#include "deleteBook.h"
#include "lookUpBook.h"

using namespace std;

void deleteBook(vector<bookType> &bookInfo, int &bookCount) {
	 int count = 0;

	 int index = lookUpBook(bookInfo);  

    if (bookCount == 0) {
        cout << "Book database is empty. No books to delete\n";
        return;
    }

   do{
    bookInfo.at(index) = bookInfo.at(bookCount - 1);
    bookCount--;

    cout << "\033[2J\033[1;1H";

    cout << "Book deleted!\n";
    cout << "Press ENTER to return to Inventory Menu...";
    cin.ignore();
	 count++;
}while(count < 1);




    return;
}
