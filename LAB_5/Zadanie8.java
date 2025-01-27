interface Silnikowy {
    void przyspiesz();
}

interface Elektryczny {
    void ladowanie();
}

class Hybryda implements Silnikowy, Elektryczny {
    @Override
    public void przyspiesz() {
        System.out.println("Pojazd hybrydowy przyspiesza.");
    }

    @Override
    public void ladowanie() {
        System.out.println("Pojazd hybrydowy ładuje baterię.");
    }
}

public class Zadanie8 {
    public static void main(String[] args) {
        Hybryda samochodHybrydowy = new Hybryda();

        samochodHybrydowy.przyspiesz();
        samochodHybrydowy.ladowanie();
    }
}
