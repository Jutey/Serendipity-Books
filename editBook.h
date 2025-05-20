/******************************************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Authors: Kenny Strawn, Romewin Villacorte, William Donnell-Crume, Cade Coxon
* Due Date: 5/21/2025
*******************************************************************************/

#include "bookType.h"
#include <regex>
#include "linkedlist.h"
#include "orderedLinkedList.h"

#ifndef EDITBOOK_H
#define EDITBOOK_H

/// A function to allow database edits and maintenance
///
/// This function displays a book record after the user looks up a book, then allows them to edit its information
///@see lookUpBook.h
///@param bookInfo: orderedLinkedList<bookType*> - a linked list containing the book's record info
///@see bookType.h
///@param bookCount: int - a user feedback integer that keeps track of the amount of books in the database
///@returns nothing meaningful at the moment
void editBook(orderedLinkedList<bookType*> bookInfo, int &bookCount);

#endif
