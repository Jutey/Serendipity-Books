main-menu: mainmenu.cpp invmenu.o cashier.o reports.o addBook.o
	g++ -std=c++20 -Wall -Werror -o main-menu mainmenu.cpp invmenu.o cashier.o reports.o addBook.o
reports: reports.cpp
	g++ -std=c++20 -Wall -Werror -c reports.cpp
bookinfo: bookinfo.cpp
	g++ -std=c++20 -Wall -Werror -c bookinfo.cpp
invmenu: invmenu.cpp
	g++ -std=c++20 -Wall -Werror -c invmenu.cpp
cashier: cashier.cpp
	g++ -std=c++20 -Wall -Werror -c cashier.cpp
addbook: addBook.cpp
	g++ -std=c++20 -Wall -Werror -c addBook.cpp

clean:
	rm -f *.o run-test
