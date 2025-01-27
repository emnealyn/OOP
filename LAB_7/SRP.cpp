#include <string>
#include <iostream>

// Klasa użytkownika
class User {
private:
   std::string name;
   std::string uuid;
public:
    User(const std::string &name, const std::string &uuid) : name(name), uuid(uuid) {}

    std::string getName() {
        return name;
    }

    std::string getUUID() {
        return uuid;
    }

};

// Klasa odpowiedzialna za zapis użytkownika
class UserSaver {
private:
    User user;
public:
    UserSaver(User user) : user(user) {}

    void saveUser() {
        std::cout << "Name: " << user.getName() << std::endl;
        std::cout << "UUID: " << user.getUUID() << std::endl;
        std::cout << "User saved" << std::endl;
    }

};


int main() {
    User user = User("Jan", "1234-5678-9012-3456");
    UserSaver userSaver(user);

    userSaver.saveUser();
   
    return 0;
}