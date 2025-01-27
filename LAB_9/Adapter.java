// Interfejs płatności
interface PaymentProcessor {
    void processPayment(double amount, String Currency);
}

// Istniejący system
class LegacyPaymentProcessor {
    public void makePayment(String currency, double amount) {
        System.out.println("Processing payment of " + amount + " " + currency + " using legacy system.");
    }
}

// Adapter
class PaymentAdapter implements PaymentProcessor {
    private final LegacyPaymentProcessor legacyProcessor;

    public PaymentAdapter(LegacyPaymentProcessor legacyProcessor) {
        this.legacyProcessor = legacyProcessor;
    }

    @Override
    public void processPayment(double amount, String currency) {
        legacyProcessor.makePayment(currency, amount);
    }
}

// Klient
public class Adapter {
    public static void main(String[] args) {
        LegacyPaymentProcessor legacyProcessor = new LegacyPaymentProcessor();

        PaymentAdapter adapter = new PaymentAdapter(legacyProcessor);

        adapter.processPayment(100, "EUR");
    }
}