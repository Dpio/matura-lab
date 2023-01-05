// Westęp
// Dawno temu, w odległej galaktyce, rozegrano mecz w grę, która przypominała siatkówkę.
// W meczu wystąpiły dwie drużyny: drużyna A i drużyna B. Mecz składał się z 10 000 krótkich
// rozgrywek. Każda rozgrywka kończyła się wygraną jednej z dwóch drużyn, za którą
// zwycięska drużyna otrzymywała jeden punkt.
// Plik mecz.txt zawiera zapis wyników kolejnych rozgrywek – jeden wiersz z napisem
// złożonym z 10 000 znaków A i B. Znak A oznacza, że rozgrywkę wygrała drużyna A,
// natomiast znak B – że rozgrywkę wygrała drużyna B.
// Napisz program(-y) który(-e) znajdzie(-dą) odpowiedzi do poniższych zadań. Odpowiedzi
// zapisz w pliku wyniki1.txt, a każdą z nich poprzedź numerem odpowiedniego zadania.
// Do dyspozycji masz plik mecz_przyklad.txt, spełniający warunki zadania – odpowiedzi
// dla tego pliku podano w treściach zadań. Możesz sprawdzać na nim działanie swojego
// programu.

// Zadanie 1
// Oblicz, ile razy nastąpiła sytuacja, w której rozgrywkę wygrała inna drużyna niż rozgrywkę
// poprzednią (tzn. dwa kolejne znaki A lub B w opisie meczu się różnią).
// Przykład: Dla napisu ABBBABA odpowiedzią jest 4.
// Natomiast dla pliku mecz_przyklad.txt odpowiedzią jest 1798

#include <iostream>
#include <fstream>
#include <string>

int zadanie1_1B(const std::string& plik) {
    int index = 0;
    int count = 0;
    std::ifstream f(plik);
    std::string line;
    char last = 'z';
    while (std::getline(f, line)) {
        for(int i = 0; i < line.length() ;i++) {

            char znak = line[i];
            if(znak != last && last != 'z') {
                count++;
            }
            last = znak;
        }
    }
    
    return count;
}

// Zadanie 1
// Oblicz, ile razy nastąpiła sytuacja, w której rozgrywkę wygrała inna drużyna niż rozgrywkę
// poprzednią (tzn. dwa kolejne znaki A lub B w opisie meczu się różnią).
// Przykład: Dla napisu ABBBABA odpowiedzią jest 4.
// Natomiast dla pliku mecz_przyklad.txt odpowiedzią jest 1798
// 5030

bool uznawane_znaki(char z) {
    return (z == 'A' || z == 'B');
}

int zadanie1_1(const std::string& plik) {
    int index = 0;
    int count = 0;

    std::ifstream f(plik);
    std::string line;
    char last = 'z'; // inicjalnie dowolony znak inny niż uznawane znaki (A, B)
    while (std::getline(f, line)) {
        for(int i = 0; i < line.length() ;i++) {

            char znak = line[i];

            if(i == 9997) {
                int p = 1;
                // ABBBBAAB
            }

            if(znak != last && i > 0 && uznawane_znaki(znak)) {
                count++;
            }
            last = znak;
        }
    }
    
    return count;
}

// Zadanie 1.2
// Pierwszy set w meczu trwa do pierwszej rozgrywki, po której któraś z drużyn ma co najmniej
// 1000 punktów za wygranie dotychczasowych rozgrywek, natomiast drużyna przeciwna ma
// co najmniej 3 punkty mniej. Drużyna, która zdobywa w secie więcej punktów od przeciwnej,
// wygrywa pierwszego seta.
// Przykład: pierwszy set może się zakończyć wynikami: 1000:500, 997:1000, 1500:1497.
// Wyniki 900:100, 999:1000, 1500:1500 nie kończą seta.
// Podaj, która drużyna wygrała pierwszego seta i jaki w tym momencie był wynik (liczba
// zwycięskich rozgrywek drużyny A i liczba zwycięskich rozgrywek drużyny B w pierwszym
// secie).
// Dla pliku mecz_przyklad.txt odpowiedzią jest: A 1000:5

