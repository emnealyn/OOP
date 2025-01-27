#include <iostream>
#include <string>

using namespace std;

class Pracownik {
protected:
    string stanowisko;
    float wynagrodzenie;

public:
    Pracownik(string stanowisko, float wynagrodzenie) : stanowisko(stanowisko), wynagrodzenie(wynagrodzenie) {}
};

class Nauczyciel : public Pracownik {
    string przedmiot;

public:
    Nauczyciel(string stanowisko, float wynagrodzenie, string przedmiot)
            : Pracownik(stanowisko, wynagrodzenie), przedmiot(przedmiot) {}

    void pokazDane() {
        cout << "Nauczyciel: \nStanowisko: " << stanowisko << "\nWynagrodzenie: " << wynagrodzenie << "\nPrzedmiot: " << przedmiot << endl;
    }
};

class Administracja : public Pracownik {
    string dzial;

public:
    Administracja(string stanowisko, float wynagrodzenie, string dzial)
            : Pracownik(stanowisko, wynagrodzenie), dzial(dzial) {}

    void pokazDane() {
        cout << "Pracownik Administracji: \nStanowisko: " << stanowisko << "\nWynagrodzenie: " << wynagrodzenie << "\nDział: " << dzial << endl;
    }
};

int main() {
    Nauczyciel nauczyciel("Nauczyciel glowny", 2100.0f, "Polski");
    Administracja administracja("Sekretarz", 8000.0f, "Dzial Obslugi");

    nauczyciel.pokazDane();
    administracja.pokazDane();

    return 0;
}
