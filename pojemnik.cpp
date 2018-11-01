/*
MIT License

Copyright (c) 2018 Nircek

Permission is hereby granted free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "pojemnik.h"
int pojemnik::part(int l, int r){
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
void pojemnik::sort(int l, int r) {
    // QuickSort
    if(r==-1)r=len()-1;
    int q;
    if (l < r) {
        q = part(l, r);
        sort(l, q);
        sort(q+1, r);
    }
}
size_t pojemnik::len() {
    size_t i = 0;   // koniec wyszukanego elementu
    size_t x = 0;   // id wyszukanego elementu
    while((i=s.find(";", i)+1))++x;
    return x;
}
void pojemnik::push(string ns) {
    s +=  ns + ";";
}
void pojemnik::set(size_t ix, string ns) {//zwraca ":" jeżeli nie ma elementu o takim ID
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
size_t pojemnik::search(string q) {
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
string pojemnik::get(size_t ix) {//zwraca ":" jeżeli nie ma elementu o takim ID
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
string pojemnik::cont() {
    return s;
}
