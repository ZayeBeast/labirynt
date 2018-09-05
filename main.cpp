#include <iostream>

using namespace std;

//struktury
typedef struct{int x; int y;} COORDS;

// zmienne globalne
string mapa[100];
COORDS player_coords;
COORDS end_coords;
char user='X';
string file_name="plik";

// procedury
void getMap(); // wczytuje mapę z pliku file_name i zapisuje do mapa[]
bool isExist(COORDS p) { // sprawdza czy dane pole jest na mapie
  if(p.y>=SIZE)return false;
  return mapa[p.y].size()>=p.x;
}
COORDS randomCoords(bool notWall=true) {
  COORDS c;
  do {
    c.y = rand() % SIZE;
    size_t s = mapa[c.y].size();
    if(s) // s != 0
      c.x = rand() % s;
  }while(!(isExist(c)&&((!notWall)||isWall(c))));
  return c;
}
void beginingcoords(); // bierze poczontkowew koordy i wrzuca do zmiennej
void targetcoords(); // bierze koordy celu/wyjścia i wrzuca do zmiennej
bool isWall(int x, int y);  // czy na podanych kordach nie ma spacji
char drawOnBufor(int x, int y, char c); // narysuj na x i y znak c i zwróć poprzednie co tam było
void viewBufor(); // wypisz bufor na ekran
char getEvent(); // pobierz znak
void doEvent(); // wykonaj operację przypisaną do danego znaku (np WSAD)
bool isEnd(); // czy jesteśmy na kordach wyjścia
void doEnd(); // wykonaj animację wygranej i przerzuć do następnego pliku

int main() {
    return 69;
}
