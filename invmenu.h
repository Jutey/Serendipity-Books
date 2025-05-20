#ifndef INVMENU_H
#define INVMENU_H

#include "bookType.h"
#include "addBook.h"
#include "orderedLinkedList.h"
#include "linkedlist.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>

using namespace std;

/// A function which creates an interactive menu to maintain the database
///
/// Allows the user to directly access and edit all books which are members of the database of bookType class objects
///@see bookType.h addBook.h editBook.h lookUpBook.h
///@param bookInfo: orderedLinkedList<bookType*> - a linked list containing all bookType objects in the database
///@param bookCount: int - a reference integer keeping count of the books in the database to warn the user
///@returns nothing meaningful for the moment
void invmenu(orderedLinkedList<bookType*> &bookInfo, int &bookCount);

#endif
