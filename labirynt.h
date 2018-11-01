#ifndef _GH_NIRCEK_LABIRYNT_LABIRYNT_H_
#define _GH_NIRCEK_LABIRYNT_LABIRYNT_H_

#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <dirent.h>
#include <fstream>
#include <cmath>
#include <vector>
#include "getch.h"
#include "color.h"

using namespace std;

//struktury
typedef struct{size_t x; size_t y;} COORDS;

// zmienne globalne
extern string mapy; //folder, w którym są mapy
extern string file_name;   //ścieżka do mapy
extern string prev_file;   //nazwa poprzedniej mapy
extern size_t SIZE;
extern string *bufor;
extern vector<string> mapa;
extern char user_ch, end_ch;
extern COORDS player_coords;
extern COORDS end_coords;

// procedury
void getMap();
bool isExist(COORDS); // sprawdza czy dane pole jest na mapie
bool isWall(COORDS);  // czy na podanych kordach nie ma spacji
COORDS randomCoords(bool notWall=true);
void beginingcoords(); // bierze poczontkowe koordy i wrzuca do zmiennej
void targetcoords(); // bierze koordy celu/wyjścia i wrzuca do zmiennej
char get(COORDS);
void set(COORDS, char);
void generateMap(size_t width=SIZE, size_t height=SIZE); // generuje mapę o podanych w parametrach wymiarach oraz zapisuje ją w zmiennej mapa
char getEvent(); //pobierz znak
void doEvent(char); // wykonaj operację przypisaną do danego znaku (np WSAD)
char drawOnBufor(COORDS, char); // narysuj na x i y znak c i zwróć poprzednie co tam było
void refreshBufor(); // załaduj mapę do bufora i nanieś na nie usera i wyjście
void viewBufor(); // wypisz bufor na ekran
bool isEnd(); // czy jesteśmy na kordach wyjścia
void animate();
bool doEnd(bool animation=true); // wykonaj animację wygranej i przerzuć do następnego pliku
void loop();
#endif

