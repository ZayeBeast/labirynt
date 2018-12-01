#include "labirynt.h"
#include <ctime>
// zmienne globalne
string mapy="maps"; //folder, w którym są mapy
string file_name;   //ścieżka do mapy
string prev_file;   //nazwa poprzedniej mapy
size_t size_map=0;
string *bufor = NULL;
string buffor="0123456789";
vector<string> mapa;
char user_ch='X', end_ch='O';
COORDS player_coords;
COORDS end_coords;
string znak[4] = {"w","a","s","d"};

void getMap()
{
std::fstream file;
file.open(file_name.c_str(), ios::in);
if(file.good()==false)
{
    throw "File does not exist";

}
mapa.clear();
size_map = 0;
string line;
while (getline(file, line)) {
    mapa.push_back(line);
    ++size_map;
}
file.close();
}

bool isExist(COORDS p) { // sprawdza czy dane pole jest na mapie
  if(p.y>=size_map)return false;
  return mapa[p.y].size()>=p.x;
}

bool isWall(COORDS c)  // czy na podanych kordach nie ma spacji
{
    if(!isExist(c))return true;
    if (mapa[c.y][c.x] == ' ') //sprawdza czy space
        return false;                //zwraca, czy jest, czy nie
        else return true;
}
COORDS randomCoords(bool notWall) {
  COORDS c;
  do {
    c.y = rand() % size_map;
    size_t s = mapa[c.y].size();
    if(s) // s != 0
      c.x = rand() % s;
  }while((!isExist(c))||(notWall&&isWall(c)));
  return c;
}
void beginingcoords() { // bierze poczontkowe koordy i wrzuca do zmiennej
  player_coords = randomCoords();
}
void targetcoords() { // bierze koordy celu/wyjścia i wrzuca do zmiennej
   int rozmiar, rzmr;
    do{
        end_coords = randomCoords();
        rozmiar = sqrt(2*pow(mapa[0].size(),2))/2;
        rzmr = sqrt(pow((int)(player_coords.x-end_coords.x),2)+pow((int)(player_coords.y-end_coords.y),2));
        cout << rzmr << " "<< rozmiar << endl;
    }while (rzmr<rozmiar);
}

char get(COORDS c) {
    if(!isExist(c)) return '?';
    return mapa[c.y][c.x];
}
void set(COORDS c, char ch) {
    if(!isExist(c)) return;
    mapa[c.y][c.x] = ch;
}
void winutf8() {
    #if __WIN32
    CONSOLE_FONT_INFOEX cfi;
    HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hndl, false, &cfi);
    cfi.cbSize = sizeof cfi;
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 28;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(hndl, 0, &cfi);
    system("chcp 65001>nul");
    #endif // __WIN32
}

// generuje mapę o podanych w parametrach wymiarach oraz zapisuje ją w zmiennej mapa
void generateMap(size_t width, size_t height) {
  //src: https://gist.github.com/Nircek/7e1ee37e0bbc30f7ab554c633209a8d4/60b41682b6561b848b7d34ae338c9e8a9ca7ba6e#file-mazes-py-L75
  size_map = height;
  for(size_t i=0;i<height;++i)
    mapa.push_back(string(width, '#'));
  COORDS c = randomCoords(false);
  set(c,' ');
  size_t it = 0;
  while(1) {
    c = randomCoords(false);
    int n = 0;
    int ni = 0;
    for(int dx=-1;dx<=1;++dx)
      for(int dy=-1;dy<=1;++dy) {
        if(dx==0&&dy==0)
          continue;
        COORDS g = {c.x+dx,c.y+dy};
        if(get(g) == ' ') {
          ++n;
          if(dx==0||dy==0)
            ++ni;
        }
      }
    if(ni==1&&n<3) {
      if(get(c)!=' ')
        it=0;
      set(c,' ');
    } else {
      ++it;
      if(it>width*height*3)
        break;
    }
  }
}
void pobranie(int a)
{
            time_t koniec;
            char cos;
            bool b=false;
            znak[a]="";
            while(true)
        {
            cos=getch();
            if(!b)
            {
                koniec= time(NULL) + 1 ;
                b=true;
            }
            if (time(NULL)>=koniec) break;
            znak[a]+=cos;
        }
}

