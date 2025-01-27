package DIP_JAVA;

public class EmailService implements MessageService {
    private final String email;

    public EmailService(String email) {
        this.email = email;
    }
    @Override
    public void sendMessage(String message) {
        System.out.println("Sending email to " + email + ": " + message);
    }
}