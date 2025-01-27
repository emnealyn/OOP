#include <iostream>
using namespace std;

class Pojazd {
public:
    virtual void przyspiesz() {
        cout << "Pojazd przyspiesza." << endl;
    }
};

class Silnikowy : virtual public Pojazd {
public:
    void przyspiesz() override {
        cout << "Pojazd silnikowy przyspiesza." << endl;
    }
};

class Elektryczny : virtual public Pojazd {
public:
    void przyspiesz() override {
        cout << "Pojazd elektryczny przyspiesza." << endl;
    }
};

class Hybryda : public Silnikowy, public Elektryczny {
public:
    void przyspiesz() override {
        cout << "Pojazd hybrydowy przyspiesza." << endl;
    }
};

int main() {
    Hybryda samochodHybrydowy;
    samochodHybrydowy.przyspiesz();

    return 0;
}
