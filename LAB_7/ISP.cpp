#include <iostream>


class Printer {
    virtual void print() = 0;
};

class Scanner {
    virtual void scan() = 0;
};

class MultiFunctionMachine : Printer, Scanner {
    public:
        void print() override {
            std::cout << "Printing" << std::endl;
        }

        void scan() override {
            std::cout << "Scanning" << std::endl;
        }
};

int main() {
    MultiFunctionMachine multiFunctionMachine;
    multiFunctionMachine.print();
    multiFunctionMachine.scan();

    return 0;
}