import java.util.ArrayList;
import java.util.Stack;


interface Command1 {
    void execute();
    void undo();
}

class TextEditor {
    private final ArrayList<String> text = new ArrayList<>();

    public void addText(String newText) {
        text.add(newText);
        System.out.println("Added tekxt: " + newText);
    }

    public void removeText(int length) {
        String removedText = text.removeLast();
        System.out.println("Removed text: " + removedText);
    }

    public String getText() {
        return String.join("", text);
    }
}

class AddTextCommand implements Command1 {
    private final TextEditor editor;
    private final String text;

    public AddTextCommand(TextEditor editor, String text) {
        this.editor = editor;
        this.text = text;
    }

    @Override
    public void execute() {
        editor.addText(text);
    }

    @Override
    public void undo() {
        editor.removeText(text.length());
    }
}

class CommandManager {
    private final Stack<Command1> commandHistory = new Stack<>();
    private final Stack<Command1> redoStack = new Stack<>();

    public void executeCommand(Command1 command) {
        command.execute();
        commandHistory.push(command);
        redoStack.clear();
    }

    public void undo() {
        if (!commandHistory.isEmpty()) {
            Command1 command = commandHistory.pop();
            command.undo();
            redoStack.push(command);
        } else {
            System.out.println("No commands to undo!");
        }
    }

    public void redo() {
        if (!redoStack.isEmpty()) {
            Command1 command = redoStack.pop();
            command.execute();
            commandHistory.push(command);
        } else {
            System.out.println("No commands to redo!");
        }
    }
}

public class Command {
    public static void main(String[] args) {
        TextEditor editor = new TextEditor();

        CommandManager manager = new CommandManager();

        Command1 addHello = new AddTextCommand(editor, "Hello ");
        Command1 addWorld = new AddTextCommand(editor, "World!");

        manager.executeCommand(addHello);
        manager.executeCommand(addWorld);
        System.out.println("Current text: " + editor.getText());

        manager.undo();
        System.out.println("After undo: " + editor.getText());

        manager.redo();
        System.out.println("After redo: " + editor.getText());
    }
}