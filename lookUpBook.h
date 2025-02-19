/************************************************
* Assignment: G4
* Purpose: Serendipity Structs
* Author: Kenny Strawn
* Due Date: 2/19/2025
************************************************/

#ifndef __LOOK_UP_BOOK_H__
#define __LOOK_UP_BOOK_H__

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "bookType.h"

using namespace std;

vector<string> lookUpBook(vector<bookType> db, string query, const int DBSIZE);

#endif
