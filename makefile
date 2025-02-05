run-test: invmenu.cpp
	g++ -std=c++20 -Wall -Werror -o run-test invmenu.cpp

clean:
	-rm *.o run-test
