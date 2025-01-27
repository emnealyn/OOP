public class Tablica {
    private int[] dane;

    // Konstruktor domyślny
    public Tablica() {
        this.dane = new int[10];
        System.out.println("Domyślny konstruktor: alokowano tablicę o rozmiarze 10.");
    }

    // Konstruktor z parametrem
    public Tablica(int rozmiar) {
        this.dane = new int[rozmiar];
        System.out.println("Konstruktor z parametrem: alokowano tablicę o rozmiarze " + rozmiar + ".");
    }

    public static void main(String[] args) {
        // Testowanie klasy Tablica
        Tablica t1 = new Tablica();
        Tablica t2 = new Tablica(20);
    }
}
