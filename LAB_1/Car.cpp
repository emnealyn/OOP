#include <iostream>
#include <string>

using namespace std;

class Car {
    private:
        string make;
        string model;
        int year;
        int currentYear;

    public:
        Car(string carMake, string carModel, int carYear) {
            make = carMake;
            model = carModel;
            year = carYear;
            currentYear=2024;
        }

        void displayInfo() {
            cout << "Car detail info: " << endl;
            cout << "Make: " << make << endl;
            cout << "Model: " << model << endl;
            cout << "Year: " << year << endl;
        }

        int getCarAge() {
            int age = currentYear - year;
            cout << "Car age (in years): " << age << endl;
            return age;
        }
};

bool isSameCar(Car car1, Car car2) {
    if (car1.getCarAge() == car2.getCarAge()) {
        cout << "The cars are the same age." << endl;
        return true;
    } else {
        cout << "The cars are not the same age." << endl;
        return false;
    }
}

int main() {
    Car car1("Toyota", "Yaris", 2020);
    Car car2("Toyota", "Corolla", 2019);

    car1.displayInfo();
    car1.getCarAge();
    isSameCar(car1,car2);

    return 0;
}