import java.util.ArrayList;
import java.util.List;

interface Observer1 {
    void update(String message);
}

class User implements Observer1 {
    private final String name;
    
    public User(String name) {
        this.name = name;
    }

    @Override
    public void update(String message) {
        System.out.println(name + " received message: " + message);
    }
}

class NotificationService {
    private final List<Observer1> observers = new ArrayList<>();

    public void addObserver(Observer1 observer) {
        observers.add(observer);
    }

    public void removeObserver(Observer1 observer) {
        observers.remove(observer);
    }

    public void notifyObservers(String message) {
        for (Observer1 observer : observers) {
            observer.update(message);
        }
    }
    
}

public class Observer {
    public static void main(String[] args) {
        User u1 = new User("User 1");
        User u2 = new User("User 2");
        User u3 = new User("User 3");

        NotificationService notificationService = new NotificationService();
        notificationService.addObserver(u1);
        notificationService.addObserver(u2);
        notificationService.addObserver(u3);

        notificationService.notifyObservers("Something new!");
    }
}