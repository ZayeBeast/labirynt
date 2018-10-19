#include "color.h"
#ifdef _WIN32
#include <windows.h>
#endif
color_mode g_color_mode;
bool ansichecked, ansiavailable;
void testansi() {
    
}
bool isModeAvailable(color_mode cm) {
    switch(cm) {
        case NO:
            return true;
        case ANSI:
            if(ansichecked)
                return ansiavailable;
            testansi();
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

