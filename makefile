main-menu: mainmenu.cpp
	g++ -std=c++20 -Wall -Werror -o main-menu mainmenu.cpp
reports: reports.cpp
	g++ -std=c++20 -Wall -Werror -o main-menu reports.cpp

clean:
	-rm *.o run-test
