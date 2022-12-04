#include <iostream>
using namespace std;

string alfabet="abcdefghijklmnopqrstuvwxyz";

int findChar(char z) {
  z=tolower(z);
  for (int i=0;i<alfabet.size();i++)
    if (z==alfabet[i])
        return i;
  return -1;
}

string kodKlucz(string wsad, string klucz){
  int indx;
  int indxKlucz=0;
  for (int i=0 ; i<wsad.size() ; i++) {
    indx = (findChar(wsad[i]) + findChar(klucz[indxKlucz++]) ) %26;
    wsad[i]=alfabet[indx];
    if (indxKlucz>=klucz.size())
      indxKlucz=0;
    }
  return wsad;
}

int main() {
  string wsad="abcdefxyz";
  cout << kodKlucz(wsad,"ab");  
}