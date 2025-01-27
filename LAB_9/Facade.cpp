#include <iostream>

class FlightSearch {
public:
    void search() {
        std::cout << "Searching for flights from Poznan to Rome" << std::endl;
        std::cout << "Flights found:\n\t- 10:00\n\t- 12:00\n\t- 18:00" << std::endl;
    }
};

class BookingSystem {
public:
    void book() {
        std::cout << "Booking flight for Jan Kowalski" << std::endl;
    }
};

class PaymentProcessor {
public:
    void pay() {
        std::cout << "Processing payment of 150.00 EUR" << std::endl;
    }
};

class FlightFacade {
private:
    FlightSearch flightSearch;
    BookingSystem bookingSystem;
    PaymentProcessor paymentProcessor;

public:
    FlightFacade() {
        flightSearch = FlightSearch();
        bookingSystem = BookingSystem();
        paymentProcessor = PaymentProcessor();
    }

    void bookFlight() {
        flightSearch.search();
        bookingSystem.book();
        paymentProcessor.pay();
    }
};

int main() {
    FlightFacade fs = FlightFacade();

    fs.bookFlight();

    return 0;
}