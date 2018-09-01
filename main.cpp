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
    public:
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
    pojemnik p;
    p.push("a");
    p.push("b");
    p.push("c");
    p.push("d");
    cout<<p.search("d");
    p.set(1, "e");
    p.sort();
    cout<<p.cont();
    return 69;
}
