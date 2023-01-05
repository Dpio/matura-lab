#include <iostream>
#include <fstream>
#include <string>

int wczytajPlik(const std::string& plik) {
    int count = 0;
    std::ifstream f(plik);
    std::string line;
    while (std::getline(f, line)) {
        for (char znak : line) {

        }
    }
    return count;
}