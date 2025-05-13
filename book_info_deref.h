#ifndef BOOK_INFO_DEREF_H
#define BOOK_INFO_DEREF_H

#include "orderedLinkedList.h" // for orderedLinkedList class
#include "linkedlist.h" // for linkedListIterator class
#include "bookType.h" // for bookType class
using namespace std;

orderedLinkedList<bookType> bookInfoDeref(orderedLinkedList<bookType> &bookInfo);

#endif // BOOK_INFO_DEREF_H