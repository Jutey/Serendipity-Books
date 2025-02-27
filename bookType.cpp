#include "bookType.h"

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
  cout << "█" << setw(24) << " " << setw(54) << " "                        << "█" << endl;
  cout << "█" << setw(78) << " " << "█"      << endl;
  cout << "█" << setw(28) << " " << setw(50) << "Serendipity Book Sellers" << "█" << endl;
  cout << "█" << setw(35) << " " << setw(43) << "Book Information"         << "█" << endl;

  cout << "█" << setw(78) << " " << "█"      << endl;

  cout << "█" << setw(38) << " ISBN: "               << setw(40) << isbn      << "█" << endl;
  cout << "█" << setw(38) << " Title: "              << setw(40) << bookTitle << "█" << endl;
  cout << "█" << setw(38) << " Author: "             << setw(40) << author    << "█" << endl;
  cout << "█" << setw(38) << " Publisher: "          << setw(40) << publisher << "█" << endl;
  cout << "█" << setw(38) << " Date Added: "         << setw(40) << dateAdded << "█" << endl;
  cout << "█" << setw(38) << " Quantity-On-Hand: "   << setw(40) << qtyOnHand << "█" << endl;
  cout << "█" << setw(38) << " Wholesale Cost: $"    << setw(40) << wholesale << "█" << endl;
  cout << "█" << setw(38) << " Retail Price: $"      << setw(40) << retail    << "█" << endl;
  cout << "█" << setw(78) << " "           << "█"    << endl;
  cout << "█" << setw(78) << " "           << "█"    << endl;
  cout << "█" << setw(78) << " "           << "█"    << endl;
  cout << "█" << setw(78) << " "           << "█"    << endl;


  cout << "████████████████████████████████████████████████████████████████████████████████";
  cout << endl << endl << endl;
}
