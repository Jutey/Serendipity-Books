/******************************************************************************
* Assignment: Exam 3
* Purpose: Serendipity Final Project
* Authors: Kenny Strawn, Romewin Villacorte, William Donnell-Crume, Cade Coxon
* Due Date: 5/21/2025
*******************************************************************************/

#include "bookType.h"
#include "setw_consts.h"

using namespace std;

int bookType::num_recs = 0;


bookType::bookType()
{
  this->bookTitle = "EMPTY";
  this->isbn = "EMPTY";
  this->author = "EMPTY";
  this->publisher = "EMPTY";
  this->dateAdded = "EMPTY";
  this->qtyOnHand = 0;
  this->wholesale = 0.0;
  this->retail = 0.0;
  num_recs++;
}

bookType::bookType(string title,
                  string isbn,
                  string author,
                  string publisher,
                  string date,
                  int qty,
                  double wholesale,
                  double retail)
{
  this->bookTitle = title;
  this->isbn = isbn;
  this->author = author;
  this->publisher = publisher;
  this->dateAdded = date;
  this->qtyOnHand = qty;
  this->wholesale = wholesale;
  this->retail = retail;

  num_recs++;
}

void bookType::setBookTitle(string title)
{
  this->bookTitle = title;
}

void bookType::setIsbn(string isbn)
{
  this->isbn = isbn;
}

void bookType::setAuthor(string author)
{
  this->author = author;
}

void bookType::setPublisher(string publisher)
{
  this->publisher = publisher;
}

void bookType::setDateAdded(string date)
{
  this->dateAdded = date;
}

void bookType::setQtyOnHand(int qty)
{
  this->qtyOnHand = qty;
}

void bookType::setWholesale(double wholesale)
{
  this->wholesale = wholesale;
}

void bookType::setRetail(double retail)
{
  this->retail = retail;
}
int bookType::getNumRecs()
{
	return num_recs;
}

string bookType::getBookTitle() const
{
  return bookTitle;
}

string bookType::getIsbn() const
{
  return isbn;
}

string bookType::getAuthor() const
{
  return author;
}

string bookType::getPublisher() const
{
  return publisher;
}

string bookType::getDateAdded() const
{
  return dateAdded;
}

int bookType::getQtyOnHand() const
{
  return qtyOnHand;
}

double bookType::getWholesale() const
{
  return wholesale;
}

double bookType::getRetail() const
{
  return retail;
}

void bookType::incrementNumRecs()
{
  num_recs++;
}
void bookType::decrementNumRecs()
{
  num_recs--;
}

bool bookType::operator==(const bookType& other) const
{
  return bookTitle == other.bookTitle &&
        isbn == other.isbn &&
        author == other.author &&
        publisher == other.publisher &&
        dateAdded == other.dateAdded &&
        qtyOnHand == other.qtyOnHand &&
        wholesale == other.wholesale &&
        retail == other.retail;
}

bool bookType::operator!=(const bookType& other) const
{
  return !(*this == other);
}

bool bookType::operator>=(const bookType& other) const
{
  if (bookTitle != other.bookTitle)
  {
    return bookTitle > other.bookTitle;
  }
  if (isbn != other.isbn)
  {
    return isbn > other.isbn;
  }
  if (author != other.author)
  {
    return author > other.author;
  }
  if (publisher != other.publisher)
  {
    return publisher > other.publisher;
  }
  if (dateAdded != other.dateAdded)
  {
    return dateAdded > other.dateAdded;
  }
  if (qtyOnHand != other.qtyOnHand)
  {
    return qtyOnHand > other.qtyOnHand;
  }
  if (wholesale != other.wholesale)
  {
    return wholesale > other.wholesale;
  }
  return retail >= other.retail;
}

void bookType::print() const
{
  ostringstream wholesaleOss;
  ostringstream retailOss;

  wholesaleOss << fixed << setprecision(2) << "$" << wholesale;
  retailOss << fixed << setprecision(2) << "$" << retail;

  string wholesaleFmt = wholesaleOss.str();
  string retailFmt = retailOss.str();

  string fixedTitle = bookTitle;

  // Check if the book title is too long
  if (bookTitle.length() > BOOK_INFO_BODY_WIDTH)
  {
    fixedTitle = bookTitle.substr(0, BOOK_INFO_BODY_WIDTH - 3) + "...";
  }

  cout << endl << endl;
  //cout << setfill("█") << setw(80) << "#" << endl;
  cout << left;
  cout << "████████████████████████████████████████████████████████████████████████████████";
  cout << endl;
  cout << "█" << setw(BOOK_INFO_TITLE_PADDING) << " " << setw(BOOK_INFO_TITLE_WIDTH) << " "                        << "█" << endl;
  cout << "█" << setw(WINDOW_INNER) << " " << "█"      << endl;
  cout << "█" << setw(BOOK_INFO_TITLE_PADDING) << " " << setw(BOOK_INFO_TITLE_WIDTH) << "Serendipity Book Sellers" << "█" << endl;
  cout << "█" << setw(BOOK_INFO_SUBTITLE_PADDING) << " " << setw(BOOK_INFO_SUBTITLE_WIDTH) << "Book Information"         << "█" << endl;

  cout << "█" << setw(WINDOW_INNER) << " " << "█"      << endl;

  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " ISBN: "               << setw(BOOK_INFO_BODY_WIDTH) << isbn         << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Title: "              << setw(BOOK_INFO_BODY_WIDTH) << fixedTitle    << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Author: "             << setw(BOOK_INFO_BODY_WIDTH) << author       << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Publisher: "          << setw(BOOK_INFO_BODY_WIDTH) << publisher    << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Date Added: "         << setw(BOOK_INFO_BODY_WIDTH) << dateAdded    << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Quantity-On-Hand: "   << setw(BOOK_INFO_BODY_WIDTH) << qtyOnHand    << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Wholesale Cost: "     << setw(BOOK_INFO_BODY_WIDTH) << wholesaleFmt << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Retail Price: "       << setw(BOOK_INFO_BODY_WIDTH) << retailFmt    << "█" << endl;
  cout << "█" << setw(WINDOW_INNER) << " "           << "█"    << endl;
  cout << "█" << setw(WINDOW_INNER) << " "           << "█"    << endl;
  cout << "█" << setw(WINDOW_INNER) << " "           << "█"    << endl;
  cout << "█" << setw(WINDOW_INNER) << " "           << "█"    << endl;

  cout << "████████████████████████████████████████████████████████████████████████████████";
  cout << endl << endl << endl;
}

bookType::~bookType()
{
  //destructor
	num_recs--;
}
