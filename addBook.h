#include "bookType.h"
#include "orderedLinkedList.h"
#include "linkedlist.h"

#ifndef ADDBOOK_H
#define ADDBOOK_H

/// This function allows for updating the database with new books
///
/// This is a void function which functions off of user-provided information to form a database of books.
///@param bookInfo: vector<bookType> - a vector of bookType classes which store the necessary info for the books
///@see bookType.h
///@param bookCount: int - a running total of the books in the database that makes sure the limit is not exceeded
///@param DBSIZE: constant int - a constant which controls the maximum limit for the database size
///@returns nothing meaningful for the moment
void addBook(orderedLinkedList<bookType*> bookInfo, int &bookCount, const int DBSIZE);

#endif
