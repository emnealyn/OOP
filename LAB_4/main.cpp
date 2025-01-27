#include<iostream>
#include<string>

using namespace std;

class Osoba {
    private:
        string imie;
        string nazwisko;
        int wiek;
        string email;
        string telefon;

    public:
        Osoba() : imie(""), nazwisko(""), wiek(0), email(""), telefon("") {}

        Osoba(string imie, string nazwisko, int wiek, string email, string telefon) : imie(imie), nazwisko(nazwisko), wiek(wiek), email(email), telefon(telefon) {}


        string getImie() const {return imie;}

        string getNazwisko() const {return nazwisko;}

        int getWiek() const {return wiek;}

        string getEmail() const {return email;}

        string getTelefon() const {return telefon;}

        void setImie(string imie) {this->imie = imie;}

        void setNazwisko(string nazwisko) {this->nazwisko = nazwisko;}

        void setWiek(int wiek) {this->wiek = wiek;}

        void setEmail(string email) {
            if(email.find("@") != string::npos) {
            this->email = email;
            } else {
                cout << "Niepoprawny email" << endl;
            }
        }

        void setTelefon(string telefon) {
            if (telefon.length() == 9) {
                this->telefon = telefon;
            } else {
                cout << "Niepoprawny numer telefonu" << endl;
            }
        }
};

int main() {
    Osoba osoba("Chiara", "Aliementi", 20, "chiaraali@gmail.com", "123456789");
    cout << "Imie: " << osoba.getImie() << endl;
    cout << "Nazwisko: " << osoba.getNazwisko() << endl;
    cout << "Wiek: " << osoba.getWiek() << endl;
    cout << "Email: " << osoba.getEmail() << endl;
    cout << "Telefon: " << osoba.getTelefon() << endl;

    osoba.setImie("Charles");
    osoba.setNazwisko("Trapani");
    osoba.setWiek(21);
    osoba.setEmail("charliessi@office.com");
    osoba.setTelefon("987654321");

    cout << "\nZmienione dane: \n\n";
    cout << "Imie: " << osoba.getImie() << endl;
    cout << "Nazwisko: " << osoba.getNazwisko() << endl;
    cout << "Wiek: " << osoba.getWiek() << endl;
    cout << "Email: " << osoba.getEmail() << endl;
    cout << "Telefon: " << osoba.getTelefon() << endl;

}
