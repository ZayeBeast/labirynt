#!/bin/sh
g++ *.cpp
E=$?
echo GET $E
if [ "$1" != "o" ]; then
  /usr/bin/time --quiet -f'\nTime %U. Exit %x. Memory %M.' ./a.out
fi
exit $E
