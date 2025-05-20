/******************************************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Authors: Kenny Strawn, Romewin Villacorte, William Donnell-Crume, Cade Coxon
* Due Date: 5/21/2025
*******************************************************************************/
#include <iostream>
#include <vector>
#include "deleteBook.h"
#include "lookUpBook.h"

using namespace std;

void deleteBook(orderedLinkedList<bookType*>& bookInfo, int &bookCount)
{
  int count = 0;

  int index = lookUpBook(bookInfo);  

  if (bookCount == 0)
  {
    cout << "Book database is empty. No books to delete\n";
    return;
  }

  do
  {
    if(index == -1)
    {
      cout << "Book not found. No books deleted.\n";
      cout << "Press ENTER to return to Inventory Menu...";
      cin.ignore();
        return;
    }


    // Advance iterator to the index-th position
    linkedListIterator<bookType*> it = bookInfo.begin();
    for (int i = 0; i < index && it != bookInfo.end(); ++i) {
        ++it;
    }
    if (it != bookInfo.end()) {
        bookInfo.deleteNode(*it);
    }

    // Temporary workaround until we can figure out how to completely drop the bookCount parameter thanks to having numRecs to replace it
    bookCount = bookType::getNumRecs();
    
    // We decrement in the destructor, so no need to decrement again

    cout << "\033[2J\033[1;1H";

    cout << "Book deleted!\n";
    cout << "Press ENTER to return to Inventory Menu...";
    cin.ignore();
    count++;
	
  } while(count < 1);

  return;
}
