/******************************************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Authors: Kenny Strawn, Romewin Villacorte, William Donnell-Crume, Cade Coxon
* Due Date: 5/21/2025
*******************************************************************************/
#ifndef DELETE_BOOK_H
#define DELETE_BOOK_H

#include <vector>
#include "bookType.h"
#include "orderedLinkedList.h"
#include "linkedlist.h"

/// A function allowing the removal of books from the database
///
/// Allows the user to look up a book in order to delete it. This will make more space in the database
///@see lookUpBook.h bookType.h
///@param bookInfo: vector<bookType> - a vector which serves as the database for all book information
///@param bookCount: int - a running count of the books in the database to inform the user
///@returns nothing meaningful for the moment
void deleteBook(orderedLinkedList<bookType*>& bookInfo, int &bookCount);

#endif
