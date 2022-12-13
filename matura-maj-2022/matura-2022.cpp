// Zapisz w pseudojęzyku lub wybranym języku programowania algorytm, który dla danego ciągu n dodatnich liczb całkowitych zapisanego w 
// tablicy A obliczy najmniejszą liczbę elementów, które trzeba w nim podmienić, aby otrzymać n-permutację.
// Uwaga: W zapisie algorytmu możesz korzystać tylko z instrukcji sterujących, operatorów arytmetycznych: 
// dodawania, odejmowania, mnożenia, dzielenia, dzielenia całkowitego i reszty z dzielenia; operatorów logicznych, porównań, 
// odwoływania się do pojedynczych elementów tablicy i instrukcji przypisania lub samodzielnie napisanych funkcji i procedur wykorzystujących powyższe operacje. 
// Zabronione jest używanie funkcji wbudowanych oraz operatorów innych niż wymienione, dostępnych w językach programowania.
// 
// n – dodatnia liczba całkowita
// A[1..n] – tablica n dodatnich liczb całkowitych, gdzie A[i] jest i-tym elementem ciągu
// Wynik:
// k – minimalna liczba elementów, które trzeba podmienić w ciągu
// zapisanym w tablicy A, aby otrzymać n-permutację
#include <iostream>
using namespace std;


int permutacja(int n, int A[]){
    int k = 0;
    int B[n];
    for (int i = 0; i < n ; i++) {
        B[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int a = A[i];
        if(a <= n) {
            B[a - 1] = B[a - 1] + 1; 
        } else {
            k++;
        }
    }

    for (int i = 1; i < n; i++) { 
        if( B[i] > 1 ) {
            k = k + B[i] - 1;
        }
    }

    return k;
}

int main() {
	int n = 10;
    int A[n];

    int B0[3] = {1, 3, 1}; // 1
    int B[4] = {1, 4, 2, 5}; //1
    int B1[5] = {2, 2, 2, 2, 2}; // 4
    int B2[4] = {4, 2, 3, 1}; // 0
    int B3[6] = {5, 4, 1, 5, 6, 8}; // 2
    int B4[6] = {8, 4, 9, 6, 5, 7}; // 3
    int C[5] = {1, 4, 2, 5, 4}; // pomysł pati

    cout << permutacja(3, B0) << endl;
    cout << permutacja(4, B) << endl;
    cout << permutacja(5, B1) << endl;
    cout << permutacja(4, B2) << endl;
    cout << permutacja(6, B3) << endl;
    cout << permutacja(6, B4) << endl;
}

