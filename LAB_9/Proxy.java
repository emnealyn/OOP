// Interfejs dostępu do danych
interface DataAccess {
    void accessData(String user);
}

// Klasa rzeczywista (RealSubject)
class RealDataAccess implements DataAccess {
    @Override
    public void accessData(String user) {
        System.out.println("Access granted for user: " + user);
    }
}

// Klasa Proxy
class DataAccessProxy implements DataAccess {
    private final RealDataAccess realDataAccess;
    private static final String AUTHORIZED_USER = "admin";

    public DataAccessProxy() {
        this.realDataAccess = new RealDataAccess();
    }

    @Override
    public void accessData(String user) {
        System.out.println("Accessing data by: " + user + "...");

        if (isAuthorized(user)) {
            realDataAccess.accessData(user);
        } else {
            System.out.println("Access denied for user: " + user);
        }
    }

    private boolean isAuthorized(String user) {
        return AUTHORIZED_USER.equals(user);
    }
}

// Klient
public class Proxy {
    public static void main(String[] args) {
        DataAccess dataAccess = new DataAccessProxy();

        // Dostęp dozwolony
        dataAccess.accessData("admin");

        System.out.println();

        // Dostęp zabroniony
        dataAccess.accessData("user");
    }
}