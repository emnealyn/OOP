abstract class Pojazd {
    public abstract void przyspiesz();

    public void zatrzymaj() {
        System.out.println("Pojazd zatrzymuje się.");
    }
}

class Samochod extends Pojazd {
    @Override
    public void przyspiesz() {
        System.out.println("Samochód przyspiesza.");
    }
}

class Rower extends Pojazd {
    @Override
    public void przyspiesz() {
        System.out.println("Rower przyspiesza.");
    }
}

public class Main {
    public static void main(String[] args) {
        Pojazd pojazd1 = new Samochod();
        Pojazd pojazd2 = new Rower();

        pojazd1.przyspiesz();
        pojazd2.przyspiesz();
    }
}
