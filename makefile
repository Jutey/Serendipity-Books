run-test: mainmenu.cpp
	g++ -std=c++20 -Wall -Werror -o run-test mainmenu.cpp

clean:
	-rm *.o run-test
