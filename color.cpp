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
        if(c=='n'||c=='N')return true;
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

}

