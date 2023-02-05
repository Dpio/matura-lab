#include <iostream>

using namespace std;

unsigned long long silnia(int n)
{
    if (n == 0)
    {
        return 1;
    }

    unsigned long long a = 1;
    for (int i = 1; i <= n; i++)
    {
        a = a * i;
    }

    return a;
}

void czyDanaLiczbaJestSilna(int n)
{
    unsigned long long tab[6];

    // inicjalizacja
    for (int i = 0; i < 6; i++)
    {
        tab[i] = 1;
    }

    // ppoznac wszystkie silnie liczb do n
    for (int i = 1; i <= 6; i++)
    {
        tab[i] = silnia(i);
    }

    // wyświetlanie tablicy silnia
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << tab[i] << endl;
    // }

    bool czySilna = false;
    int liczby[10];
    int indexLiczb = 0;
    for (int i = 0; i < 10; i++)
    {
        liczby[i] = -1;
    }

    int idxNajblizsza = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i + 1 < 10 && tab[i + 1] > n)
        {
            idxNajblizsza = i;
            break;
        }
    }

    unsigned long long b = 0;
    bool czyPetlaDziala = true;
    while (czyPetlaDziala)
    {
        liczby[indexLiczb++] = idxNajblizsza;
        b = n - tab[idxNajblizsza];

        if (b == 0)
        {
            czySilna = true;
        }

        if (b <= 0)
        {
            czyPetlaDziala = false;
        }
    }

    // wyświetlanie
    if (czySilna)
    {
        cout << n << " [True, [";

        for (int i = 0; i < 10; i++)
        {
            if (liczby[i] == -1)
            {
                break;
            }
            cout << liczby[i];
            if (i + 1 < 10 && liczby[i + 1] != -1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    else
    {
        cout << n << " False" << endl;
    }
}

void silna2(int N)
{
    int l = N;
    int k = 1;

    unsigned long long tab[6];
    for (int i = 0; i < 6; i++)
    {
        tab[i] = 1;
    }

    while (tab[k] <= N)
    {
        tab[k] = tab[k - 1] * k;
        k = k + 1;
    }
    k = k - 1;

    int liczby[10];
    int indexLiczb = 0;
    for (int i = 0; i < 10; i++)
    {
        liczby[i] = -1;
    }
    
    while (N > 0)
    {
        if (tab[k] <= N)
        {
            N = N - tab[k];
            liczby[indexLiczb++] = k;
        }
        
        k = k - 1;
        if (k == -1)
        {
            break;
        }
    }
    

    if (N == 0 && liczby[indexLiczb - 1] > 0)
    {
        cout << l << " true ";
        for (int i = 0; i < 10; i++)
        {
            if (liczby[i] == -1)
            {
                break;
            }
            cout << liczby[i];
            if (i + 1 < 10 && liczby[i + 1] != -1)
            {
                cout << ", ";
            }
        }
        cout << endl;
        
    }
    else
    {
        cout << l << " false" << endl;
    }
}

int main()
{
    for (int i = 1; i <= 200; i++)
    {
        silna2(i); 
        //2 [True, [2]] 
        //9 [True, [3, 2, 1]] 
    }

    return 0;
}

/* obliczenie wszystkich silni
k=1
while(silnia[k]<=N)
{
    silnia[k]=silnia[k-1]*k
    k=k+1
}
k=k-1
//metoda zachlanna-metoda podejmujaca w kazdym kroku decyzje
//ktora w danej chwili wydcaje sie najbardziej korzystna
while(N>0)
{
    if(silnia[k]<=N)
    {
        N=N-s[k];
    }
    k=k-1;
    if(k==-1)
    {
        break;
    }
}
if(N==0)
{
    cout<< "liczba silna" <<endl;
}
else
    cout<<" liczba nie jest silna"<<endl;
*/