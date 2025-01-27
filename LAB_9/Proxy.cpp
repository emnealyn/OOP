#include <iostream>
#include <string>

// Interfejs dostępu do danych
class DataAccess {
    virtual void accessData(std::string user) = 0;
};

// Klasa rzeczywista (RealSubject)
class RealDataAccess : public DataAccess {
public:
    void accessData(std::string user) override {
        std::cout << "Access granted for user: " << user << std::endl;
    }
};

// Klasa Proxy
class DataAccessProxy : public DataAccess {
private:
    RealDataAccess* realDataAccess;
    const std::string AUTHORIZED_USER = "admin";

public:
    DataAccessProxy() {
        realDataAccess = new RealDataAccess();
    }

    void accessData(std::string user) override {
        std::cout << "Accessing data by: " << user << "..." << std::endl;

        if (isAuthorized(user)) {
            realDataAccess->accessData(user);
        } else {
            std::cout << "Access denied for user: " << user << std::endl;
        }
    }

    bool isAuthorized(std::string user) {
        return user == AUTHORIZED_USER;
    }
};

// Klient
int main() {
    DataAccessProxy* dataAccessProxy = new DataAccessProxy();
   
    // Dostęp dozwolony
    dataAccessProxy->accessData("admin");

    std::cout << std::endl;
    
    // Dostęp zabroniony
    dataAccessProxy->accessData("user");

    return 0;
}