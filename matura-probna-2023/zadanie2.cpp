#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Dla danej, dodatniej liczby całkowitej N, na kartce papieru rysujemy N różnych punktów
i numerujemy je liczbami 1, 2, ..., N. W tym zadaniu będziemy łączyć punkty ze sobą
strzałkami – funkcja strzałka(x,y) rysuje strzałkę od punktu o numerze x do punktu
o numerze y.
Wywołanie poniżej zapisanej funkcji rekurencyjnej rysuj(x) poskutkuje narysowaniem pewnej
liczby strzałek. Jej jedynym argumentem jest pewna liczba całkowita x z przedziału [1, N ].
Przeanalizuj funkcję i znajdź odpowiedzi dla podanych zadań.

funkcja rysuj(x)
    jeżeli 2*x ≤ N
        strzałka(x, 2*x)
        rysuj(2*x)
    jeżeli 2*x + 1 ≤ N
        strzałka(x, 2*x + 1)
        rysuj(2*x + 1)


W pliku pary.txt danych jest 1000 par liczb całkowitych z przedziału [1, 100 000], po
jednej parze w wierszu. Liczby w każdym wierszu są rozdzielone znakiem odstępu. Druga
liczba w parze zawsze jest większa od pierwszej.

Dla N = 100 000 wykonano polecenie rysuj(1) dla pewnego układu N punktów.
Napisz program, który znajdzie i wypisze te pary liczb z pliku pary.txt, które
odpowiadają numerom punktów x i y takich, że z punktu o numerze x można przejść po
jednej lub wielu strzałkach (zawsze zgodnie z ich zwrotami) do punktu o numerze y.
Przykład:
Przykładowo: dla N = 5 po strzałkach można przejść z punktu o numerze 1 do punktu
o numerze 4, ale nie można przejść z punktu o numerze 3 do punktu o numerze 5.

*/

void strzalka(int a, int b)
{
    cout << "a: " << a << " b: " << b << endl;
}

void rysuj(int x, int max)
{
    if (int(2 * x) <= max)
    {
        strzalka(x, 2 * x);
        rysuj(2 * x, max);
    }
    if (int(2 * x + 1) <= max)
    {
        strzalka(x, 2 * x + 1);
        rysuj(2 * x + 1, max);
    }
}

void zadanie2_core(std::string line)
{
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
    int b = stoi(liczba2);

    cout << "a: " << a << " b: " << b << endl;
    //rysuj(b, 10000);
}

int main()
{
    // std::cout << zadanie1_1("dane/mecz_przyklad.txt") << std::endl;
    // std::cout << zadanie1_1("dane/mecz.txt") << std::endl;
    // std::cout << zadanie1_1B("dane/mecz_przyklad.txt") << std::endl;
    // zadanie1_2("dane/mecz_przyklad.txt");
    // zadanie2("dane/pary.txt");

    zadanie2_core("1 4"); // 1 4
    zadanie2_core("3 5"); // nic
    // zadanie2_core("35922 66803");
    // zadanie2_core("26782 59975");
    // zadanie2_core("20627 36176");
    // zadanie2_core("47941 54222");

    return 0;
}