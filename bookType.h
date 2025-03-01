#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const int DBSIZE = 20;

/// This is a class to store info for each book
///
/// Every Book has a Title, ISBN, Author, Publisher, Date Added to the Database, Quantity, Wholesale value, and Retail value
class bookType {
	private:
		string bookTitle;
		string isbn;
		string author;
		string publisher;
		string dateAdded;
		int qtyOnHand;
		double wholesale;
		double retail;
	public:
		/// Contains Default Values for Private Members.
		///
		/// Default values from this function are used as placeholders when updating the database.
		///@returns nothing meaningful for the moment
		bookType();
		/// Pushes an Update for All Private Members When Called.
		///
		/// Makes sure each value from the user has been updated and stored in the database.
		///@param string: Placeholders for all string members of the class, being bookTitle, isbn, author, publisher, and dateAdded
		///@param int: Placeholders for all int members of the class, being qtyOnHand
		///@param double: Placeholders for all double members of the class, being wholesale and retail
		///@returns nothing meaningful for the moment
		bookType(string, string, string, string, string, int, double, double);
		/// Sets the Book Title Based on Input.
		///
		/// Takes a value from the user as a parameter and updates the title accordingly.
		///@param string: Placeholder for the bookTitle
		///@returns nothing meaningful for the moment
		void setBookTitle(string);
		/// Sets the Book's ISBN Based on Input.
		///
		/// Takes a value from the user as a parameter and updates the isbn accordingly.
		///@param string: Placeholder for the isbn
		///@returns nothing meaningful for the moment
		void setIsbn(string);
		/// Sets the Book's Author Based on Input.
		///
		/// Takes a value from the user as a parameter and updates the author accordingly.
		///@param string: Placeholder for the author
		///@returns nothing meaningful for the moment
		void setAuthor(string);
		/// Sets the Book's Publisher Based on Input.
		///
		/// Takes a value from the user as a parameter and updates the publisher accordingly.
		///@param string: Placeholder for the publisher
		///@returns nothing meaningful for the moment
		void setPublisher(string);
		/// Sets the Book's Date Of Addition Based on Input.
		///
		/// Takes a value from the user as a parameter and updates the date of addition accordingly.
		///@param string: Placeholder for the dateAdded
		///@returns nothing meaningful for the moment
		void setDateAdded(string);
		/// Sets the Book's On Hand Quantity Based on Input.
		///
		/// Takes a value from the user as a parameter and updates the on hand quantity accordingly.
		///@param int: Placeholder for the qtyOnHand
		///@returns nothing meaningful for the moment
		void setQtyOnHand(int);
		/// Sets the Book's Wholesale Value Based on Input.
		///
		/// Takes a value from the user as a parameter and updates the wholesale value accordingly.
		///@param double: Placeholder for the wholesale value
		///@returns nothing meaningful for the moment
		void setWholesale(double);
		/// Sets the Book's Retail Value Based on Input.
		///
		/// Takes a value from the user as a parameter and updates the retail value accordingly.
		///@param double: Placeholder for the retail value
		///@returns nothing meaningful for the moment
		void setRetail(double);
		/// Gets the Current Value of the Book's title.
		///
		/// Finds the corresponding member within the class object and returns it's value.
		///@returns bookTitle of type string
		string getBookTitle() const;
		/// Gets the Current Value of the Book's ISBN.
		///
		/// Finds the corresponding member within the class object and returns it's value.
		///@returns isbn of type string
		string getIsbn() const;
		/// Gets the Current Value of the Book's Author.
		///
		/// Finds the corresponding member within the class object and returns it's value.
		///@returns author of type string
		string getAuthor() const;
		/// Gets the Current Value of the Book's Publisher.
		///
		/// Finds the corresponding member within the class object and returns it's value.
		///@returns publisher of type string
		string getPublisher() const;
		/// Gets the Current Value of the Book's Date of Addition.
		///
		/// Finds the corresponding member within the class object and returns it's value.
		///@returns dateAdded of type string
		string getDateAdded() const;
		/// Gets the Current Value of the Book's On Hand Quantity.
		///
		/// Finds the corresponding member within the class object and returns it's value.
		///@returns qtyOnHand of type int
		int getQtyOnHand() const;
		/// Gets the Current Value of the Book's Wholesale Value.
		///
		/// Finds the corresponding member within the class object and returns it's value.
		///@returns wholesale of type double
		double getWholesale() const;
		/// Gets the Current Value of the Book's Retail Value.
		///
		/// Finds the corresponding member within the class object and returns it's value.
		///@returns retail of type double
		double getRetail() const;
		/// Creates and Displays a Record of the Book.
		///
		/// Rounds up all of the values for the specified index in the database and prints the record. This tells the user everything they may want to know about the book.
		///@returns nothing meaningful for the moment
		void print() const;
};

#endif
