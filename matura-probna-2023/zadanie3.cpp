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

/*
    string liczba1;
    string liczba2;
    bool space = false;
    for (int i = 0; i < line.length(); i++)
    {
        char znak = line[i];

        if(znak == ' ') {
            space = true;
        }

        if(!space && znak != '\r') {
            liczba1.append(1, znak);
        } else if (znak != '\r') {
            liczba2.append(1, znak);
        }
    }

    int a = stoi(liczba1);

*/

void zadanie3_core(bool *sito, int N)
{
    sito[1] = false;
    for (int i = 2; i < N; i++)
    {
        sito[i] = true;
    }

    for (int i = 2; i < N; i++)
    {
        if (sito[i] == true)
        {
            int j = i * i;
            while (j > 0 && j <= N)
            {
                sito[j] = false;
                j = j + i;
            }
        }
    }
}

void zadanie3(const string &plik)
{
    ifstream f(plik);
    string line;

    int array[100];
    int idx = 0;
    while (getline(f, line))
    {
        // linie = 468/r -> dla 1 wiersza z pliku liczby_przyklad.txt
        array[idx++] = std::stoi(line);
    }

    // 1. czym jest sito i co zawiera?
    // 2. czemu 1000001, a jakie miało być z zadania?
    // 3.
    bool sito[1000001]; // incjalizacja
    zadanie3_core(sito, 1000000);

    // cout << sito[10] << endl; // fałsz
    // cout << sito[11] << endl; // prawda

    /// ZADANIE 3.2 START
    int pierwsze = 0;
    for (int i = 0; i < 100; i++)
    {
        int x = array[i];
        if (sito[x - 1])
        {
            ++pierwsze;
        }
    }

    cout << pierwsze << endl;
    /// ZADANIE 3.2 KONIEC
}

//DO ZROBIENIA PÓŹNIEJ
void zadanie3_3(const string &plik)
{
    ifstream f(plik);
    string line;

    int array[100];
    int idx = 0;
    while (getline(f, line))
    {
        array[idx++] = std::stoi(line);
    }

    bool sito[1000001]; // incjalizacja
    zadanie3_core(sito, 1000000);

    for (int i = 0; i < 100; i++)
    {
        int x = array[i];
        if (!sito[x]) // TYLKO PARZYSTE
        {
            bool sito2[x + 1];
            sito2[1] = false;
            for (int i = 2; i < x; i++)
            {
                sito2[i] = true;
            }

            for (int i = 2; i < x; i++)
            {
                if (sito2[i] == true)
                {
                    int j = i * i;
                    while (j > 0 && j <= x)
                    {
                        if (j == x)
                        {
                        }
                        sito2[j] = false;
                        j = j + i;
                    }
                }
            }
        }
    }
}

int main()
{
    // zadanie3_core(100);

    // for (int i = 1; i <= N; i++)
    // {
    //     if(Sito[i])
    //         cout << i << " jest pierwsza" << endl;
    //     if(!Sito[i])
    //         cout << i << " jest złożona" << endl;
    // }

    // zadanie3_core(123);
    // zadanie3_core(23);
    // zadanie3_core(10);

    zadanie3("dane/liczby_przyklad.txt");
    // zadanie3("dane/liczby.txt");

    return 0;
}