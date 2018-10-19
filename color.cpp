#include "color.h"
//TODO: #include "getch.h"
#include <iostream>
using namespace std;
#ifdef _WIN32
#include <windows.h>
#endif
color_mode g_color_mode=NO;
bool ansichecked=false, ansiavailable=false;
bool testansi() {
    cout<<"Czy widzisz tekst ponizej na czerwono [t, n]?\n\n\33[31mprzykladowy tekst\33[0m\n\n";
    ansichecked=true;
    while(1) {
        char c;//TODO: getch();
        cin>>c;
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
}
void setColor(color c, surface s) {
    bool b=false, bs=(s==FG);
    char cc;
    string cs;
    switch(g_color_mode) {
        case NO:
            return;
            break;
        case ANSI:
            switch(c) {
                case BBLACK:    b=true; case BLACK:    cc='0'; break;
                case BRED:      b=true; case RED:      cc='1'; break;
                case BGREEN:    b=true; case GREEN:    cc='2'; break;
                case BYELLOW:   b=true; case YELLOW:   cc='3'; break;
                case BBLUE:     b=true; case BLUE:     cc='4'; break;
                case BMAGENTA:  b=true; case MAGENTA:  cc='5'; break;
                case BCYAN:     b=true; case CYAN:     cc='6'; break;
                case BWHITE:    b=true; case WHITE:    cc='7'; break;
            }
            switch((!bs)|(b<<1)) {
                case 0b00: cs="3";  break;
                case 0b01: cs="4";  break;
                case 0b10: cs="9";  break;
                case 0b11: cs="10"; break;
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

