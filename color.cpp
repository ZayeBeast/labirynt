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
    if(g_color_mode==NO)
        return;
    if(g_color_mode==ANSI) {
        bool b=false, bs=(s==FG);
        char cc;
        string cs;
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
        switch(bs&(b<<1)) {
            case 0b00: cs="3";  break;
            case 0b01: cs="4";  break;
            case 0b10: cs="9";  break;
            case 0b11: cs="10"; break;
        }
        cout<<"\33["<<cs<<cc<<'m';
    }
}

