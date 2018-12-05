#!/bin/sh
if [ "$1" = "r" ]; then
  g++ *.cpp -Wall -fexceptions -Weffc++ -pedantic -Wextra -ansi -O3 -Werror
  E=$?
elif [ "$1" = "e" ]; then
  g++ *.cpp -Wall -fexceptions -Weffc++ -pedantic -Wextra -ansi -Og -g
  E=$?
else
  g++ *.cpp -Wall -fexceptions -Weffc++ -pedantic -Wextra -ansi -Og -g -Werror
  E=$?
fi
echo GET $E
if [ "$2" != "o" ]; then
  if [ "$E" = "0" ]; then
    if [ -e /usr/bin/time ]; then
      /usr/bin/time --quiet -f'\nTime %U. Exit %x. Memory %M.' ./a.out
    else
      ./a.out
      echo -e "\nTime n/a. Exit $?. Memory n/a."
    fi
  fi
fi
exit $E
