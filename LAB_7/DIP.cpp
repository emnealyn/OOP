#include <iostream>
#include <string>


class MessageService {
    public:
        virtual void sendMessage(const std::string &message) = 0;

};

class EmailService : public MessageService {    
    private:
        std::string email;
        
    public:
        EmailService(const std::string &email) : email(email) {}

        void sendMessage(const std::string &message) override {
            std::cout << "Sending email to " << email << ": " << message << std::endl;
        }

};

class Notification {
    private:
        EmailService emailService;
    public:
        Notification(EmailService emailService) : emailService(emailService) {}

    void notify(std::string message) {
       std::cout << "Sending notification: " << message << std::endl;

       std::cout << "Also sending email notification" << std::endl;
       emailService.sendMessage(message);
    }
};

int main() {
    EmailService emailService("example@example.com");
    
    Notification(emailService).notify("Welcome to SOLID");

    return 0;
}