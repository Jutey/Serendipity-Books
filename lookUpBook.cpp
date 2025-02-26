/************************************************
* Assignment: G4
* Purpose: Serendipity Structs
* Author: Kenny Strawn
* Due Date: 2/19/2025
************************************************/

#include "lookUpBook.h"
#include "editBook.h"

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
  vector<string> fixedTitles;
  
  // User input
  string query;
  char foundResponse;
  char editResponse;

  int currentBookCount = db.size();
  
  cls();
  cout << "Search: ";
  getline(cin, query);
  
  for (bookType book : db)
  {
    titles.push_back(book.getBookTitle());
  }

  // Case-desensitize search query
  transform(query.begin(), query.end(), query.begin(), ::tolower);

  // Case-desensitize titles
  for (string title : titles)
  {
    transform(title.begin(), title.end(), title.begin(), ::tolower);
    fixedTitles.push_back(title);
  }
  
  titles = fixedTitles;
  fixedTitles.clear();
  
  // Loop through titles, find results, and ask user if they found the book they were looking for
  for (string title : titles)
  {
    if (title.find(query) != title.npos)
    {
      cout << "Found title: " << title << endl;
      cout << "Is this the book you're looking for? (y/n) ";
      cin.get(foundResponse);
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      foundResponse = tolower(foundResponse);
      
      switch(foundResponse)
      {
        case 'y':
          // Match found title with the title of the book in the database, then print all of the book's fields
          for (bookType book : db)
          {
            string bookTitleLowered = book.getBookTitle();
            transform(bookTitleLowered.begin(), bookTitleLowered.end(), bookTitleLowered.begin(), ::tolower);

            if (bookTitleLowered == title)
            {
              book.print();
              cout << endl;
              cout << "Would you like to edit this book? (y/n) ";
              cin.get(editResponse);
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              editResponse = tolower(editResponse);
              
              switch(editResponse)
              {
                case 'y':
                  editBook(book.getBookTitle(), currentBookCount, db, DBSIZE);
                  break;
                case 'n':
                  break;
                default:
                  cout << "Error: invalid response. Please enter either y or n." << endl;
                  break;
              }
            }
          }
          break;
        case 'n':
          continue;
        default:
          cout << "Error: invalid response. Please enter either y or n." << endl;
          continue;
      }

      if (foundResponse == 'y')
      {
        break;
      }
    }
    else {
      cout << "No results found." << endl;
      break;
    }
  }
}
