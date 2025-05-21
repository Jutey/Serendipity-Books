/******************************************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Authors: Kenny Strawn, Romewin Villacorte, William Donnell-Crume, Cade Coxon
* Due Date: 5/21/2025
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>

#include "reports.h"
#include "int_input_checked.h"
#include "setw_consts.h"
#include "bookType.h"
#include "book_info_deref.h" // for bookInfoDeref
#include "linkedlist.h"
#include "orderedLinkedList.h"
#include "book_info_deref.h"
#include "selsort.h"

using namespace std;

void repListing(orderedLinkedList<bookType*> &bookInfo)
{
  // Pull the current Date from the system
  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  int year = localTime->tm_year + 1900;
  int month = localTime->tm_mon + 1;
  int day = localTime->tm_mday;
  string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

  int totalBooks = bookInfo.length();
  int totalPages = (totalBooks + 9) / 10;
  int currentPage = 1;
  string choice;

  do
  {
    int startingIndex = (currentPage - 1) * 10;
    int endingIndex = min(startingIndex + 10, totalBooks);

    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"
      << endl;
    cout << "█" << setw(REP_LISTING_WIDTH - 3) << right << " " << "█" << endl;
    cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << right << "SERENDIPITY BOOKSELLERS" << setw(REP_LISTING_TITLE_WIDTH + 1) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << right << "REPORT LISTING" << setw(REP_LISTING_TITLE_WIDTH + 1) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_WIDTH - 3) << right << " " << "█" << endl;
    cout << "█  Date: " << left << setw(12) << date 
       << "PAGE: " << setw(2) << currentPage 
       << " of " << setw(2) << totalPages 
       << " DATABASE SIZE: " << setw(5) << bookInfo.length()
       << " CURRENT BOOK COUNT: " << setw(5) << bookInfo.length()
       << setw(REP_LISTING_WIDTH - 84) << " " << "█" << endl;
    cout << "█" << setw(REP_LISTING_WIDTH - 3) << right << " " << "█" << endl;

    cout << "█  " << setw(31) << left << "TITLE"
       << setw(12) << "ISBN"
       << setw(21) << "AUTHOR"
       << setw(12) << "PUBLISHER"
       << setw(12) << "DATE ADDED"
       << setw(8)  << "QTY O/H"
       << setw(10) << "WHOLESALE"
       << setw(14) << "RETAIL"
       << "█" << endl;
    cout << "█  " << setw(31) << "----------------------------"
       << setw(12) << "----------"
       << setw(21) << "---------------------"
       << setw(12) << "----------"
       << setw(12) << "-----------"
       << setw(8)  << "-------"
       << setw(10) << "---------"
       << setw(14) << "-------"
       << "█" << endl;

    int idx = 0;

    for (linkedListIterator<bookType*> it = bookInfo.begin(); it != bookInfo.end(); ++it, ++idx)
    {
      if (idx < startingIndex) continue;
      if (idx >= endingIndex) break;
      const bookType& book = **it;
      cout << "█  " 
        << left << setw(31) 
        << (book.getBookTitle().length() > 30 ? book.getBookTitle().substr(0, 27) + "..." : book.getBookTitle())
        << setw(12) 
        << (book.getIsbn().length() > 12 ? book.getIsbn().substr(0, 9) + "..." : book.getIsbn())
        << setw(21) 
        << (book.getAuthor().length() > 21 ? book.getAuthor().substr(0, 18) + "..." : book.getAuthor())
        << setw(12) 
        << (book.getPublisher().length() > 12 ? book.getPublisher().substr(0, 9) + "..." : book.getPublisher())
        << setw(12) 
        << book.getDateAdded()
        << setw(8)  
        << book.getQtyOnHand()
        << "$" << right << setw(9) 
        << fixed << setprecision(2) << book.getWholesale()
        << "  $" << right << setw(9) 
        << book.getRetail()
        << "  █" << endl;
    }

    if (currentPage < totalPages)
    {
      cout << "█" << setw(REP_LISTING_WIDTH - 3) << left << "  Type \"2\" to go to the next page, or any other key to return..." << "█" << endl;
    } else
    {
      cout << "█" << setw(REP_LISTING_WIDTH - 3) << left << "  Press any key to return..." << "█" << endl;
    }
    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████" << endl;

    getline(cin, choice);
    if (choice == "2" && currentPage < totalPages) {
      currentPage++;
    } else {
      break;
    }
  } while (true);
}

void repWholesale(orderedLinkedList<bookType*> &bookInfo)
{
  // Get current date
  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  int year = localTime->tm_year + 1900;
  int month = localTime->tm_mon + 1;
  int day = localTime->tm_mday;
  string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

  int totalBooks = bookInfo.length();
  int totalPages = (totalBooks + 9) / 10;
  int currentPage = 1;
  string choice;
  double totalWholesale = 0.0;

  // Copy pointers to vector for sorting
  vector<bookType*> books;
  for (linkedListIterator<bookType*> it = bookInfo.begin(); it != bookInfo.end(); ++it)
    books.push_back(*it);

  // Sort by quantity on hand descending
  selectionSort(books.begin(), books.end(), [](bookType* a, bookType* b) {
    return a->getWholesale() > b->getWholesale();
  });

  do
  {
    int startingIndex = (currentPage - 1) * 10;
    int endingIndex = min(startingIndex + 10, totalBooks);

    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"
      << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << right << "SERENDIPITY BOOKSELLERS" << setw(REP_LISTING_TITLE_WIDTH + 1) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << right << "WHOLESALE VALUE REPORT" << setw(REP_LISTING_TITLE_WIDTH + 1) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;
    cout << "█  Date: " << left << setw(12) << date << "PAGE: " << currentPage << " of " << totalPages << setw(REP_LISTING_TITLE_WIDTH + 28) << " " << "█" << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;

    cout << "█  " << setw(31) << left << "TITLE"
       << setw(12) << "ISBN"
       << setw(8) << "QTY O/H"
       << setw(14) << "WHOLESALE COST"
       << setw(REP_LISTING_WIDTH - 70) << " " << "█" << endl;
    cout << "█  " << setw(31) << "----------------------------"
       << setw(12) << "----------"
       << setw(8) << "-------"
       << setw(14) << "--------------"
       << setw(REP_LISTING_WIDTH - 70) << " " << "█" << endl;

    int idx = 0;
    double pageWholesale = 0.0;
    for (int idx = startingIndex; idx < endingIndex; ++idx)
    {
      const bookType& book = *books[idx];
      double bookValue = book.getWholesale() * book.getQtyOnHand();
      pageWholesale += bookValue;
      cout << "█  " << left << setw(30) << book.getBookTitle().substr(0, 30)
      << setw(12) << book.getIsbn().substr(0, 12)
      << setw(9) << book.getQtyOnHand()
      << "$" << right << setw(13) << fixed << setprecision(2) << book.getWholesale()
      << "   (Total: $" << setw(10) << bookValue << ")"
      << setw(REP_LISTING_TAIL_PADDING + 26) << "█" << endl;
    }
    totalWholesale += pageWholesale;

    if (currentPage < totalPages)
    {
      cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << "Type \"2\" to go to the next page, or any other key to continue..." << setw(REP_LISTING_TITLE_WIDTH - 1) << "█" << endl;
    }
    else
    {
      cout << "█  Total Wholesale Value of Inventory: $" << fixed << setprecision(2) << totalWholesale << setw(76) << " " << "█" << endl;
      cout << "█" << setw(REP_LISTING_WIDTH - 3) << left << "  Press any key to return..." << "█" << endl;
    }
    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████" << endl;

    getline(cin, choice);
    if (choice == "2" && currentPage < totalPages)
    {
      currentPage++;
    }
    else
    {
      break;
    }
  } while (true);
}

void repRetail(orderedLinkedList<bookType*> &bookInfo)
{
  // Get current date
  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  int year = localTime->tm_year + 1900;
  int month = localTime->tm_mon + 1;
  int day = localTime->tm_mday;
  string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

  int totalBooks = bookInfo.length();
  int totalPages = (totalBooks + 9) / 10;
  int currentPage = 1;
  string choice;
  double totalRetail = 0.0;

  // Copy pointers to vector for sorting
  vector<bookType*> books;
  for (linkedListIterator<bookType*> it = bookInfo.begin(); it != bookInfo.end(); ++it)
    books.push_back(*it);

  // Sort by quantity on hand descending
  selectionSort(books.begin(), books.end(), [](bookType* a, bookType* b) {
    return a->getRetail() > b->getRetail();
  });

  do
  {
    int startingIndex = (currentPage - 1) * 10;
    int endingIndex = min(startingIndex + 10, totalBooks);

    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"
      << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << right << "SERENDIPITY BOOKSELLERS" << setw(REP_LISTING_TITLE_WIDTH + 1) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << right << "RETAIL VALUE REPORT" << setw(REP_LISTING_TITLE_WIDTH + 1) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;
    cout << "█  Date: " << left << setw(12) << date << "PAGE: " << currentPage << " of " << totalPages << setw(REP_LISTING_TITLE_WIDTH + 28) << " " << "█" << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;

    cout << "█  " << setw(31) << left << "TITLE"
       << setw(12) << "ISBN"
       << setw(8) << "QTY O/H"
       << setw(14) << "RETAIL PRICE"
       << setw(REP_LISTING_WIDTH - 70) << " " << "█" << endl;
    cout << "█  " << setw(31) << "----------------------------"
       << setw(12) << "----------"
       << setw(8) << "-------"
       << setw(14) << "--------------"
       << setw(REP_LISTING_WIDTH - 70) << " " << "█" << endl;

    int idx = 0;
    double pageRetail = 0.0;
    for (int idx = startingIndex; idx < endingIndex; ++idx)
    {
      const bookType& book = *books[idx];
      double bookValue = book.getRetail() * book.getQtyOnHand();
      pageRetail += bookValue;
      cout << "█  " << left << setw(30) << book.getBookTitle().substr(0, 30)
      << setw(12) << book.getIsbn().substr(0, 12)
      << setw(9) << book.getQtyOnHand()
      << "$" << right << setw(13) << fixed << setprecision(2) << book.getRetail()
      << "   (Total: $" << setw(10) << bookValue << ")"
      << setw(REP_LISTING_TAIL_PADDING + 26) << "█" << endl;
    }
    totalRetail += pageRetail;

    if (currentPage < totalPages)
    {
      cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << "Type \"2\" to go to the next page, or any other key to continue..." << setw(REP_LISTING_TITLE_WIDTH - 1) << "█" << endl;
    }
    else
    {
      cout << "█  Total Retail Value of Inventory: $" << fixed << setprecision(2) << totalRetail << setw(REP_LISTING_TITLE_WIDTH + 17) << " " << "█" << endl;
      cout << "█" << setw(REP_LISTING_WIDTH - 3) << left << "  Press any key to return..." << "█" << endl;
    }
    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████" << endl;

    getline(cin, choice);
    if (choice == "2" && currentPage < totalPages)
    {
      currentPage++;
    }
    else
    {
      break;
    }
  } while (true);
}

void repQty(orderedLinkedList<bookType*> &bookInfo)
{
  // Get current date
  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  int year = localTime->tm_year + 1900;
  int month = localTime->tm_mon + 1;
  int day = localTime->tm_mday;
  string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

  // Copy pointers to vector for sorting
  vector<bookType*> books;
  for (linkedListIterator<bookType*> it = bookInfo.begin(); it != bookInfo.end(); ++it)
    books.push_back(*it);

  // Sort by quantity on hand descending
  selectionSort(books.begin(), books.end(), [](bookType* a, bookType* b) {
    return a->getQtyOnHand() > b->getQtyOnHand();
  });

  int totalBooks = books.size();
  int totalPages = (totalBooks + 9) / 10;
  int currentPage = 1;
  string choice;

  do
  {
    int startingIndex = (currentPage - 1) * 10;
    int endingIndex = min(startingIndex + 10, totalBooks);

    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"
      << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << right << "SERENDIPITY BOOKSELLERS" << setw(REP_LISTING_TITLE_WIDTH + 1) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << right << "LISTING BY QUANTITY" << setw(REP_LISTING_TITLE_WIDTH + 1) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;
    cout << "█  Date: " << left << setw(12) << date << "PAGE: " << currentPage << " of " << totalPages << setw(REP_LISTING_TITLE_WIDTH + 28) << " " << "█" << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;

    cout << "█  " << setw(31) << left << "TITLE"
       << setw(12) << "ISBN"
       << setw(9) << "QTY O/H"
       << setw(14) << "WHOLESALE"
       << setw(14) << "RETAIL"
       << setw(REP_LISTING_WIDTH - 85) << " " << "█" << endl;
    cout << "█  " << setw(31) << "----------------------------"
       << setw(12) << "----------"
       << setw(9) << "-------"
       << setw(14) << "----------"
       << setw(14) << "----------"
       << setw(REP_LISTING_WIDTH - 85) << " " << "█" << endl;

    for (int idx = startingIndex; idx < endingIndex; ++idx)
    {
      const bookType& book = *books[idx];
      cout << "█  " << left << setw(30) << book.getBookTitle().substr(0, 30)
      << setw(12) << book.getIsbn().substr(0, 12)
      << setw(9) << book.getQtyOnHand()
      << "$" << right << setw(10) << fixed << setprecision(2) << book.getWholesale()
      << "  $" << right << setw(10) << book.getRetail()
      << setw(REP_LISTING_TAIL_PADDING + 39) << "█" << endl;
    }

    if (currentPage < totalPages)
    {
      cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << "Type \"2\" to go to the next page, or any other key to return..." << setw(REP_LISTING_TITLE_WIDTH + 1) << "█" << endl;
    }
    else
    {
      cout << "█" << setw(REP_LISTING_WIDTH - 3) << left << "  Press any key to return..." << "█" << endl;
    }
    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████" << endl;

    getline(cin, choice);
    if (choice == "2" && currentPage < totalPages)
    {
      currentPage++;
    }
    else
    {
      break;
    }
  } while (true);
}

void repCost(orderedLinkedList<bookType*> &bookInfo)
{
  // Get current date
  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  int year = localTime->tm_year + 1900;
  int month = localTime->tm_mon + 1;
  int day = localTime->tm_mday;
  string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

  // Copy pointers to vector for sorting
  vector<bookType*> books;
  for (linkedListIterator<bookType*> it = bookInfo.begin(); it != bookInfo.end(); ++it)
    books.push_back(*it);

  // Sort by wholesale cost descending
  selectionSort(books.begin(), books.end(), [](const bookType* a, const bookType* b) {
    return a->getWholesale() > b->getWholesale();
  });

  int totalBooks = books.size();
  int totalPages = (totalBooks + 9) / 10;
  int currentPage = 1;
  string choice;

  do
  {
    int startingIndex = (currentPage - 1) * 10;
    int endingIndex = min(startingIndex + 10, totalBooks);

    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"
      << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << right << "SERENDIPITY BOOKSELLERS" << setw(REP_LISTING_TITLE_WIDTH + 1) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << right << "LISTING BY COST" << setw(REP_LISTING_TITLE_WIDTH + 1) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;
    cout << "█  Date: " << left << setw(12) << date << "PAGE: " << currentPage << " of " << totalPages << setw(REP_LISTING_TITLE_WIDTH + 28) << " " << "█" << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;

    cout << "█  " << setw(31) << left << "TITLE"
       << setw(12) << "ISBN"
       << setw(10) << "WHOLESALE"
       << setw(9) << "QTY O/H"
       << setw(10) << "RETAIL"
       << setw(REP_LISTING_WIDTH - 77) << " " << "█" << endl;
    cout << "█  " << setw(31) << "----------------------------"
       << setw(12) << "----------"
       << setw(10) << "----------"
       << setw(9) << "-------"
       << setw(10) << "----------"
       << setw(REP_LISTING_WIDTH - 77) << " " << "█" << endl;

    for (int idx = startingIndex; idx < endingIndex; ++idx)
    {
      const bookType& book = *books[idx];
      cout << "█  " << left << setw(30) << book.getBookTitle().substr(0, 30)
      << setw(12) << book.getIsbn().substr(0, 12)
      << "$" << right << setw(10) << fixed << setprecision(2) << book.getWholesale()
      << setw(9) << book.getQtyOnHand()
      << "  $" << right << setw(10) << book.getRetail()
      << setw(REP_LISTING_TAIL_PADDING + 39) << "█" << endl;
    }

    if (currentPage < totalPages)
    {
      cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << "Type \"2\" to go to the next page, or any other key to return..." << setw(REP_LISTING_TITLE_WIDTH + 1) << "█" << endl;
    }
    else
    {
      cout << "█" << setw(REP_LISTING_WIDTH - 3) << left << "  Press any key to return..." << "█" << endl;
    }
    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████" << endl;

    getline(cin, choice);
    if (choice == "2" && currentPage < totalPages)
    {
      currentPage++;
    }
    else
    {
      break;
    }
  } while (true);
}

void repAge(orderedLinkedList<bookType*> &bookInfo)
{
  // Get current date
  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  int year = localTime->tm_year + 1900;
  int month = localTime->tm_mon + 1;
  int day = localTime->tm_mday;
  string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

  // Copy pointers to vector for sorting
  vector<bookType*> books;
  for (linkedListIterator<bookType*> it = bookInfo.begin(); it != bookInfo.end(); ++it)
    books.push_back(*it);

  // Sort by date added ascending (oldest first)
  selectionSort(books.begin(), books.end(), [](bookType* a, bookType* b) {
    return a->getDateAdded() < b->getDateAdded();
  });

  int totalBooks = books.size();
  int totalPages = (totalBooks + 9) / 10;
  int currentPage = 1;
  string choice;

  do
  {
    int startingIndex = (currentPage - 1) * 10;
    int endingIndex = min(startingIndex + 10, totalBooks);

    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"
      << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << right << "SERENDIPITY BOOKSELLERS" << setw(REP_LISTING_TITLE_WIDTH + 1) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << right << "LISTING BY AGE" << setw(REP_LISTING_TITLE_WIDTH + 1) << right << "█" << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;
    cout << "█  Date: " << left << setw(12) << date << "PAGE: " << currentPage << " of " << totalPages << setw(REP_LISTING_TITLE_WIDTH + 28) << " " << "█" << endl;
    cout << "█" << setw(REP_LISTING_WIDTH) << right << "█" << endl;

    cout << "█  " << setw(31) << left << "TITLE"
       << setw(12) << "ISBN"
       << setw(12) << "DATE ADDED"
       << setw(9) << "QTY O/H"
       << setw(10) << "WHOLESALE"
       << setw(10) << "RETAIL"
       << setw(REP_LISTING_WIDTH - 89) << " " << "█" << endl;
    cout << "█  " << setw(31) << "----------------------------"
       << setw(12) << "----------"
       << setw(12) << "----------"
       << setw(9) << "-------"
       << setw(10) << "----------"
       << setw(10) << "----------"
       << setw(REP_LISTING_WIDTH - 89) << " " << "█" << endl;

    for (int idx = startingIndex; idx < endingIndex; ++idx)
    {
      const bookType& book = *books[idx];
      cout << "█  " << left << setw(30) << book.getBookTitle().substr(0, 30)
      << setw(12) << book.getIsbn().substr(0, 12)
      << setw(12) << book.getDateAdded()
      << setw(9) << book.getQtyOnHand()
      << "$" << right << setw(10) << fixed << setprecision(2) << book.getWholesale()
      << "  $" << right << setw(10) << book.getRetail()
      << setw(REP_LISTING_TAIL_PADDING + 27) << "█" << endl;
    }

    if (currentPage < totalPages)
    {
      cout << "█" << setw(REP_LISTING_TITLE_WIDTH) << "Type \"2\" to go to the next page, or any other key to return..." << setw(REP_LISTING_TITLE_WIDTH + 1) << "█" << endl;
    }
    else
    {
      cout << "█" << setw(REP_LISTING_WIDTH - 3) << left << "  Press any key to return..." << "█" << endl;
    }
    cout << "████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████" << endl;

    getline(cin, choice);
    if (choice == "2" && currentPage < totalPages)
    {
      currentPage++;
    }
    else
    {
      break;
    }
  } while (true);
}

void reports(orderedLinkedList<bookType*> &bookInfo)
{
  int choice;
  do
  {
    cout << "\033[2J\033[1;1H";
    cout << endl << endl;
    //cout << setfill("█") << setw(80) << "#" << endl;
    cout << left;
    cout << "████████████████████████████████████████████████████████████████████████████████";
    cout << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(MENU_HEAD_PADDING) << " " << setw(MENU_HEAD_WIDTH) << "Serendipity Book Sellers" << "█" << endl;
    cout << "█" << setw(BOOK_INFO_SUBTITLE_PADDING) << " " << setw(BOOK_INFO_SUBTITLE_WIDTH) << "Reports" << "█" << endl;

    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;

    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "1. Inventory Listing" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "2. Inventory Wholesale Value" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "3. Inventory Retail Value" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "4. Listing by Quantity" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "5. Listing by Cost" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_BODY_WIDTH) << "6. Listing by Age" << "█" << endl;
    cout << "█" << setw(MENU_BODY_PADDING) << " " << setw(MENU_EXIT_PADDING) << "\033[32m7. Return to Main Menu\033[0m " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;
    cout << "█" << setw(WINDOW_INNER) << " " << "█" << endl;


    cout << "████████████████████████████████████████████████████████████████████████████████";
    cout << endl << endl << endl;

    choice = intInputChecked("Enter Your Choice", 1, 7);

    switch(choice)
    {

      case 1:
      //  cout << "You selected item 1." << endl;
      //  cout << "Press ENTER to continue ...";
      //  cin.ignore(numeric_limits<streamsize>::max(), '\n');
      if (bookInfo.isEmptyList())
      {
        cout << "█" << setw(MENU_BODY_PADDING) << " " << "The database is empty. Please add a book." << setw(35) << "█" << endl;
      }
      else
      {
        repListing(bookInfo);
      }
      break;

      case 2:
        repWholesale(bookInfo);
        break;

      case 3:
        repRetail(bookInfo);
        break;

      case 4:
        repQty(bookInfo);
        break;

      case 5:
        repCost(bookInfo);
        break;

      case 6:
        repAge(bookInfo);
        break;
        
      case 7:
        break;
      default:
        cout << "Please enter a number from the range of 1-7" << endl;

    }
    cout << "\033[2J\033[1;1H";

  } while(choice != 7);
}

