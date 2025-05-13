#include "bookType.h"
#include <regex>
#include "linkedlist.h"
#include "orderedLinkedList.h"

#ifndef EDITBOOK_H
#define EDITBOOK_H

/// A function to allow database edits and maintenance
///
/// This function displays a book record after the user looks up a book, then allows them to edit it's information
///@see lookUpBook.h
///@param bookInfo: vector<bookType> - a vector full of the book's record info
///@see bookType.h
///@param bookCount: int - a user feedback integer that keeps track of the amount of books in the database
///@param DBSIZE: const int - an integer that limits the size of the Database
///@returns nothing meaningful at the moment
void editBook(orderedLinkedList<bookType> bookInfo, int &bookCount, const int DBSIZE);

/// A function to allow database edits and maintenance
///
/// This function accepts a string to edit a book directly from the lookUpBook function
///@see lookUpBook.h
///@param title: string - a string that allows the direct editing of a title from lookUpBook
///@param bookCount: int - a user feedback integer that keeps track of the amount of books in the database
///@param bookInfo: vector<bookType> - a vector full of the book's record info
///@see bookType.h
///@param DBSIZE: const int - an integer that limits the size of the Database
///@returns nothing meaningful at the moment
void editBook(string title, int &bookCount, orderedLinkedList<bookType> bookInfo, const int DBSIZE);

#endif
