#ifndef REPORTS_H
#define REPORTS_H

#include <iostream>
#include <iomanip>
#include <string>
#include "bookType.h"
#include <vector>

using namespace std;

/// An organizational function for the database
///
/// A function which lists the books in the database in different orders. Soon to rely on the database of type bookType
///@see bookType.h
///@returns nothing meaningful for the moment
void reports(const std::vector<bookType*> bookInfo);
void repListing(const std::vector<bookType*> bookInfo);
#endif
