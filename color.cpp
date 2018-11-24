/*
MIT License

Copyright (c) 2018 Nircek

Permission is hereby granted, free of charge, to any person obtaining a copy
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
#include "color.h"
#include "getch.h"
#include <iostream>
using namespace std;
#ifdef _WIN32
#include <windows.h>
#endif
color_mode g_color_mode=NO;
bool ansichecked=false, ansiavailable=false;
bool testansi() {
    cout<<"Czy poniższy tekst wyświetla Ci się na czerwono? [t, n]\n\n\33[31mprzykładowy tekst\33[0m\n\n";
    ansichecked=true;
    while(1) {
        char c = getch();
        if(c=='t'||c=='T')return true;
        if(c=='n'||c=='N')return false;
    }
}
bool isModeAvailable(color_mode cm) {
    switch(cm) {
        case NO:
            return true;
        case ANSI:
            if(ansichecked)
                return ansiavailable;
            ansiavailable = testansi();
            return ansiavailable;
        case WIN:
            #ifdef _WIN32
            return true;
            #else
            return false;
            #endif
    }
    return false;
}
void setColor(color c, surface s) {
    bool b=false, bs=(s==FG);
    char cc='0';
    string cs;
    switch(g_color_mode) {
        case NO:
            return;
            break;
        case ANSI:
            switch(c) {
                case BBLACK:    b=true; /*FALLTHRU*/case BLACK:    cc='0'; break;
                case BRED:      b=true; /*FALLTHRU*/case RED:      cc='1'; break;
                case BGREEN:    b=true; /*FALLTHRU*/case GREEN:    cc='2'; break;
                case BYELLOW:   b=true; /*FALLTHRU*/case YELLOW:   cc='3'; break;
                case BBLUE:     b=true; /*FALLTHRU*/case BLUE:     cc='4'; break;
                case BMAGENTA:  b=true; /*FALLTHRU*/case MAGENTA:  cc='5'; break;
                case BCYAN:     b=true; /*FALLTHRU*/case CYAN:     cc='6'; break;
                case BWHITE:    b=true; /*FALLTHRU*/case WHITE:    cc='7'; break;
            }
            switch((!bs)|(b<<1)) {
                /*0b00*/case 0: cs="3";  break;
                /*0b01*/case 1: cs="4";  break;
                /*0b10*/case 2: cs="9";  break;
                /*0b11*/case 3: cs="10"; break;
            }
            cout<<"\33["<<cs<<cc<<'m';
            break;
        case WIN:
            #ifdef _WIN32
            WORD a;
            CONSOLE_SCREEN_BUFFER_INFO info;
            if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
                a = 0;
            else
                a = info.wAttributes;
            const WORD allFG = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED;
            const WORD allBG = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_RED;
            a &= bs?(~allFG):(~allBG);
            short i=bs?FOREGROUND_INTENSITY:BACKGROUND_INTENSITY,
            r=bs?FOREGROUND_RED:BACKGROUND_RED,
            g=bs?FOREGROUND_GREEN:BACKGROUND_GREEN,
            b=bs?FOREGROUND_BLUE:BACKGROUND_BLUE;
            switch(c) {
                case BBLACK:   a|=i; case BLACK:   a|=0;    break;
                case BRED:     a|=i; case RED:     a|=r;    break;
                case BGREEN:   a|=i; case GREEN:   a|=g;    break;
                case BYELLOW:  a|=i; case YELLOW:  a|=r|g;  break;
                case BBLUE:    a|=i; case BLUE:    a|=b;    break;
                case BMAGENTA: a|=i; case MAGENTA: a|=r|b;  break;
                case BCYAN:    a|=i; case CYAN:    a|=g|b;  break;
                case BWHITE:   a|=i; case WHITE:   a|=r|g|b;break;
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
            #endif
            break;
    }
}

