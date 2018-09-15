#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <dirent.h>
#include <fstream>
#include <conio.h>

using namespace std;

// zmienne globalne
string mapa[100];
string bufor[100];
int coordx, coordy;
int endcoordx, endcoordy;
char user='X';
string mapy="maps"; //folder, w którym są mapy
string file_name;   //ścieżka do mapy
string prev_file;   //nazwa poprzedniej mapy

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
class pojemnik {
    string s;
    int part(int l, int r){
        string x = get(l);
        int i = l, j = r;
        string w;
        while(1) {
            while (get(j) > x)j--;
            while (get(i) < x)i++;
            if (i<j) {
                w = get(i);
                set(i, get(j));
                set(j, w);
                i++;
                j--;
            }
            else return j;
        }
    }
    public:
    void sort(int l=0, int r=-1) {
        // QuickSort
        if(r==-1)r=len()-1;
        int q;
        if (l < r) {
            q = part(l, r);
            sort(l, q);
            sort(q+1, r);
        }
    }
    size_t len() {
        size_t i = 0;   // koniec wyszukanego elementu
        size_t x = 0;   // id wyszukanego elementu
        while((i=s.find(";", i)+1))++x;
        return x;
    }
    void push(string ns) {
        s +=  ns + ";";
    }
    void set(size_t ix, string ns) {//zwraca ":" jeżeli nie ma elementu o takim ID
        size_t i = 0;   // koniec wyszukanego elementu
        size_t j = 0;   // początek wyszukanego elementu
        size_t x = 0;   // id wyszukanego elementu
        while((i=s.find(";", i)+1)) {
            if(ix==x) {
                s=s.substr(0,j)+ns+s.substr(i-1);
                break;
            }
            ++x;
            j=i;
        }
    }
    size_t search(string q) {
        size_t i = 0;   // koniec wyszukanego elementu
        size_t j = 0;   // początek wyszukanego elementu
        size_t x = 0;   // id wyszukanego elementu
        while((i=s.find(";", i)+1)) {
            string ns = s.substr(j,i-j-1);//wyszukany element
            if(q==ns) return x;
            ++x;
            j=i;
        }
        return -1;
    }
    string get(size_t ix) {//zwraca ":" jeżeli nie ma elementu o takim ID
        size_t i = 0;   // koniec wyszukanego elementu
        size_t j = 0;   // początek wyszukanego elementu
        size_t x = 0;   // id wyszukanego elementu
        while((i=s.find(";", i)+1)) {
            if(ix==x) {
                return s.substr(j,i-j-1);
            }
            ++x;
            j=i;
        }
        return ":";
    }
    string cont() {
        return s;
    }
};
void animate() {

}
bool doEnd(bool animation=true) {                  // wykonaj animację wygranej i przerzuć do następnego pliku

   size_t index;
   if(animation)
     animate();
   pojemnik p1;
       struct dirent * plik;
    DIR * sciezka;

    if(( sciezka = opendir( mapy.c_str() ) ) ) {
        while(( plik = readdir( sciezka ) ) )
           if(string(plik->d_name).substr(string(plik->d_name).size()-3) == string(".map"))
                p1.push( plik->d_name );
        closedir( sciezka );
    }
    else
        throw "Nie udalo sie wylistowac katalogow";

   p1.sort();

   index = p1.search(prev_file);
   prev_file = p1.get(index+1);
    file_name = mapy+"/"+prev_file;
    if(index==(size_t)-1)
        {
         return false;
        }
    return true;
}


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
