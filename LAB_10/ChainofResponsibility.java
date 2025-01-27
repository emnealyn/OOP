abstract class SupportHandler {
    protected SupportHandler nextHandler;

    public void setNextHandler(SupportHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    public abstract void handleRequest(String issue);
}

class ConsultantHandler extends SupportHandler {
    @Override
    public void handleRequest(String issue) {
        if (issue.equalsIgnoreCase("simple issue")) {
            System.out.println("Consultant: Resolved the simple issue.");
        } else {
            System.out.println("Consultant: Escalating the issue to the manager.");
            if (nextHandler != null) {
                nextHandler.handleRequest(issue);
            }
        }
    }
}

class ManagerHandler extends SupportHandler {
    @Override
    public void handleRequest(String issue) {
        if (issue.equalsIgnoreCase("complex issue")) {
            System.out.println("Manager: Resolved the complex issue.");
        } else {
            System.out.println("Manager: Escalating the issue to technical support.");
            if (nextHandler != null) {
                nextHandler.handleRequest(issue);
            }
        }
    }
}

class TechnicalSupportHandler extends SupportHandler {
    @Override
    public void handleRequest(String issue) {
        System.out.println("Technical Support: Resolved the technical issue.");
    }
}

public class ChainOfResponsibility {
    public static void main(String[] args) {
        SupportHandler consultant = new ConsultantHandler();
        SupportHandler manager = new ManagerHandler();
        SupportHandler technicalSupport = new TechnicalSupportHandler();

        consultant.setNextHandler(manager);
        manager.setNextHandler(technicalSupport);

        System.out.println("Processing 'simple issue':");
        consultant.handleRequest("simple issue");
        
        System.out.println("\nProcessing 'complex issue':");
        consultant.handleRequest("complex issue");
        
        System.out.println("\nProcessing 'technical issue':");
        consultant.handleRequest("technical issue");
    }
}