#include "getch.h"
/*
MIT License

Copyright (c) 2018 Nircek

Permission is hereby granted free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// code from https://gist.github.com/Nircek/c8b104456e6c68068866425072a0863f
// under MIT license
#include <iostream>
#ifndef _WIN32
#include <unistd.h>
#include <termios.h>
char getch(){
    // src: https://stackoverflow.com/a/16361724/6732111
    char buf=0;
    struct termios old;
    std::cout.flush();
    if(tcgetattr(0, &old)<0)
        throw "tcsetattr()";
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        throw "tcsetattr ICANON";
    if(read(0,&buf,1)<0)
        throw "read()";
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        throw "tcsetattr ~ICANON";
    return buf;
 }
#endif
