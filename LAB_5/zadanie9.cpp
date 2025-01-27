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

    void getInfo() {
        cout << "Marka: " << marka << endl;
        cout << "Model: " << model << endl;
    }

};

class Samochod : private Pojazd {
public:
    Samochod (string marka, string model) : Pojazd(marka, model) {}
};

class Elektryczny : public Samochod {
public:
    Elektryczny(string marka, string model) : Samochod(marka, model) {}
    void przyspiesz() override {
        cout << "Samochod elektryczny przyspiesza" << endl;
    }

};

int main() {
    Elektryczny e("Tesla", "Model S");
    e.przyspiesz();
    return 0;
}