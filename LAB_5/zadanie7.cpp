#include <iostream>

using namespace std;

class Silnikowy {
public:
    virtual void przyspiesz() {
        cout << "Pojazd silnikowy przyspiesza z użyciem silnika spalinowego." << endl;
    }
};

class Elektryczny {
public:
    void ladowanie() {
        cout << "Pojazd elektryczny ładuje baterię." << endl;
    }
};

class Hybryda : public Silnikowy, public Elektryczny {
public:
    void przyspiesz() override {
        cout << "Pojazd hybrydowy przyspiesza, korzystając z silnika spalinowego i elektrycznego." << endl;
    }
};

int main() {
    Hybryda samochodHybrydowy;
    samochodHybrydowy.przyspiesz();  
    samochodHybrydowy.ladowanie(); 

    return 0;
}
