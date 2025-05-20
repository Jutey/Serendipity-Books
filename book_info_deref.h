/******************************************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Authors: Kenny Strawn, Romewin Villacorte, William Donnell-Crume, Cade Coxon
* Due Date: 5/21/2025
*******************************************************************************/

#ifndef BOOK_INFO_DEREF_H
#define BOOK_INFO_DEREF_H

#include "orderedLinkedList.h" // for orderedLinkedList class
#include "linkedlist.h" // for linkedListIterator class
#include "bookType.h" // for bookType class
using namespace std;

orderedLinkedList<bookType> bookInfoDeref(orderedLinkedList<bookType*> &bookInfo);

#endif // BOOK_INFO_DEREF_H