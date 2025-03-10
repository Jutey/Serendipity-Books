#ifndef CASHIER_H
#define CASHIER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "bookType.h"
using namespace std;

/// A function to give a summary and receipt to the customer
///
/// Takes input from the user on what books they are purchasing and gives them a receipt of their purchase. Soon to rely on the database of class bookType
///@see bookType.h
///@returns nothing meaningful for the moment
void cashier(vector<bookType>& bookInfo);

#endif
