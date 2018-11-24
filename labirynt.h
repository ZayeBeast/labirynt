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
#if _WIN32
#include <windows.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef struct _CONSOLE_FONT_INFOEX {
  ULONG cbSize;
  DWORD nFont;
  COORD dwFontSize;
  UINT  FontFamily;
  UINT  FontWeight;
  WCHAR FaceName[LF_FACESIZE];
} CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;
BOOL WINAPI GetCurrentConsoleFontEx(HANDLE, BOOL, PCONSOLE_FONT_INFOEX);
BOOL WINAPI SetCurrentConsoleFontEx(HANDLE, BOOL, PCONSOLE_FONT_INFOEX);
#ifdef __cplusplus
}
#endif
#endif

using namespace std;

//struktury
typedef struct{int x; int y;} COORDS;

//definicje
#define NO_EVENT            0
#define UP_ARROW_EVENT      1
#define DOWN_ARROW_EVENT    2
#define LEFT_ARROW_EVENT    3
#define RIGHT_ARROW_EVENT   4

// zmienne globalne
extern string mapy; //folder, w którym są mapy
extern string file_name;   //ścieżka do mapy
extern string prev_file;   //nazwa poprzedniej mapy
extern size_t size_map;
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
void calibrate(); //kalibracja klawiszy strzałek
void winutf8();
void generateMap(size_t width=size_map, size_t height=size_map); // generuje mapę o podanych w parametrach wymiarach oraz zapisuje ją w zmiennej mapa
char getEvent(); //pobierz znak
void doEvent(char); // wykonaj operację przypisaną do danego znaku (np WSAD)
char drawOnBufor(COORDS, char); // narysuj na x i y znak c i zwróć poprzednie co tam było
void refreshBufor(); // załaduj mapę do bufora i nanieś na nie usera i wyjście
void clear_screen();
void viewBufor(); // wypisz bufor na ekran
bool isEnd(); // czy jesteśmy na kordach wyjścia
void animate();
bool doEnd(bool animation=true); // wykonaj animację wygranej i przerzuć do następnego pliku
void loop();
#endif

