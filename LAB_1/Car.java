public class Car {
    String make;
    String model;
    int year;
    int currentYear;

    public Car(String make, String model, int year) {
        this.make = make;
        this.model = model;
        this.year = year;
        this.currentYear = 2024;
    }

    public void displayInfo() {
        System.out.println("Make: " + make);
        System.out.println("Model: " + model);
        System.out.println("Year: " + year);
    }

    int getCarAge() {
        return currentYear - year;
    }

    public boolean isSameCar(Car otherCar) {
        return this.make.equals(otherCar.make) && this.model.equals(otherCar.model) && this.year == otherCar.year;
    }

    public static void main(String[] args) {
        Car car1 = new Car("Toyota", "Yaris", 2020);
        Car car2 = new Car("Toyota", "Corolla", 2013);
        car1.displayInfo();
        System.out.println("Car age (in years): " + car1.getCarAge());
        if (car1.isSameCar(car2)) {
            System.out.println("The cars are the same.");
        } else {
            System.out.println("The cars are different.");
        }

    }
}
