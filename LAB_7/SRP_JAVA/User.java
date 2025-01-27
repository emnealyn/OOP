package SRP_JAVA;

public class User {

    private final String name;
    private final String uuid;

    public User(String name, String uuid) {
        this.name = name;
        this.uuid = uuid;
    }

    String getName() {
        return name;
    }

    String getUUID() {
        return uuid;
    }

}