void zadanie1_2_B(const std::string& plik) {
    int index = 0;
    int count = 0;
    int countA = 0;
    int winA = 0;
    int countB = 0;
    int winB = 0;
    std::ifstream f(plik);
    std::string line;
    while (std::getline(f, line)) {
        for(int i = 0; i < line.length() ;i++) {

            char znak = line[i];
            if(znak == 'A') {
                countA++;
            }
            if(znak == 'B') {
                countB++;
            }

            if(countA >= 1000 && countA - 3 > countB) {
                winA++;
                countA = 0;
                countB = 0;
            }
            if(countB >= 1000 && countB - 3 > countA) {
                winB++;
                countA = 0;
                countB = 0;
            }
        }
    }

    if(winA > winB) {
        std::cout << "A " << winA << ":" << winB << std::endl;
    }
    else 
        std::cout << "B " << winA << ":" << winB << std::endl;
}

void zadanie1_2(const std::string& plik) {
    int countA = 0;
    int countB = 0;
    std::ifstream f(plik);
    std::string line;
    while (std::getline(f, line)) {
        for(int i = 0; i < line.length() ;i++) {

            char znak = line[i];
            if(znak == 'A') {
                countA++;
            }
            if(znak == 'B') {
                countB++;
            }

            if(countA >= 1000 && countA == countB + 3) {
                std::cout << "A " << countA << ":" << countB << std::endl;
                return;
            }
            if(countB >= 1000 && countB == countA + 3) {
                std::cout << "B " << countA << ":" << countB << std::endl;
                return;
            }
        }
    }
}

// Zadanie 1.3
// Powiemy, że drużyna ma dobrą passę, jeśli wygrywa rozgrywki co najmniej 10 razy z rzędu.
// Każda dobra passa rozpoczyna się albo na początku meczu, albo bezpośrednio po
// przegranej rozgrywce. Każda dobra passa kończy się albo z końcem meczu, albo
// bezpośrednio przed przegraną rozgrywką.
// Podaj łączną liczbę dobrych pass, które miały obie drużyny w meczu. Wyznacz długość
// najdłuższej dobrej passy i drużynę, która ją osiągnęła. Tylko jedna drużyna miała dobrą
// passę o tej długości.
// Przykład: w meczu BBBBBBBBBBAABBAAAAAAAAAAABA mamy łącznie 2 dobre passy.
// Najdłuższą dobrą passę, o długości 11, osiągnęła drużyna A
// Dla pliku mecz_przyklad.txt odpowiedzią jest: 2 A 1000 (dwie dobre passy, najdłuższa
// drużyny A o długości 1000).

void zadanie1_3(const std::string& plik) {
    int countA = 0;
    int countB = 0;

    int passaMin = 10; // jeśli wygrywa rozgrywki co najmniej 10 razy z rzędu
    int sumaPass = 0; // Podaj łączną liczbę dobrych pass, które miały obie drużyny w meczu
    int najdluzszaPassa = 0; // Wyznacz długość najdłuższej dobrej passy i drużynę, która ją osiągnęła.
    char najdluzszaPassaDruzyna = 'z'; // Drużyna która osiągnęła najdłuższą dobra passę.
    char poprzedniZnak = 'z';
    int obecnaPassa = 0;

    std::ifstream f(plik);
    std::string line;
    while (std::getline(f, line)) {
        for(int i = 0; i < line.length() ;i++) {
            char znak = line[i];
            if(true) {
                obecnaPassa++;
            }
        }
    }
    
}

int main() {
    // std::cout << zadanie1_1("dane/mecz_przyklad.txt") << std::endl;
    // std::cout << zadanie1_1("dane/mecz.txt") << std::endl;
    // std::cout << zadanie1_1B("dane/mecz_przyklad.txt") << std::endl;
    // zadanie1_2("dane/mecz_przyklad.txt");
    // zadanie1_2("dane/mecz.txt");
    return 0;
}






