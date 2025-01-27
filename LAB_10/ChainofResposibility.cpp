#include <iostream>
#include <string>
#include <memory>

class SupportHandler {
protected:
    SupportHandler* nextHandler;

public:
    virtual ~SupportHandler() = default;

    void setNextHandler(SupportHandler* next) {
        nextHandler = next;
    }

    virtual void handleRequest(const std::string& issue) = 0;
};

class ConsultantHandler : public SupportHandler {
public:
    void handleRequest(const std::string& issue) override {
        if (issue == "simple issue") {
            std::cout << "Consultant: Resolved the simple issue.\n";
        } else {
            std::cout << "Consultant: Escalating the issue to the manager.\n";
            if (nextHandler) {
                nextHandler->handleRequest(issue);
            }
        }
    }
};

class ManagerHandler : public SupportHandler {
public:
    void handleRequest(const std::string& issue) override {
        if (issue == "complex issue") {
            std::cout << "Manager: Resolved the complex issue.\n";
        } else {
            std::cout << "Manager: Escalating the issue to technical support.\n";
            if (nextHandler) {
                nextHandler->handleRequest(issue);
            }
        }
    }
};

class TechnicalSupportHandler : public SupportHandler {
public:
    void handleRequest(const std::string& issue) override {
        std::cout << "Technical Support: Resolved the technical issue.\n";
    }
};

int main() {
    SupportHandler* consultant = new ConsultantHandler();
    SupportHandler* manager = new ManagerHandler();
    SupportHandler* technicalSupport = new TechnicalSupportHandler();

    consultant->setNextHandler(manager);
    manager->setNextHandler(technicalSupport);

    std::cout << "Processing 'simple issue':\n";
    consultant->handleRequest("simple issue");

    std::cout << "\nProcessing 'complex issue':\n";
    consultant->handleRequest("complex issue");

    std::cout << "\nProcessing 'technical issue':\n";
    consultant->handleRequest("technical issue");

    delete consultant;
    delete manager;
    delete technicalSupport;

    return 0;
}