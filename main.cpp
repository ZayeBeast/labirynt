#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include "getch.h"
#include "labirynt.h"

#define DEBUG false

int main() {
    size_t wybor;
    try {
        if(DEBUG) {
            cout << "type \'c\' to break\n";
            char ch;
            while(1) {
              ch=getch();
              if(ch=='c')break;
              cout<<(unsigned int)ch<<' ';
            }
        }
        calibrate();//TODO: wsadzić to do menu
        if(DEBUG) {
            cout<<"Naciskaj kolejne klawisze strzalek, zeby przetestowac kalibracje.\n";
            while(1) {
                cout<<getEvent()<<' ';
            }
        }
        if(isModeAvailable(WIN))g_color_mode=WIN;
        else if(isModeAvailable(ANSI))g_color_mode=ANSI;
        else g_color_mode=NO;
        srand (time(NULL));
        do{
            clear_screen();

    cout<<"Witaj w naszej amatorskiej grze \"Labirynt\"."<<endl<<endl<<endl;
    cout<<"+---------MENU---------+"                   <<endl;
    cout<<"| Wybierz:             |"                   <<endl;
    cout<<"| 1. - Kampania        |"                   <<endl;
    cout<<"| 2. - Losowa mapa     |"                   <<endl;
    cout<<"| 3. - Wyswietl Tworcow|"                   <<endl;
    cout<<"+----------------------+"                   <<endl;

    cout<<"Wybieram: ";
    cin>>wybor;
    if(wybor==2)
    {
        size_t cordy1, cordy2;
        cout<<"Wybierz rozmiar mapy: "<<endl;
        cout<<"Podaj szerokosc: ";cin>>cordy1;
        cout<<"Podaj wysokosc: ";cin>>cordy2;
        generateMap(cordy1,cordy2);
        loop();
    }
    else if(wybor==1)
    {
            size_t i = (size_t)-1;
            while(doEnd(++i)) {
                getMap();
                loop();
            }

    }
    else if(wybor==3)
    {
        cout << "Nircek aka Mrcc Znepva" << endl;
        cout << "MrDarkness19"           << endl;
        cout << "Crackenhoff"            << endl;
        cout << "GummyBear"              << endl;
        cout << "IgorBia"                << endl;
    }

    else
    {
        cout<<"Nie znaleziono takiej opcji..."<<endl;
        getch();
    }

    }while(wybor!=1&&wybor!=2&&wybor!=3);
    return 0;
        }catch(const char * c) {
        cout << "error: " << c;
        cin.get();
        return 033653340336; // 0xDEADC0DE
    }catch(...) {
        cout << "UNEXCEPTED ERROR\n";
        cin.get();
        return 033653340336; // 0xDEADC0DE
    }

}
