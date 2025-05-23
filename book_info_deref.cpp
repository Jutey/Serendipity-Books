/******************************************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Authors: Kenny Strawn, Romewin Villacorte, William Donnell-Crume, Cade Coxon
* Due Date: 5/21/2025
*******************************************************************************/
#include "book_info_deref.h" // for bookInfoDeref

orderedLinkedList<bookType> bookInfoDeref(orderedLinkedList<bookType*> &bookInfo)
{
    orderedLinkedList<bookType> derefBookInfo;
    for (size_t i = 0; i < bookInfo.size(); ++i)
    {
        bookType* ptr = *bookInfo.get(i);
        if (ptr != nullptr) {
            derefBookInfo.insert(*ptr); // Dereference the bookType object and add it to the new list
        }
    }
    return derefBookInfo;
}