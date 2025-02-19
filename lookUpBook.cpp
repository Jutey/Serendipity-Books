/************************************************
* Assignment: G4
* Purpose: Serendipity Structs
* Author: Kenny Strawn
* Due Date: 2/19/2025
************************************************/

#include "lookUpBook.h"

using namespace std;

vector<string> lookUpBook(vector<bookType> db, string query)
{
  // `std::binary_search` sucks with arrays of structs,
  // so copying titles into temporary array of strings to make things easier
  vector<string> titles;
  
  // Also use a string vector for the results, since we'll need to call `find()` more than once
  vector<string> res;
  
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
  
  // Return the vector of search results -- the UI will take care of formatting them
  return res;
}
