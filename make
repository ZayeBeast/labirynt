#!/bin/sh
if [ "$1" = "r" ]; then
  g++ *.cpp -Wall -fexceptions -O3
  E=$?
else
  g++ *.cpp -Wall -fexceptions -Weffc++ -pedantic -Wfatal-errors -Wextra -Wall -ansi -Og -g
  E=$?
fi
echo GET $E
if [ "$1" != "o" ]; then
  if [ "$E" = "0" ]; then
    /usr/bin/time --quiet -f'\nTime %U. Exit %x. Memory %M.' ./a.out
    if [ "$?" = "127" ]; then
      ./a.out
      echo "\nTime n/a. Exit $?. Memory n/a."
    fi
  fi
fi
exit $E
