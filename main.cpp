#include <iostream>

using namespace std;

// zmienne globalne
#define SIZE 100
string mapa[SIZE], bufor[SIZE];
int coordx, coordy;
int endcoordx, endcoordy;
char user_ch='X', end_ch='O';
string file_name="plik";

// procedury
void getMap(); // wczytuje mapę z pliku file_name i zapisuje do mapa[]
void beginingcoords(); // bierze poczontkowew koordy i wrzuca do zmiennej
void targetcoords(); // bierze koordy celu/wyjścia i wrzuca do zmiennej
bool isWall(int x, int y);  // czy na podanych kordach nie ma spacji
void refreshBufor() { // załaduj mapę do bufora i nanieś na nie usera i wyjście
  for(size_t i=0; i<SIZE; ++i)
    bufor[i] = mapa[i];
  drawOnBufor(coordx, coordy, user_ch);
  drawOnBufor(endcoordx, endcoordy, end_ch);
}
char drawOnBufor(int x, int y, char c) { // narysuj na x i y znak c i zwróć poprzednie co tam było
  char oc = mapa[y][x];
  mapa[y][x] = c;
  return oc;
}
void viewBufor() { // wypisz bufor na ekran
  if(system(NULL)) // sprawdzanie czy konsola dostępna
    if(system("CLS")) // sprawdzanie czy komenda CLS zadziałała
      if(system("clear"))
        cout << string('\n',0xFF);
  for(size_t i=0;i<SIZE;++i)
    if(mapa[i].size()>0)
      cout << mapa[i] << '\n';
}
char getEvent(); // pobierz znak
void doEvent(); // wykonaj operację przypisaną do danego znaku (np WSAD)
bool isEnd(); // czy jesteśmy na kordach wyjścia
void doEnd(); // wykonaj animację wygranej i przerzuć do następnego pliku
int main() {
    return 69;
}
