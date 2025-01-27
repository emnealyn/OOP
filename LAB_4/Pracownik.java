class Pracownik {
    protected String stanowisko;  // atrybut chroniony
    protected float wynagrodzenie;  // atrybut chroniony

    public Pracownik(String stanowisko, float wynagrodzenie) {
        this.stanowisko = stanowisko;
        this.wynagrodzenie = wynagrodzenie;
    }
}

class Nauczyciel extends Pracownik {
    private String przedmiot;

    public Nauczyciel(String stanowisko, float wynagrodzenie, String przedmiot) {
        super(stanowisko, wynagrodzenie);
        this.przedmiot = przedmiot;
    }

    public void pokazDane() {
        System.out.println("Stanowisko: " + stanowisko + ", Wynagrodzenie: " + wynagrodzenie + ", Przedmiot: " + przedmiot);
    }
}

class Administracja extends Pracownik {
    private String dzial;

    public Administracja(String stanowisko, float wynagrodzenie, String dzial) {
        super(stanowisko, wynagrodzenie);
        this.dzial = dzial;
    }

    public void pokazDane() {
        System.out.println("Stanowisko: " + stanowisko + ", Wynagrodzenie: " + wynagrodzenie + ", Dział: " + dzial);
    }
}

public class Main {
    public static void main(String[] args) {
        Nauczyciel nauczyciel = new Nauczyciel("Nauczyciel wspomagający", 5200.0f, "Matematyka");
        Administracja administracja = new Administracja("Sekretarz", 3200.0f, "Dział Obsługi");

        
        system.out.println("Nauczyciel:\n");
        nauczyciel.pokazDane();
        System.out.println("\nAdministracja:\n");
        administracja.pokazDane();
    }
}
