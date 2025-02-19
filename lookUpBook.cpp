/************************************************
* Assignment: G4
* Purpose: Serendipity Structs
* Author: Kenny Strawn
* Due Date: 2/19/2025
************************************************/

#include "lookUpBook.h"

using namespace std;

void cls()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void lookUpBook(vector<bookType> db)
{
  // `std::find` sucks with arrays of structs,
  // so copying titles into temporary array of strings to make things easier
  vector<string> titles;
  
  // Results storage
  vector<string> res;
  
  // User input
  string query;
  char foundResponse;
  char editResponse;
  
  cls();
  cout << "Search: " << endl;
  getline(cin, query);
  
  for (bookType book : db)
  {
    titles.push_back(book.bookTitle);
  }
  
  // Sort temporary vector of titles for later searching
  sort(titles.begin(), titles.end());
  
  // Case-desensitize titles using `std::transform`
  for (string title : titles)
  {
    transform(title.begin(), title.end(), title.begin(), ::tolower);
  }
  
  // Case-desensitize search query using `std::transform`
  transform(query.begin(), query.end(), query.begin(), ::tolower);
  
  // Iterate through all matches
  auto iter = titles.begin();
  while ((iter = find(iter, titles.end(), query)) != titles.end())
  {
    res.push_back(*iter);
    iter = next(iter);
  }
  
  for (string found : res)
  {
    cout << "Found title: " << found << endl;
    cout << "Is this the book you're looking for? (y/n) ";
    cin.get(foundResponse);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    switch(foundResponse)
    {
      case 'y':
        cout << "Edit? (y/n) ";
        cin >> editResponse;
        break;
      case 'n':
        break;
      default:
        cout << "Error: invalid response. Please enter either y or n." << endl;
        break;
    }
  }
}
