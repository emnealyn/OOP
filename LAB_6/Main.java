import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Pojazd> pojazdy = new ArrayList<>();

        pojazdy.add(new Samochod());
        pojazdy.add(new Rower());
        pojazdy.add(new Motocykl());

        for (Pojazd pojazd : pojazdy) {
            pojazd.przyspiesz();
            pojazd.zatrzymaj();
        }
    }
}
