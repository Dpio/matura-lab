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

string cezar(string wsad, int k){
  int indx;
  for (int i=0 ; i<wsad.size() ; i++) {
    indx = (findChar(wsad[i])+k)%26;
    wsad[i]=alfabet[indx];
    }
  return wsad;
}

int main() {
  string wsad="abcdefxyz";
  cout<<cezar(wsad,27); 
}