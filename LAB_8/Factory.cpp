#include <iostream>

class Vehicle {
    public:
        virtual void drive() = 0;
        virtual ~Vehicle() {}

};

class Car : public Vehicle {
    public:
        void drive() override {
            std::cout << "Driving a Car" << std::endl;
        }
};

class Bike : public Vehicle {
    public:
        void drive() override {
            std::cout << "Driving a Bike" << std::endl;
        }
};



class VehicleFactory {
    public:
        virtual Vehicle* createVehicle() = 0;
        virtual ~VehicleFactory() {};
};

class CarFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Car();
    }
};

class BikeFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Bike();
    }
};


int main() {
    VehicleFactory* carFactory = new CarFactory();
    VehicleFactory* bikeFactory = new BikeFactory();

    Vehicle* car = carFactory->createVehicle();
    Vehicle* bike = bikeFactory->createVehicle();

    car->drive();
    bike->drive();

    delete carFactory;
    delete bikeFactory;
    delete car;
    delete bike;

    return 0;
}