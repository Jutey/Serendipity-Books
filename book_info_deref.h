#ifndef BOOK_INFO_DEREF_H
#define BOOK_INFO_DEREF_H

#include <vector>
#include "bookType.h" // for bookType class
using namespace std;

vector<bookType> bookInfoDeref(vector<bookType*> &bookInfo);

#endif // BOOK_INFO_DEREF_H