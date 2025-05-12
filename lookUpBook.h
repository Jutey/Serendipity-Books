/************************************************
* Assignment: G4
* Purpose: Serendipity Structs
* Author: Kenny Strawn
* Due Date: 2/19/2025
************************************************/

#ifndef __LOOK_UP_BOOK_H__
#define __LOOK_UP_BOOK_H__

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
#include "bookType.h"
#include "orderedLinkedList.h"
#include "linkedlist.h"

using namespace std;

/// A function used to clear any hindrances from the system
///
/// A function called within lookUpBook to clear any tasks or information not being used by the system from the terminal
///@returns nothing meaningful for the moment
void cls();

/// A function to find a title in the database and give the user a multitude of choices
///
/// This function returns all matching search results based on the search query entered
///@param db: vector<bookType> - the database itself passed into the function to be replicated and searched
///@returns nothing meaningful for the moment
int lookUpBook(orderedLinkedList<bookType> db);

#endif
