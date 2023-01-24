// Uzupełnij luki oznaczone poziomymi kreskami w poniższym algorytmie sita Eratostenesa –
// algorytmie wyznaczania wszystkich liczb pierwszych nie większych od zadanej liczby
// całkowitej N > 1.
// Specyfikacja
// Dane:
//  N – liczba całkowita większa od 1
// Wynik:
//  SITO[1..N] – tablica logiczna taka, że dla i = 1, 2, …, N, SITO[ i ] = PRAWDA, gdy i jest
// liczbą pierwszą, natomiast SITO[ i ] = FAŁSZ, gdy i jest liczbą złożoną
// Algorytm
// SITO[1] ← FAŁSZ
// dla i = 2, 3, …, N
// SITO[ i ] ← PRAWDA
// dla i = 2, 3, … ,N
// jeżeli SITO[ i ] =true
// j ← i*i
//  dopóki j ≤ N wykonuj
// SITO[ j ] ← false
// j ← j+i
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void zadanie3_core(int N)
{
    bool Sito[N + 1];
    Sito[1] = false;
    for (int i = 2; i < N; i++)
    {
        Sito[i] = true;
    }

    for (int i = 2; i < N; i++)
    {
        if (Sito[i] == true)
        {
            int j = i * i;
            while (j <= N)
            {
                Sito[j] = false;
                j = j + i;
            }
        }
    }
    
    for (int i = 1; i <= N; i++)
    {
        if(Sito[i])
            cout << i << " jest pierwsza" << endl;
        if(!Sito[i])
            cout << i << " jest złożona" << endl;
    }
}

int main()
{
    zadanie3_core(20);

    return 0;
}