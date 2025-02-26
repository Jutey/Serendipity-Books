#include "bookType.h"
#include <regex>

#ifndef EDITBOOK_H
#define EDITBOOK_H

//same thing here, this vvvvvvv is a filler parameter for the actual array/vector so replace it if need be
void editBook(vector<bookType> &bookInfo, int &bookCount, const int DBSIZE);
void editBook(string title, int &bookCount, vector<bookType> &bookInfo, const int DBSIZE);

#endif
