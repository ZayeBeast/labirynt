#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <dirent.h>
#include <fstream>
#include <conio.h>

using namespace std;

//struktury
typedef struct{int x; int y;} COORDS;

// zmienne globalne
string mapy="maps"; //folder, w którym są mapy
string file_name;   //ścieżka do mapy
string prev_file;   //nazwa poprzedniej mapy
#define SIZE 100
string mapa[SIZE], bufor[SIZE];
char user_ch='X', end_ch='O';

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

COORDS player_coords;
COORDS end_coords;

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
void targetcoords() { // bierze koordy celu/wyjścia i wrzuca do zmiennej
  end_coords = randomCoords();
}
bool isWall(int x, int y);  // czy na podanych kordach nie ma spacji
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
bool isWall(int coordx, int coordy)  // czy na podanych kordach nie ma spacji
{
    if (mapa[coordy][coordx] == ' ') //sprawdza czy space
        return false;                //zwraca, czy jest, czy nie
        else return true;
}
char drawOnBufor(int x, int y, char c); // narysuj na x i y znak c i zwróć poprzednie co tam było
void viewBufor(); // wypisz bufor na ekran
char getEvent(); // pobierz znak
void doEvent(); // wykonaj operację przypisaną do danego znaku (np WSAD)
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
        if(string(plik->d_name).size()>=4)
           if(string(plik->d_name).substr(string(plik->d_name).size()-4) == string(".map"))
                p1.push( plik->d_name );
        closedir( sciezka );
    }
    else
        throw "Nie udalo sie wylistowac katalogow";

   p1.sort();

   index = p1.search(prev_file);
   prev_file = p1.get(index+1);
    file_name = mapy+"/"+prev_file;
    if(prev_file == string (":"))
        {
         return false;
        }
    return true;
}


int main() {
    srand (time(NULL));
    try {
        while(getMap()) {
            beginingcoords();
            targetcoords();
            while(1) {
                refreshBufor();
                viewBufor();
                doEvent(getEvent());
                if(isEnd())
                    break;
            }
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

