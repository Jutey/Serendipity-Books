run-test: mainmenu.cpp
	g++ -std=c++20 -Wall -Werror -o main-menu mainmenu.cpp

clean:
	-rm *.o run-test
