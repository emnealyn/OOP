#include <iostream>

using namespace std;

class Tablica {
private:
    int* dane;
    int rozmiar;

public:
    // Konstruktor domyślny
    Tablica() : rozmiar(10) {
        dane = new int[rozmiar];
        cout << "Domyślny konstruktor: alokowano tablicę o rozmiarze " << rozmiar << ".\n";
    }

    // Konstruktor z parametrem
    Tablica(int r) : rozmiar(r) {
        dane = new int[rozmiar];
        cout << "Konstruktor z parametrem: alokowano tablicę o rozmiarze " << rozmiar << ".\n";
    }

    // Destruktor
    ~Tablica() {
        delete[] dane;
        cout << "Destruktor: zwolniono pamięć dla tablicy o rozmiarze " << rozmiar << ".\n";
    }
};

int main() {
    Tablica t1;
    Tablica t2(20);

    return 0;
}
