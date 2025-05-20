/******************************************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Authors: Kenny Strawn, Romewin Villacorte, William Donnell-Crume, Cade Coxon
* Due Date: 5/21/2025
*******************************************************************************/

#include "orderedLinkedList.h"
#include "linkedlist.h"

#ifndef ADDBOOK_H
#define ADDBOOK_H

/// This function allows for updating the database with new books
///
/// This is a void function which functions off of user-provided information to form a database of books.
///@param bookInfo: orderedLinkedList<bookType*> - a linked list of bookType pointers which store the necessary info for the books
///@param bookCount: int - a running total of the books in the database
///@returns nothing because its job is to update the database, not to send anything back
void addBook(orderedLinkedList<bookType*> &bookInfo, int &bookCount);

#endif
