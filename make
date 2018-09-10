#!/bin/sh
g++ *.cpp
/usr/bin/time --quiet -f'\nTime %U. Exit %x. Memory %M.' ./a.out
