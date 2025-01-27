package SRP_JAVA;

public class Main {
    public static void main(String[] args) {
        User user = new User("Jan", "1234-5678-9012-3456");
        UserSaver userSaver = new UserSaver(user);

        userSaver.saveUser();

    }
}