public class Osoba {
    private String imie;
    private String nazwisko;
    private int wiek;
    private String email;
    private String telefon;

    public Osoba() {
        this.imie = "";
        this.nazwisko = "";
        this.wiek = 0;
        this.email = "";
        this.telefon = "";
    }

    public Osoba(String imie, String nazwisko, int wiek) {
        this.imie = imie;
        this.nazwisko = nazwisko;
        this.wiek = wiek;
        this.email = "";
        this.telefon = "";
    }

    public String getImie() { return imie; }
    public String getNazwisko() { return nazwisko; }
    public int getWiek() { return wiek; }
    public String getEmail() { return email; }
    public String getTelefon() { return telefon; }

    public void setImie(String imie) { this.imie = imie; }
    public void setNazwisko(String nazwisko) { this.nazwisko = nazwisko; }
    public void setWiek(int wiek) { this.wiek = wiek; }

    public void setEmail(String email) {
        if (email.contains("@")) {
            this.email = email;
        } else {
            System.out.println("Nieprawidłowy adres email.");
        }
    }

    public void setTelefon(String telefon) {
        if (telefon.length() == 9 ) {
            this.telefon = telefon;
        } else {
            System.out.println("Nieprawidłowy numer telefonu.");
        }
    }

    public static void main(String[] args) {
        Osoba osoba = new Osoba("Chiara", "Aliementi", 20);

        osoba.setEmail("chiara@example.com");
        osoba.setTelefon("123456789");
        
        System.out.println("Imię: " + osoba.getImie());
        System.out.println("Nazwisko: " + osoba.getNazwisko());
        System.out.println("Wiek: " + osoba.getWiek());
        System.out.println("Email: " + osoba.getEmail());
        System.out.println("Telefon: " + osoba.getTelefon());

        
        osoba.setImie("Chiariana");
        osoba.setNazwisko("Aliementini");
        osoba.setWiek(21);
        osoba.setEmail("chiarusia@office.com");  
        osoba.setTelefon("987654321");   
        
        System.out.println("Imię: " + osoba.getImie());
        System.out.println("Nazwisko: " + osoba.getNazwisko());
        System.out.println("Wiek: " + osoba.getWiek());
        System.out.println("Email: " + osoba.getEmail());
        System.out.println("Telefon: " + osoba.getTelefon());
        
    }
}
