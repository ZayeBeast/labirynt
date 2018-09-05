#include <iostream>

using namespace std;

// zmienne globalne
#define SIZE 100
string mapa[SIZE], bufor[SIZE];
int coordx, coordy;
int endcoordx, endcoordy;
char user='X';
string file_name="plik";

// procedury
void getMap(); // wczytuje mapę z pliku file_name i zapisuje do mapa[]
void beginingcoords(); // bierze poczontkowew koordy i wrzuca do zmiennej
void targetcoords(); // bierze koordy celu/wyjścia i wrzuca do zmiennej
bool isWall(int x, int y);  // czy na podanych kordach nie ma spacji
void refreshBufor() { // załaduj mapę do bufora
  for(size_t i=0; i<SIZE; ++i)
    bufor[i] = mapa[i];
}
char drawOnBufor(int x, int y, char c) { // narysuj na x i y znak c i zwróć poprzednie co tam było
  char oc = mapa[y][x];
  mapa[y][x] = c;
  return oc;
}
void viewBufor(); // wypisz bufor na ekran
char getEvent(); // pobierz znak
void doEvent(); // wykonaj operację przypisaną do danego znaku (np WSAD)
bool isEnd(); // czy jesteśmy na kordach wyjścia
void doEnd(); // wykonaj animację wygranej i przerzuć do następnego pliku
int main() {
    mapa[0] = "abcd";
    refreshBufor();
    mapa[0] = "";
    cout << bufor[0];
    return 69;
}
