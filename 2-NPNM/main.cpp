#include <iostream>
using namespace std;

int main() {
  
  int T[10]={33,21,23,27,27,28,2,13,24,32};
  int len=1, maxlen=1,idx,N=10;
  for (int i=1 ;i<N ; i++)
    if (T[i]>=T[i-1]) {
        len++;
        if (len>maxlen){
          maxlen=len;
          idx=i;
        }         
      }
      else 
        len=1;
    cout<<"Najdluzszy caig niemalejacy: ";
    cout<<"\nIlosc el: "<<maxlen<<endl;
    cout<<"Pierwszy element: "<<T[idx-maxlen+1];   
}