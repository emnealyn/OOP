#include <iostream>
#include <string>

class State1; 

class ATM {
    private:
        std::string state;

    public:
        void setState(const std::string& newState) {
            state = newState;
        }

        std::string getState() const {
            return state;
        }

        void changeState(State1* state);
};

class State1 {
    public:
        virtual void handle(ATM& atm) = 0;
};

void ATM::changeState(State1* state) {
    state->handle(*this);
}


class WaitingForCardState : public State1 {
public:
    void handle(ATM& atm) override {
        atm.setState("Waiting for card");
    }
};

class PINVerificationState : public State1 {
public:
    void handle(ATM& atm) override {
        atm.setState("Checking PIN");
    }
};

class WithdrawalState : public State1 {
public:
    void handle(ATM& atm) override {
        atm.setState("Cash withdrawal");
    }
};

int main() {
    ATM* atm = new ATM();
    WaitingForCardState* waitingForCard = new WaitingForCardState();
    PINVerificationState* verifyPIN = new PINVerificationState();
    WithdrawalState* withdrawal = new WithdrawalState();

    atm->changeState(waitingForCard);
    std::cout << atm->getState() << std::endl;

    atm->changeState(verifyPIN);
    std::cout << atm->getState() << std::endl;

    atm->changeState(withdrawal);
    std::cout << atm->getState() << std::endl;

    delete atm;
    delete waitingForCard;
    delete verifyPIN;
    delete withdrawal;

    return 0;
}