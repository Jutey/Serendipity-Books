#include <iostream>
#include <iomanip>
#include <string>
#include "bookType.h" //struct header here
#include "addBook.h"

using namespace std;

//bookCount is a variable that should be addressed and initialized within main
//Default array/vector name is bookInfo if that's easiest, otherwise update lines 138-145
//Also, make sure this vvvvvvvv filler parameter gets updated, wasn't sure what we were using
void addBook(bookType &passVectorOrArrayOfStructsHere, int &bookCount) {
	int    choice;
	string bookTitle;
	string isbn;
	string author;
	string publisher;
	string dateAdded;
	int    qtyOnHand;
	double wholesale;
	double retail;

	//initialize all filler variables
	bookTitle = "EMPTY";
	isbn      = "EMPTY";
	author    = "EMPTY";
	publisher = "EMPTY";
	dateAdded = "EMPTY";
	qtyOnHand = 0;
	wholesale = 0.00;
	retail    = 0.00;

	do
	{
	cout << "\033[2J\033[1;1H";
	cout << endl << endl;
	//cout << setfill("█") << setw(80) << "#" << endl;
	cout << left;
	cout << "████████████████████████████████████████████████████████████████████████████████";
	cout << right << endl;
	cout << "█" << setw(53) << "SERENDIPITY  BOOKSELLERS" << setw(25) << " " << "█" << endl;
	cout << "█" << setw(45) << "ADD BOOK"                 << setw(33) << " " << "█" << endl;
	cout << "█" << setw(78) << " " << "█" << endl;
	cout << "█" << setw(45) << "DATABASE SIZE:"           << setw(4)  << "  20"
					<< setw(20) << "CURRENT BOOK COUNT:"      << setw(4)  << bookCount
					<< setw(5)  << " " << "█" << endl;
	cout << "█" << setw(78) << " " << "█" << endl;
	cout << "█" << setw(70) << "--PENDING VALUES"         << setw(8)  << " " << "█" << endl;

	cout << left;

	cout << "█" << setw(1)  << " " << setw(36) << "<1> Enter Book Title"              << ">  --"
					<< setw(38) << bookTitle << "█" << endl;
	cout << "█" << setw(1)  << " " << setw(36) << "<2> Enter ISBN"                    << ">  --"
					<< setw(38) << isbn      << "█" << endl;
	cout << "█" << setw(1)  << " " << setw(36) << "<3> Enter Author"                  << ">  --"
					<< setw(38) << author    << "█" << endl;
	cout << "█" << setw(1)  << " " << setw(36) << "<4> Enter Publisher"               << ">  --"
					<< setw(38) << publisher << "█" << endl;
	cout << "█" << setw(1)  << " " << setw(36) << "<5> Enter Date Added <mm/dd/yyyy>" << ">  --"
					<< setw(38) << dateAdded << "█" << endl;
	cout << "█" << setw(1)  << " " << setw(36) << "<6> Enter Quantity on Hand"        << ">  --"
					<< setw(38) << qtyOnHand << "█" << endl;
	cout << fixed << setprecision(2);
	cout << "█" << setw(1)  << " " << setw(36) << "<7> Enter Wholesale Cost"          << ">  --$"
					<< setw(37) << wholesale << "█" << endl;
	cout << "█" << setw(1)  << " " << setw(36) << "<8> Enter Retail Price"            << ">  --$"
					<< setw(37) << retail    << "█" << endl;
	cout << unsetf(ios::fixed) << setprecision(6);
	cout << "█" << setw(1)  << " " << setw(36) << "<9> Save Book To Database"    << setw(41) << " " << "█" << endl;
	cout << "█" << setw(1)  << " " << setw(36) << "<0> Return to Inventory Menu" << setw(41) << " " << "█" << endl;

	cout << "█" << setw(78) << " " << "█" << endl;

	cout << "████████████████████████████████████████████████████████████████████████████████";
	cout << endl;

	cout << "		Choice<0-9>:";
	cin >> choice;
   cin.ignore(10000, '\n');


	    if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a valid number from the range of 0-9." << endl;
            continue;
        }

		switch(choice)
	{

		case 1:
			cout << "Enter Book Title: ";
			getline(cin, bookTitle);
			cout << "\033[2J\033[1;1H";
			break;
		case 2:
			cout << "Enter ISBN: ";
			getline(cin, isbn);
			cout << "\033[2J\033[1;1H";
			break;
		case 3:
			cout << "Enter Author: ";
			getline(cin, author);
			cout << "\033[2J\033[1;1H";
			break;
		case 4:
			cout << "Enter Publisher: ";
			getline(cin, publisher);
			cout << "\033[2J\033[1;1H";
			break;
		case 5:
			cout << "Enter Date Added: ";
			getline(cin, dateAdded);
			cout << "\033[2J\033[1;1H";
			break;
		case 6:
			cout << "Enter Quantity on Hand: ";
			cin  >> qtyOnHand;
			cin.ignore(10000, '\n');
			cout << "\033[2J\033[1;1H";
			break;
		case 7:
			cout << "Enter Wholesale Cost: ";
			cin  >> wholesale;
			cin.ignore(10000, '\n');
			cout << "\033[2J\033[1;1H";
			break;
		case 8:
			cout << "Enter Retail Price: ";
			cin  >> retail;
			cin.ignore(10000, '\n');
			cout << "\033[2J\033[1;1H";
			break;
		case 9:
			//pass all filler information into the struct array/vector
			bookInfo[bookCount].bookTitle = bookTitle;
			bookInfo[bookCount].isbn      = isbn;
			bookInfo[bookCount].author    = author;
			bookInfo[bookCount].publisher = publisher;
			bookInfo[bookCount].dateAdded = dateAdded;
			bookInfo[bookCount].qtyOnHand = qtyOnHand;
			bookInfo[bookCount].wholesale = wholesale;
			bookInfo[bookCount].retail    = retail;
			//update bookCount
			bookCount++;
			//re-initialize all filler variables
			bookTitle = "EMPTY";
			isbn      = "EMPTY";
			author    = "EMPTY";
			publisher = "EMPTY";
			dateAdded = "EMPTY";
			qtyOnHand = 0;
			wholesale = 0.00;
			retail    = 0.00;
			//clear screen
			cout << "\033[2J\033[1;1H";
			break;
		case 0;
			break;
		default:
			cout << "Please enter a number from the range of 0-9" << endl;

	}

	cout << "\033[2J\033[1;1H";

  }while(choice != 0 && bookCount < 20);

  return;
}
