/************************************************
* Assignment: A6
* Purpose: Structs
* Author: Kenny Strawn
* Due Date: 2/9/2025
************************************************/

#include "int_input_checked.h"

using namespace std;

// Function to stop input failure in its tracks (int version)
int intInputChecked(string prompt)
{
  int out;
  cout << prompt << ": ";
  cin >> out;

  while (cin.fail())
  {
    cin.clear();
    cout << "Error: please enter a number.";

    cout << prompt << ": ";
    cin >> out;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return out;
}

// Function to stop input failure in its tracks (long version)
long long intInputCheckedLong(string prompt)
{
  long long out;
  cout << prompt << ": ";
  cin >> out;

  while (cin.fail())
  {
    cin.clear();
    cout << "Error: please enter a number.";

    cout << prompt << ": ";
    cin >> out;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return out;
}
