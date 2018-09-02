#include <iostream>
#include <conio.h>

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
char getEvent()
    {
        return getch();
    }// pobierz znak
void doEvent(char c)
    {
        
        c = toupper(c);
        switch (c)
        {
            case'W':
            {
                if(isWall(coordx,coordy+1)==false)
                {    
                coordy++;
                }    
            }
            break;
            case'S':
            {
                if(isWall(coordx,coordy-1)==false)
                {    
                coordy--;
                }    
            }
            break;
            case 'A':
            {
                if(isWall(coordx-1,coordy)==false)
                {    
                coordx--;
                }    
            }
            break;
            case'D':
            {
                if(isWall(coordx+1,coordy)==false)
                {    
                coordx++;
                }    
            }
            break;
        }   
    
    }// wykonaj operację przypisaną do danego znaku (np WSAD)
bool isEnd(); // czy jesteśmy na kordach wyjścia
void doEnd(); // wykonaj animację wygranej i przerzuć do następnego pliku
int main() {
    return 69;
}
