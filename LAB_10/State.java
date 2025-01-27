class ATM {
    private String state;

    public void setState(String state) {
        this.state = state;
    }

    public String getState() {
        return state;
    }

    public void changeState(State1 state) {
        state.handle(this);
    }
}

interface State1 {
    void handle(ATM atm);
}

class WaitingForCardState implements State1 {
    @Override
    public void handle(ATM atm) {
        atm.setState("Waiting for card");
    }
}

class PINVerificationState implements State1 {
    @Override
    public void handle(ATM atm) {
        atm.setState("Checking PIN");
    }
}

class WithdrawalState implements State1 {
    @Override
    public void handle(ATM atm) {
        atm.setState("Cash withdrawal");
    }
}



public class State {
    public static void main(String[] args) {
        ATM atm = new ATM();

        State1 waitingForCard = new WaitingForCardState();
        State1 verifyPIN = new PINVerificationState();
        State1 withdrawal = new WithdrawalState();

        atm.changeState(waitingForCard);
        System.out.println(atm.getState());

        atm.changeState(verifyPIN);
        System.out.println(atm.getState());

        atm.changeState(withdrawal);
        System.out.println(atm.getState());
    }
}