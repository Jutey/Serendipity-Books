/************************************************
* Assignment: G4
* Purpose: Serendipity Structs
* Author: Kenny Strawn
* Due Date: 2/17/2025
************************************************/

#ifndef __INT_INPUT_CHECKED_H__
#define __INT_INPUT_CHECKED_H__

#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Function to stop input failure in its tracks (int version)
// Parameters:
//  * prompt: string - the prompt to display to the user
//  * rangeBegin: int - the beginning of the range of acceptable values
//  * rangeEnd: int - the end of the range of acceptable values
// Returns:
//  * int - the user's input
int intInputChecked(string prompt, int rangeBegin, int rangeEnd);

// Function to stop input failure in its tracks (int version)
// Parameters:
//  * prompt: string - the prompt to display to the user
//  * rangeBegin: int - the beginning of the range of acceptable values
//  * rangeEnd: int - the end of the range of acceptable values
// Returns:
//  * int - the user's input
long long intInputCheckedLong(string prompt, int rangeBegin, int rangeEnd);

// Function to stop input failure in its tracks (float version)
// Parameters:
//  * prompt: string - the prompt to display to the user
//  * rangeBegin: float - the beginning of the range of acceptable values
//  * rangeEnd: float - the end of the range of acceptable values
// Returns:
//  * float - the user's input
float floatInputChecked(string prompt, float rangeBegin, float rangeEnd);


// Function to stop input failure in its tracks (double version)
// Parameters:
//  * prompt: string - the prompt to display to the user
//  * rangeBegin: double - the beginning of the range of acceptable values
//  * rangeEnd: double - the end of the range of acceptable values
// Returns:
//  * double - the user's input
double doubleInputChecked(string prompt, double rangeBegin, double rangeEnd);

#endif
