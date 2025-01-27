public class Samochód {
    private String marka;
    private String model;
    private int rokProdukcji;

    // Konstruktor domyślny
    public Samochód() {
        this.marka = "Nieznana";
        this.model = "Nieznany";
        this.rokProdukcji = 0;
    }

    // Konstruktor z parametrami
    public Samochód(String marka, String model, int rokProdukcji) {
        this.marka = marka;
        this.model = model;
        this.rokProdukcji = rokProdukcji;
    }

    // Metoda do wyświetlania informacji o samochodzie
    public void pokażInformacje() {
        System.out.println("Samochód: " + marka + " " + model + ", Rok produkcji: " + rokProdukcji + ".");
    }

    public static void main(String[] args) {
        // Tworzenie obiektów
        Samochód s1 = new Samochód();
        s1.pokażInformacje();

        Samochód s2 = new Samochód("Toyota", "Yaris", 2015);
        s2.pokażInformacje();
    }
}
