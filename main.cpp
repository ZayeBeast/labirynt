#include <iostream>

using namespace std;

// zmienne globalne
string mapa[100];
int coordx, coordy;
int endcoordx, endcoordy;
char user='X';
string file_name="plik";

// procedury
void getMap(); // wczytuje mapę z pliku file_name i zapisuje do mapa[]
void beginingcoords(); // bierze poczontkowew koordy i wrzuca do zmiennej
void targetcoords(); // bierze koordy celu/wyjścia i wrzuca do zmiennej
bool isWall(int x, int y);  // czy na podanych kordach nie ma spacji
char drawOnBufor(int x, int y, char c); // narysuj na x i y znak c i zwróć poprzednie co tam było
void viewBufor(); // wypisz bufor na ekran
char getEvent(); // pobierz znak
void doEvent(); // wykonaj operację przypisaną do danego znaku (np WSAD)
bool isEnd(); // czy jesteśmy na kordach wyjścia
class pojemnik {
    string s;
    public:
    void sort() {

    }
    void push(string ns) {
        s += ns + ";";
    }
    size_t search(string) {

    }
    string get(size_t) {//zwraca ":" jeżeli nie ma elementu o takim ID

    }
};
bool doEnd() { // wykonaj animację wygranej i przerzuć do następnego pliku
    //TODO: MrDarkness19: stworzenie nowego obiektu pojemnika
    //TODO: MrDarkness19: wrzucanie kolejnych nazw plików (tylko z rozszerzeniem .map!!!)
    //                    za pomocą funkcji pojemnik::push()
    //TODO: MrDarkness19: przesortowanie tego obiektu za pomocą funkcji pojemnik::sort()
    //TODO: MrDarkness19: znalezienie w pojemniku aktualnie otwartej mapy w pojemniku
    //TODO: MrDarkness19: ustawienie aktualnie otwartej mapy na następną
    //TODO: Nircek: animacja
    //TODO: MrDarkness19: jeżeli się nie udało to zwróć false
    //TODO: MrDarkness19: a jak wszystko ok to zwróć true
}
int main() {
    return 69;
}
