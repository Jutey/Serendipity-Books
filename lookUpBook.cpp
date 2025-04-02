/************************************************
* Assignment: G4
* Purpose: Serendipity Structs
* Author: Kenny Strawn
* Due Date: 2/19/2025
************************************************/

#include "lookUpBook.h"
#include "book_info_deref.h" // for bookInfoDeref

using namespace std;

void cls()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

int lookUpBook(vector<bookType*> db)
{
  // `std::find` sucks with arrays of structs,
  // so copying titles into temporary array of strings to make things easier
  vector<string> titles;
  vector<string> fixedTitles;
  
  // User input
  string query;
  char foundResponse;
  char editResponse;
  char retryResponse;

  // Return value
	int out = -1;
	bool found = false;
	int currentBookCount = db.size();
 do {

  cls();

  cout << "Search: ";
  getline(cin, query);
  
  //copies book titles into the titles vectors

  for (bookType book : bookInfoDeref(db))
  {
    titles.push_back(book.getBookTitle());
  }

  // Converts query to a case-desensitized search query
  transform(query.begin(), query.end(), query.begin(), ::tolower);

  // Case-desensitize titles
  for (string title : titles)
  {
    transform(title.begin(), title.end(), title.begin(), ::tolower);
    fixedTitles.push_back(title);
  }
  
  //replace original title with lowercase option
  titles = fixedTitles;
  
  fixedTitles.clear();

  // Loop through titles, find results, and ask user if they found the book they were looking for
 for (int i = 0; i < titles.size(); i++)
 {
    // if (cin.fail())
    // {
    //   cin.clear();
    //   cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //   cout << "Not Found, try searching for a different book." << endl;
    //   break;
    // }
    if (titles[i].find(query) != string::npos)  // If query is found within the title
    {
      cout << "Found title: " << bookInfoDeref(db)[i].getBookTitle() << endl;  // Display original title
      cout << "Is this the book you're looking for? (y/n) ";
      cin.get(foundResponse);
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      foundResponse = tolower(foundResponse);

      switch (foundResponse)
      {
        case 'y':
          // Print book details
          bookInfoDeref(db)[i].print();
          cout << endl;
          out = i;
			 found = true;
          break;
        case 'n':
          continue; // Continue searching
        default:
          cout << "Error: invalid response. Please enter either y or n." << endl;
          continue;
      }
    }
   if(found)
	{
		cout << "Book not found. Would you like to search for another book? (y/n) ";
      cin.get(retryResponse);
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
		break;

	}
	if(tolower(retryResponse) != 'y')
	{
	 return -1;
	}

    if (foundResponse == 'y')
    {
      cout << "Press Enter to continue ..." << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      break;
    }
  }
	}while(out == -1);

  return out;
}