void calibrate() {
string napis[4];
    napis[0]="górę";
    napis[1]="lewo";
    napis[2]="dół";
    napis[3]="prawo";
        for(int i=0;i<4;i++)
        {
         cout<<"wciśnij strzałkę w "<<napis[i]<<", poczekaj 1s i potwierdź enterem"<<endl;
        pobranie(i);
        }
}
void zapisz()
    {
        for(int i=0;i<9;i++)
        {
            buffor[i]=buffor[i+1];
        }
        buffor[9]=getch();
        buffor=buffor.substr(0,10);
    }

int getEvent()
    {
        zapisz();
        if(buffor.substr(buffor.size()-znak[0].length()) == znak[0])
          return UP_ARROW_EVENT;
        if(buffor.substr(buffor.size()-znak[1].length()) == znak[1])
          return LEFT_ARROW_EVENT;
        if(buffor.substr(buffor.size()-znak[2].length()) == znak[2])
          return DOWN_ARROW_EVENT;
        if(buffor.substr(buffor.size()-znak[3].length()) == znak[3])
          return RIGHT_ARROW_EVENT;
        return NO_EVENT;
    }
void doEvent(int c) {
    COORDS n=player_coords;
    switch(c) {
        case UP_ARROW_EVENT: --n.y; break;
        case DOWN_ARROW_EVENT: ++n.y; break;
        case LEFT_ARROW_EVENT: --n.x; break;
        case RIGHT_ARROW_EVENT: ++n.x; break;

    }


    if(!isWall(n))
        player_coords = n;

}// wykonaj operację przypisaną do danego znaku (np WSAD)
char drawOnBufor(COORDS C, char c) { // narysuj na x i y znak c i zwróć poprzednie co tam było
  char oc = bufor[C.y][C.x];
  bufor[C.y][C.x] = c;
  return oc;
}
void refreshBufor() { // załaduj mapę do bufora i nanieś na nie usera i wyjście
  if(!bufor) delete[] bufor;
  bufor = new string[size_map];
  for(size_t i=0; i<size_map; ++i)
    bufor[i] = mapa[i];
  drawOnBufor(player_coords, user_ch);
  drawOnBufor(end_coords, end_ch);
}
void clear_screen() {
  if(system(NULL)) // sprawdzanie czy konsola dostępna
    if(system("CLS")) // sprawdzanie czy komenda CLS zadziałała
      if(system("clear"))
        cout << string(0xFF, '\n');
}
void viewBufor() { // wypisz bufor na ekran
  clear_screen();
  for(size_t i=0;i<size_map;++i) {
    for(size_t j=0;j<bufor[i].size();++j) {
      if(player_coords.x==j&&player_coords.y==i)
        setColor(RED, BG);
      if(end_coords.x==j&&end_coords.y==i)
        setColor(GREEN, BG);
      cout << bufor[i][j];
      setColor(BLACK, BG);
    }
  cout << '\n';
  }
}
bool isEnd() {// czy jesteśmy na kordach wyjścia
    if  ((player_coords.x== end_coords.x) && (player_coords.y==end_coords.y))
                    return true;
                    else return false;
                }
#include "pojemnik.h"
void animate() {
  cout<<"Udało Ci się przejść mapę \""<<prev_file<<"\".\n\nNaciśnij dowolny przycisk, żeby zagrać w następną...";
  getch();
}
bool doEnd(bool animation) {                  // wykonaj animację wygranej i przerzuć do następnego pliku
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

void loop() {
    beginingcoords();
    targetcoords();
    while(1) {
        refreshBufor();
        viewBufor();
        doEvent(getEvent());
        if(isEnd())
            break;
    }
}
