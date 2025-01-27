package DIP_JAVA;

public class Notification {
    private final MessageService messageService;

    public Notification(MessageService messageService) {
        this.messageService = messageService;
    }

    public void notify(String message) {
        System.out.println("Sending notification: " + message);

        System.out.println("Also sending email notification: ");
        messageService.sendMessage(message);
    }
}