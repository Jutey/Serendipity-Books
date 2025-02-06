main-menu: mainmenu.cpp
        g++ -std=c++20 -Wall -Werror -o main-menu mainmenu.cpp
reports: reports.cpp
        g++ -std=c++20 -Wall -Werror -o reports reports.cpp
bookinfo: bookinfo.cpp
        g++ -std=c++20 -Wall -Werror -o bookinfo bookinfo.cpp
invmenu: invmenu.cpp
        g++ -std=c++20 -Wall -Werror -o invmenu invmenu.cpp

clean:
        -rm *.o run-test
