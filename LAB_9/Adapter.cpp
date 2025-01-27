#include <iostream>
#include <string>

// Interfejs płatności
class PaymentProcessor {
public:
    virtual void processPayment(double amount, std::string currency) = 0;
    virtual ~PaymentProcessor() {}
};

// Istniejący system
class LegacyPaymentProcessor {
public:
    void makePayment(std::string currency, double amount) {
        std::cout << "Processing payment of " << amount << " " << currency << " using legacy system." << std::endl;
    }
};

// Adapter
class PaymentAdapter : public PaymentProcessor {
private:
    LegacyPaymentProcessor* legacyProcessor;
public:
    PaymentAdapter(LegacyPaymentProcessor* legacy) : legacyProcessor(legacy) {}

    void processPayment(double amount, std::string currency) override {
        legacyProcessor->makePayment(currency, amount);
    }
};

// Klient
int main() {
    LegacyPaymentProcessor legacyProcessor;

    PaymentAdapter adapter(&legacyProcessor);

    adapter.processPayment(100, "EUR");

    return 0;
}