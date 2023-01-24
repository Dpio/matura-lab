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

int wczytajPlik(const std::string& plik) {
    int count = 0;
    std::ifstream f(plik);
    std::string line;
    while (std::getline(f, line)) {
        for(int i = 0; i < line.length() ;i++) {
            char znak = line[i];
        }
    }
    return count;
}

