#include <iostream>
#include <string>

using namespace std;


class Pojazd {
private:
    string marka;
    string model;
public:
    Pojazd(string marka, string model) {
        this->marka = marka;
        this->model = model;
    }

    virtual void przyspiesz() = 0;
    virtual void zatrzymaj()= 0;

    void getInfo() {
        cout << "Marka: " << marka << endl;
        cout << "Model: " << model << endl;
    }

};

class Samochod : private Pojazd {


public:
    Samochod (string marka, string model) : Pojazd(marka, model) {}
    void przyspiesz() override {
        cout << "Samochod przyspiesza" << endl;
    }
    void zatrzymaj() override {
        cout << "Samochod zatrzymuje sie" << endl;

    }
    void getInfo() {
        Pojazd::getInfo();
    }
};

class Rower : public Pojazd {

public:
    Rower(string marka, string model) : Pojazd(marka, model) {}

    void przyspiesz() override {
        cout << "Rower przyspiesza" << endl;
    }

    void zatrzymaj() override {
        cout << "Rower zatrzymuje sie" << endl;
    }

    void getInfo() {
        Pojazd::getInfo();
    };
};


int main() {
    Samochod samochod("Toyota", "Yaris");
    Rower rower("Kross", "Level B2");

    samochod.getInfo();
    rower.getInfo();

    samochod.przyspiesz();
    samochod.zatrzymaj();

    rower.przyspiesz();
    rower.zatrzymaj();

    return 0;
}