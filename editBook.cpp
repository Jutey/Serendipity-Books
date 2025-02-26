#include "editBook.h"
#include "int_input_checked.h"

// Function: editBook
void editBook(vector<bookType> &bookInfo, int &bookCount, const int DBSIZE)
{
    string matcher;
    int choice;

    do
    {
        cout << "\033[2J\033[1;1H";
        
        cout << "Enter either the title or the ISBN of the book you want to edit: ";
        cin >> matcher;

        // Use regex to check for dashes and digits, then select the option accordingly
        if (regex_match(matcher, regex("([0-9]{1,3})-([0-9]{3})-([0-9]{3})-([0-9]{1,}|[X])")))
        {
            cout << "ISBN detected" << endl;
            cout << "Editing by ISBN" << endl;
            cout << "Press Enter to continue..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cout << "Title detected" << endl;
            cout << "Editing by title" << endl;
            cout << "Press Enter to continue..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        for (int i = 0; i < bookCount; i++)
        {
            if (bookInfo[i].getBookTitle() == matcher || bookInfo[i].getIsbn() == matcher)
            {
                cout << "\033[2J\033[1;1H";
                cout << endl << endl;
                //cout << setfill("█") << setw(80) << "#" << endl;
                cout << left;
                cout << "████████████████████████████████████████████████████████████████████████████████";
                cout << right << endl;
                cout << "█" << setw(53) << "SERENDIPITY  BOOKSELLERS"  << setw(25) << " " << "█" << endl;
                cout << "█" << setw(45) << "EDIT BOOK"                 << setw(33) << " " << "█" << endl;
                cout << "█" << setw(78) << " " << "█" << endl;
                cout << "█" << setw(45) << "DATABASE SIZE:"            << setw(4)  << "  20"
                            << setw(20) << "CURRENT BOOK COUNT:"       << setw(4)  << bookCount
                            << setw(5)  << " " << "█" << endl;
                cout << "█" << setw(78) << " " << "█" << endl;
                cout << "█" << setw(54) << "--PENDING VALUES"          << setw(24)  << " " << "█" << endl;
        
                cout << left;
        
                cout << "█"   << " "              << setw(34)                   << "<1> Update Book Title"              << ">  --"
                              << setw(38)         << bookInfo[i].getBookTitle() << "█" << endl;
                cout << "█"   << " "              << setw(34)                   << "<2> Update ISBN"                    << ">  --"
                              << setw(38)         << bookInfo[i].getIsbn()      << "█" << endl;
                cout << "█"   << " "              << setw(34)                   << "<3> Update Author"                  << ">  --"
                              << setw(38)         << bookInfo[i].getAuthor()    << "█" << endl;
                cout << "█"   << " "              << setw(34)                   << "<4> Update Publisher"               << ">  --"
                              << setw(38)         << bookInfo[i].getPublisher() << "█" << endl;
                cout << "█"   << " "              << setw(34)                   << "<5> Date Last Updated <mm/dd/yyyy>" << ">  --"
                              << setw(38)         << bookInfo[i].getDateAdded() << "█" << endl;
                cout << "█"   << " "              << setw(34)                   << "<6> Update Quantity on Hand"        << ">  --"
                              << setw(38)         << bookInfo[i].getQtyOnHand() << "█" << endl;
                cout << fixed << setprecision(2);
                cout << "█"   << " "              << setw(34)                   << "<7> Update Wholesale Cost"          << ">  --$"
                              << setw(37)         << bookInfo[i].getWholesale() << "█" << endl;
                cout << "█"   << " "              << setw(34)                   << "<8> Update Retail Price"            << ">  --$"
                              << setw(37)         << bookInfo[i].getRetail()    << "█" << endl;
                
                cout.unsetf(ios::fixed);
                cout << setprecision(6);
                cout << "█" << setw(1)  << " " << setw(36) << "<9> Return to Inventory Menu" << setw(41) << " " << "█" << endl;
        
                cout << "█" << setw(78) << " " << "█" << endl;
        
                cout << "████████████████████████████████████████████████████████████████████████████████";
                cout << endl;

                choice = intInputChecked("        Choice<1-9>", 1, 9);

                string tmpTitle = bookInfo[i].getBookTitle();
                string tmpIsbn = bookInfo[i].getIsbn();
                string tmpAuthor = bookInfo[i].getAuthor();
                string tmpPublisher = bookInfo[i].getPublisher();
                string tmpDateAdded = bookInfo[i].getDateAdded();
                int tmpQtyOnHand = bookInfo[i].getQtyOnHand();
                double tmpWholesale = bookInfo[i].getWholesale();
                double tmpRetail = bookInfo[i].getRetail();

                char save;

                // Use switch to handle the user's choice
                switch(choice)
                {

                    case 1:
                        cout << "Enter Book Title: ";
                        getline(cin, tmpTitle);

                        cout << "New title: " << tmpTitle << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving title ..." << endl;
                            bookInfo[i].setBookTitle(tmpTitle);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Title not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 2:
                        cout << "Enter ISBN: ";
                        getline(cin, tmpIsbn);
                        
                        cout << "New ISBN: " << tmpIsbn << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving ISBN ..." << endl;
                            bookInfo[i].setBookTitle(tmpTitle);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "ISBN not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 3:
                        cout << "Enter Author: ";
                        getline(cin, tmpAuthor);
                        
                        cout << "New author: " << tmpAuthor << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving author ..." << endl;
                            bookInfo[i].setAuthor(tmpAuthor);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Author not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 4:
                        cout << "Enter Publisher: ";
                        getline(cin, tmpPublisher);
                        
                        cout << "New publisher: " << tmpPublisher << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving publisher ..." << endl;
                            bookInfo[i].setPublisher(tmpPublisher);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Publisher not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 5:
                        cout << "Enter Date Last Updated: ";
                        getline(cin, tmpDateAdded);

                        cout << "New date last updated: " << tmpDateAdded << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving date last updated ..." << endl;
                            bookInfo[i].setDateAdded(tmpDateAdded);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Date not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 6:
                        cout << "Enter Quantity on Hand: ";
                        cin >> tmpQtyOnHand;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        
                        cout << "New quantity on hand: " << tmpQtyOnHand << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving quantity on hand ..." << endl;
                            bookInfo[i].setQtyOnHand(tmpQtyOnHand);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Quantity on hand not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 7:
                        cout << "Enter Wholesale Cost: ";
                        cin  >> tmpWholesale;
                        
                        cout << "New wholesale cost: " << tmpWholesale << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving wholesale cost ..." << endl;
                            bookInfo[i].setWholesale(tmpWholesale);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Wholesale cost not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 8:
                        cout << "Enter Retail Price: ";
                        cin  >> tmpRetail;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        
                        cout << "New retail price: " << tmpRetail << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving retail price ..." << endl;
                            bookInfo[i].setRetail(tmpRetail);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Retail price not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 9:
                        break;
                    default:
                        cout << "Please enter a number from the range of 1-9" << endl;

                }

                cout << "\033[2J\033[1;1H";
            }
        }

    }while(choice != 0 && bookCount < 20);

    return;
}

void editBook(string matcher, int &bookCount, vector<bookType> &bookInfo, const int DBSIZE)
{
    int choice;

    do
    {
        cout << "\033[2J\033[1;1H";

        // Use regex to check for dashes and digits, then select the option accordingly
        if (regex_match(matcher, regex("([0-9]{1,3})-([0-9]{3})-([0-9]{3})-([0-9]{1,}|[X])")))
        {
            cout << "ISBN detected" << endl;
            cout << "Editing by ISBN" << endl;
            cout << "Press Enter to continue..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cout << "Title detected" << endl;
            cout << "Editing by title" << endl;
            cout << "Press Enter to continue..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        // Use logic similar to that which I wrote into lookUpBook to find by title as well as an identical user interface to that found in addBook to perform the editing
        for (int i = 0; i < bookCount; i++)
        {
            if (bookInfo[i].getBookTitle() == matcher || bookInfo[i].getIsbn() == matcher)
            {
                cout << "\033[2J\033[1;1H";
                cout << endl << endl;
                //cout << setfill("█") << setw(80) << "#" << endl;
                cout << left;
                cout << "████████████████████████████████████████████████████████████████████████████████";
                cout << right << endl;
                cout << "█" << setw(53) << "SERENDIPITY  BOOKSELLERS"  << setw(25) << " " << "█" << endl;
                cout << "█" << setw(45) << "EDIT BOOK"                 << setw(33) << " " << "█" << endl;
                cout << "█" << setw(78) << " " << "█" << endl;
                cout << "█" << setw(45) << "DATABASE SIZE:"            << setw(4)  << "  20"
                            << setw(20) << "CURRENT BOOK COUNT:"       << setw(4)  << bookCount
                            << setw(5)  << " " << "█" << endl;
                cout << "█" << setw(78) << " " << "█" << endl;
                cout << "█" << setw(54) << "--PENDING VALUES"          << setw(24)  << " " << "█" << endl;
        
                cout << left;
        
                cout << "█"   << " "              << setw(34)                   << "<1> Update Book Title"              << ">  --"
                              << setw(38)         << bookInfo[i].getBookTitle() << "█" << endl;
                cout << "█"   << " "              << setw(34)                   << "<2> Update ISBN"                    << ">  --"
                              << setw(38)         << bookInfo[i].getIsbn()      << "█" << endl;
                cout << "█"   << " "              << setw(34)                   << "<3> Update Author"                  << ">  --"
                              << setw(38)         << bookInfo[i].getAuthor()    << "█" << endl;
                cout << "█"   << " "              << setw(34)                   << "<4> Update Publisher"               << ">  --"
                              << setw(38)         << bookInfo[i].getPublisher() << "█" << endl;
                cout << "█"   << " "              << setw(34)                   << "<5> Date Last Updated <mm/dd/yyyy>" << ">  --"
                              << setw(38)         << bookInfo[i].getDateAdded() << "█" << endl;
                cout << "█"   << " "              << setw(34)                   << "<6> Update Quantity on Hand"        << ">  --"
                              << setw(38)         << bookInfo[i].getQtyOnHand() << "█" << endl;
                cout << fixed << setprecision(2);
                cout << "█"   << " "              << setw(34)                   << "<7> Update Wholesale Cost"          << ">  --$"
                              << setw(37)         << bookInfo[i].getWholesale() << "█" << endl;
                cout << "█"   << " "              << setw(34)                   << "<8> Update Retail Price"            << ">  --$"
                              << setw(37)         << bookInfo[i].getRetail()    << "█" << endl;
                
                cout.unsetf(ios::fixed);
                cout << setprecision(6);
                cout << "█" << setw(1)  << " " << setw(36) << "<9> Return to Inventory Menu" << setw(41) << " " << "█" << endl;
        
                cout << "█" << setw(78) << " " << "█" << endl;
        
                cout << "████████████████████████████████████████████████████████████████████████████████";
                cout << endl;

                choice = intInputChecked("        Choice<1-9>", 1, 9);

                string tmpTitle = bookInfo[i].getBookTitle();
                string tmpIsbn = bookInfo[i].getIsbn();
                string tmpAuthor = bookInfo[i].getAuthor();
                string tmpPublisher = bookInfo[i].getPublisher();
                string tmpDateAdded = bookInfo[i].getDateAdded();
                int tmpQtyOnHand = bookInfo[i].getQtyOnHand();
                double tmpWholesale = bookInfo[i].getWholesale();
                double tmpRetail = bookInfo[i].getRetail();

                char save;

                switch(choice)
                {

                    case 1:
                        cout << "Enter Book Title: ";
                        getline(cin, tmpTitle);

                        cout << "New title: " << tmpTitle << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving title ..." << endl;
                            bookInfo[i].setBookTitle(tmpTitle);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Title not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 2:
                        cout << "Enter ISBN: ";
                        getline(cin, tmpIsbn);
                        
                        cout << "New ISBN: " << tmpIsbn << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving ISBN ..." << endl;
                            bookInfo[i].setBookTitle(tmpTitle);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "ISBN not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 3:
                        cout << "Enter Author: ";
                        getline(cin, tmpAuthor);
                        
                        cout << "New author: " << tmpAuthor << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving author ..." << endl;
                            bookInfo[i].setAuthor(tmpAuthor);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Author not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 4:
                        cout << "Enter Publisher: ";
                        getline(cin, tmpPublisher);
                        
                        cout << "New publisher: " << tmpPublisher << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving publisher ..." << endl;
                            bookInfo[i].setPublisher(tmpPublisher);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Publisher not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 5:
                        cout << "Enter Date Last Updated: ";
                        getline(cin, tmpDateAdded);

                        cout << "New date last updated: " << tmpDateAdded << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving date last updated ..." << endl;
                            bookInfo[i].setDateAdded(tmpDateAdded);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Date not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 6:
                        cout << "Enter Quantity on Hand: ";
                        cin >> tmpQtyOnHand;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        
                        cout << "New quantity on hand: " << tmpQtyOnHand << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving quantity on hand ..." << endl;
                            bookInfo[i].setQtyOnHand(tmpQtyOnHand);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Quantity on hand not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 7:
                        cout << "Enter Wholesale Cost: ";
                        cin  >> tmpWholesale;
                        
                        cout << "New wholesale cost: " << tmpWholesale << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving wholesale cost ..." << endl;
                            bookInfo[i].setWholesale(tmpWholesale);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Wholesale cost not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 8:
                        cout << "Enter Retail Price: ";
                        cin  >> tmpRetail;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        
                        cout << "New retail price: " << tmpRetail << endl;
                        cout << "Save (y/n)? ";
                        cin.get(save);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (save == 'y' || save == 'Y')
                        {
                            cout << "Saving retail price ..." << endl;
                            bookInfo[i].setRetail(tmpRetail);

                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else if (save == 'n' || save == 'N')
                        {
                            cout << "Retail price not saved" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }
                        else
                        {
                            cout << "Invalid input" << endl;
                            cout << "Press ENTER to continue ..." << endl;
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        }

                        cout << "\033[2J\033[1;1H";
                        break;
                    case 9:
                        break;
                    default:
                        cout << "Please enter a number from the range of 1-9" << endl;

                }

                cout << "\033[2J\033[1;1H";
            }
        }

    }while(choice != 0 && bookCount < 20);

    return;
}