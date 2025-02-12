main-menu: mainmenu.cpp
	g++ -std=c++20 -Wall -Werror -o main-menu mainmenu.cpp
reports: reports.cpp
	g++ -std=c++20 -Wall -Werror -c reports.cpp
bookinfo: bookinfo.cpp
	g++ -std=c++20 -Wall -Werror -c bookinfo.cpp
invmenu: invmenu.cpp
	g++ -std=c++20 -Wall -Werror -c invmenu.cpp
cashier: cashier.cpp
	g++ -std=c++20 -Wall -Werror -c cashier.cpp

clean:
	rm -f *.o run-test
