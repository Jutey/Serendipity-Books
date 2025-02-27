#include "bookType.h"
#include "setw_consts.h"

using namespace std;

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

void bookType::print() const
{
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

  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " ISBN: "               << setw(BOOK_INFO_BODY_WIDTH) << isbn      << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Title: "              << setw(BOOK_INFO_BODY_WIDTH) << bookTitle << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Author: "             << setw(BOOK_INFO_BODY_WIDTH) << author    << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Publisher: "          << setw(BOOK_INFO_BODY_WIDTH) << publisher << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Date Added: "         << setw(BOOK_INFO_BODY_WIDTH) << dateAdded << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Quantity-On-Hand: "   << setw(BOOK_INFO_BODY_WIDTH) << qtyOnHand << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Wholesale Cost: $"    << setw(BOOK_INFO_BODY_WIDTH) << wholesale << "█" << endl;
  cout << "█" << setw(BOOK_INFO_BODY_PADDING) << " Retail Price: $"      << setw(BOOK_INFO_BODY_WIDTH) << retail    << "█" << endl;
  cout << "█" << setw(WINDOW_INNER) << " "           << "█"    << endl;
  cout << "█" << setw(WINDOW_INNER) << " "           << "█"    << endl;
  cout << "█" << setw(WINDOW_INNER) << " "           << "█"    << endl;
  cout << "█" << setw(WINDOW_INNER) << " "           << "█"    << endl;


  cout << "████████████████████████████████████████████████████████████████████████████████";
  cout << endl << endl << endl;
}
