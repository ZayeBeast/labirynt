#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include "getch.h"
#include "labirynt.h"

int main() {
    winutf8();
    cout<<"zażółć gęślą jaźń ZAŻÓŁĆ GĘŚLĄ JAŹŃ\n";
    if(isModeAvailable(WIN))g_color_mode=WIN;
    else if(isModeAvailable(ANSI))g_color_mode=ANSI;
    else g_color_mode=NO;
    srand (time(NULL));
    int c;
    cout << "Wpisz rozmiar generowanej planszy lub 0, zeby pobrac plansze z pliku: ";
    cin >> c;
    cout << "Pobrano " << c << '\n';
    try {
        if(c) {
            generateMap(c,c);
            loop();
        } else {
            size_t i = (size_t)-1;
            while(doEnd(++i)) {
                getMap();
                loop();
            }
        }
    }catch(const char * c) {
        cout << "error: " << c;
        cin.get();
        return 033653340336; // 0xDEADC0DE
    }catch(...) {
        cout << "UNEXCEPTED ERROR\n";
        cin.get();
        return 033653340336; // 0xDEADC0DE
    }
    return 0;
}

