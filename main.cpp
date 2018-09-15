#include <iostream>
<<<<<<< HEAD
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

=======
#include <fstream>
#include <cstdlib>
>>>>>>> origin/getmap()-by-pan-ciemność
using namespace std;

// zmienne globalne
string mapa[100];
string bufor[100];
int coordx, coordy;
int endcoordx, endcoordy;
char user='X';
string file_name="plik";

// procedury
void beginingcoords()
{   do{
            coordx = rand() % 100 + 1;
            coordy = rand() % 100 + 1;
        }while (isWall(coordx, coordy));
 
    } // bierze poczontkowew koordy i wrzuca do zmiennej
void getMap()
{
std::fstream file;
file.open(file_name, ios::in);

if(file.good()==false)
{
    throw "File does not exist";
   
}
string line;
i=0;
while (getline(file, line))
{        
    mapa[i] = line;
    i++;
}

file.close();
}



void targetcoords(); // bierze koordy celu/wyjścia i wrzuca do zmiennej
bool isWall(int x, int y);  // czy na podanych kordach nie ma spacji
char drawOnBufor(int x, int y, char c); // narysuj na x i y znak c i zwróć poprzednie co tam było
void refreshBufor(); // stwórz bufor
void viewBufor(); // wypisz bufor na ekran
char getEvent(); // pobierz znak
void doEvent(); // wykonaj operację przypisaną do danego znaku (np WSAD)
bool isEnd(); // czy jesteśmy na kordach wyjścia
void doEnd(); // wykonaj animację wygranej i przerzuć do następnego pliku
int main() {
    srand (time(NULL));
    try {
        getMap();
        beginingcoords();
        targetcoords();
        while(1) {
            refreshBufor();
            viewBufor();
            doEvent(getEvent());
            if(isEnd())
                doEnd();
        }
    }catch(const char * c) {
        cout << "error: " << c;
        cin.get()
        return 033653340336; // 0xDEADC0DE
    }catch(...) {
        cout << "UNEXCEPTED ERROR\n";
        cin.get();
        return 033653340336; // 0xDEADC0DE
    }
    return 0;
}
