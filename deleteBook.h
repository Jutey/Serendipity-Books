#ifndef DELETE_BOOK_H
#define DELETE_BOOK_H

#include <vector>
#include "bookType.h"

/// A function allowing the removal of books from the database
///
/// Allows the user to look up a book in order to delete it. This will make more space in the database
///@see lookUpBook.h bookType.h
///@param bookInfo: vector<bookType> - a vector which serves as the database for all book information
///@param bookCount: int - a running count of the books in the database to inform the user
///@returns nothing meaningful for the moment
void deleteBook(std::vector<bookType> &bookInfo, int &bookCount);

#endif
