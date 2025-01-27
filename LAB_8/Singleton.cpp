#include <iostream>

class DatabaseConnection {
    private:
        static DatabaseConnection* instancePtr;

        DatabaseConnection() {}

    public:
        DatabaseConnection(const DatabaseConnection& obj) = delete;

        void operator=(const DatabaseConnection& obj) = delete;

        static DatabaseConnection* getInstance();
      
};

DatabaseConnection* DatabaseConnection::instancePtr = nullptr;;

DatabaseConnection *DatabaseConnection::getInstance()
{
    if(instancePtr==nullptr){
        instancePtr = new DatabaseConnection();
    }
    return instancePtr;
}



int main() {
    DatabaseConnection* connection1 = DatabaseConnection::getInstance();
    DatabaseConnection* connection2 = DatabaseConnection::getInstance();
    
    std::cout << "Are both instances the same? " << (connection1 == connection2) << std::endl;

    return 0;
}