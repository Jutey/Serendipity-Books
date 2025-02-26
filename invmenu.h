#ifndef INVMENU_H
#define INVMENU_H

#include "bookType.h"
#include "addBook.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>

using namespace std;

void invmenu(vector<bookType> &bookInfo, int &bookCount, const int DBSIZE);

#endif
