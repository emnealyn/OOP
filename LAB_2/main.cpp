#include <iostream>
#include <string>

using namespace std;

class Samochód {
private:
    string marka;
    string model;
    int rokProdukcji;

public:
    // Konstruktor domyślny
    Samochód() : marka("Nieznana"), model("Nieznany"), rokProdukcji(0) {
    }

    // Konstruktor z parametrami
    Samochód(string m, string mo, int rok) : marka(m), model(mo), rokProdukcji(rok) {
    }

    // Destruktor
    ~Samochód() {
        cout << "Destruktor wywołany dla: " << marka << " " << model << ".\n";
    }

    // Metoda do wyświetlania informacji o samochodzie
    void pokażInformacje() const {
        cout << "Samochód: " << marka << " " << model << ", Rok produkcji: " << rokProdukcji << ".\n";
    }
};

int main() {
    // Tworzenie obiektów
    Samochód s1;
    s1.pokażInformacje();

    Samochód s2("Toyota", "Yaris", 2015);
    s2.pokażInformacje();

    return 0;
}
