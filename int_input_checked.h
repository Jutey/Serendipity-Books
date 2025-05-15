/************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Author: Kenny Strawn
* Due Date: 5/21/2025
************************************************/

#ifndef __INT_INPUT_CHECKED_H__
#define __INT_INPUT_CHECKED_H__

#include <iostream>
#include <limits>
#include <string>

using namespace std;

/// Function to stop input failure in its tracks (int version)
///
/// Checks integers to make sure their values are valid. If they are not, the user gets an error and is asked to give a new input
///@param prompt: string - the prompt to display to the user
///@param rangeBegin: int - the beginning of the range of acceptable values
///@param rangeEnd: int - the end of the range of acceptable values
///@returns int - the user's input
int intInputChecked(string prompt, int rangeBegin, int rangeEnd);

/// Function to stop input failure in its tracks (long long version)
///
/// Checks long long integers to make sure the input is valid. If they are not, the user gets an error and is asked to give a new input
///@param prompt: string - the prompt to display to the user
///@param rangeBegin: long long - the beginning of the range of acceptable values
///@param rangeEnd: long long - the end of the range of acceptable values
///@returns long long - the user's input
long long intInputCheckedLong(string prompt, long long rangeBegin, long long rangeEnd);

/// Function to stop input failure in its tracks (float version)
///
/// Checks floating point values to make sure the input is valid. If they are not, the user gets an error and is asked to give a new input
///@param prompt: string - the prompt to display to the user
///@param rangeBegin: float - the beginning of the range of acceptable values
///@param rangeEnd: float - the end of the range of acceptable values
///@returns float - the user's input
float floatInputChecked(string prompt, float rangeBegin, float rangeEnd);


/// Function to stop input failure in its tracks (double version)
///
/// Checks doubles to make sure their values are valid. If they are not, the user gets an error and is asked to give a new input
///@param prompt: string - the prompt to display to the user
///@param rangeBegin: double - the beginning of the range of acceptable values
///@param rangeEnd: double - the end of the range of acceptable values
///@returns double - the user's input
double doubleInputChecked(string prompt, double rangeBegin, double rangeEnd);

#endif
