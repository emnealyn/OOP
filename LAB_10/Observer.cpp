
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


// Interfejs obserwatora
class Observer {
    public:
        virtual void update(std::string message)=0;

};

// Konkretna klasa obserwatora
class User : public Observer {
    private:
        std::string name;

    public:
        User(std::string name) {
            this->name = name;
        }

        void update(std::string message) {
            std::cout << name << " received message: " << message << std::endl;
        }

};

// Klasa podmiotu
class NotificationService {
    private:
        std::vector<Observer*> observers;
    public:
        void addObserver(Observer* observer) {
            observers.push_back(observer);
        }

        void removeObserver(Observer* observer) {
            observers.erase(std::find(observers.begin(), observers.end(), observer));
        }

        void notifyObservers(std::string message) {
            for (Observer* observer : observers) {
                observer->update(message);
            }
        }

};

int main() {
    User *u1 = new User("User 1");
    User *u2 = new User("User 2");
    User *u3 = new User("User 3");

    NotificationService *notificationService = new NotificationService();
    notificationService->addObserver(u1);
    notificationService->addObserver(u2);
    notificationService->addObserver(u3);

    notificationService->notifyObservers("Something new!");

    delete user1;
    delete user2;
    delete user3;
    delete notificationService;
   
    return 0;
}
