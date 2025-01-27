package SRP_JAVA;

public class UserSaver {
    private final User user;

    public UserSaver(User user) {
        this.user = user;
    }

    public void saveUser() {
        System.out.println("User " + user.getName() + " with UUID " + user.getUUID() + " saved.");
    }
}