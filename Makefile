main-menu: mainmenu.cpp bookType.o int_input_checked.o invmenu.o cashier.o reports.o addBook.o editBook.o lookUpBook.o
	g++ -std=c++20 -Wall -Werror -o main-menu mainmenu.cpp bookType.o int_input_checked.o invmenu.o cashier.o reports.o addBook.o editBook.o lookUpBook.o
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
lookupbook: lookUpBook.cpp
	g++ -std=c++20 -Wall -Werror -c lookUpBook.cpp
intinputchecked: int_input_checked.cpp
	g++ -std=c++20 -Wall -Werror -c int_input_checked.cpp
booktype: bookType.cpp
	g++ -std=c++20 -Wall -Werror -c bookType.cpp
editbook: editBook.cpp
	g++ -std=c++20 -Wall -Werror -c editBook.cpp
asm: mainmenu.cpp
	g++ -std=c++20 -Wall -Werror -S mainmenu.cpp
clean:
	rm -f *.o *.s main-menu
