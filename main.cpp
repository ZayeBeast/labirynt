#include <iostream>

using namespace std;

// zmienne globalne
string mapa[100];
int coordx, coordy;
int endcoordx, endcoordy;
char user='X';
string mapy="maps"; //folder, w którym są mapy
string file_name;   //ścieżka do mapy
string prev_file;   //nazwa poprzedniej mapy

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
    void sort() {

    }
    void push(string) {

    }
    size_t search(string) {

    }
    string get(size_t) {//zwraca ":" jeżeli nie ma elementu o takim ID

    }
};
bool doEnd() {                  // wykonaj animację wygranej i przerzuć do następnego pliku
   string plik;
   size_t index;
    
   pojemnik p1;                      
       struct dirent * plik;
    DIR * sciezka;

    if(( sciezka = opendir( mapy ) ) ) {
        while(( plik = readdir( sciezka ) ) )
             p1.push( plik->d_name );

        closedir( sciezka );
    }
    else
        throw "Nie udalo sie wylistowac katalogow";              
                                
   p1.sort();                  
    
   index = p1.search(plik)
   prev_file = p1.get(index+1);   
    file_name = mapy+"/"+prev_file;
    if(index==-1)
        {
         return false;
        }        
    return true;
        


int main() {
    return 69;
}
