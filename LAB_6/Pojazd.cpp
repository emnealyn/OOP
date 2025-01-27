#include <iostream>
#include <vector>
#include<memory>
using namespace std;

class Pojazd {
public:

    virtual void przyspiesz() {
        cout << "Pojazd przyspiesza." << endl;
    }

    virtual void zatrzymaj() {
        cout << "Pojazd zatrzymuje się." << endl;
    }

    virtual ~Pojazd() {
        cout << "Usuwanie obiektu Pojazd" << endl;
    }
};

class Samochod : public Pojazd {
public:
    void przyspiesz() override {
        cout << "Samochód przyspiesza." << endl;
    }
    void zatrzymaj() override {
        cout << "Samochód zatrzymuje się." << endl;
    }
    ~Samochod() {
        cout << "Usuwanie obiektu Samochód" << endl;
    }
};

class Rower : public Pojazd {
public:
    void przyspiesz() override {
        cout << "Rower przyspiesza." << endl;
    }
    void zatrzymaj() override {
        cout << "Rower zatrzymuje się." << endl;
    }
    ~Rower() {
        cout << "Usuwanie obiektu Rower" << endl;
    }
};

class Motocykl : public Pojazd {
public:
    void przyspiesz() override {
        cout << "Motocykl przyspiesza." << endl;
    }
    void zatrzymaj() override {
        cout << "Motocykl zatrzymuje się." << endl;
    }
    ~Motocykl() {
        cout << "Usuwanie obiektu Motocykl" << endl;
    }

};

class Skuter : public Pojazd {
public:
    void przyspiesz() override {
        cout << "Skuter przyspiesza." << endl;
    }

    void zatrzymaj() override {
        cout << "Skuter zatrzymuje się." << endl;
    }

    ~Skuter() {
        cout << "Usuwanie obiektu Skuter" << endl;
    }
};

int main() {
    vector<unique_ptr<Pojazd>> pojazdy;

    pojazdy.push_back(make_unique<Samochod>());
    pojazdy.push_back(make_unique<Rower>());
    pojazdy.push_back(make_unique<Motocykl>());
    pojazdy.push_back(make_unique<Skuter>());

    for (const auto& pojazd : pojazdy) {
        pojazd->przyspiesz();
        pojazd->zatrzymaj();
    }

    return 0;
}
