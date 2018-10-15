#!/bin/sh
g++ *.cpp
E=$?
echo GET $E
if [ "$1" != "o" ]; then
  /usr/bin/time --quiet -f'\nTime %U. Exit %x. Memory %M.' ./a.out
  if [ "$?" = "127" ]; then
    ./a.out
    echo "\nTime n/a. Exit $?. Memory n/a."
  fi
fi
exit $E
