#include <iostream>
#include <stack>
#include <vector>
#include <string>


class Command1 {
    public:
        virtual void execute()=0;
        virtual void undo()=0;
};

class TextEditor {
    private:
        std::vector<std::string>* text = new std::vector<std::string>();

    public:
        void addText(std::string newText) {
            text->push_back(newText);
            std::cout << "Added text: " << newText << std::endl;
    }

        void removeText(int length) {
            std::string removedText = text->back();
            text->pop_back();
            std::cout << "Removed text: " << removedText << std::endl;
        }

        std::string getText() {
            std::string result = "";
            for (std::string s : *text) {
                result += s;
            }
            return result;
        }
};

class AddTextCommand : public Command1 {
    private:
        TextEditor* editor;
        std::string text;

    public:
        AddTextCommand(TextEditor* editor, std::string text) {
            this->editor = editor;
            this->text = text;
        }

        void execute() override {
            editor->addText(text);
        }

        void undo() override {
            editor->removeText(text.length());
        }
};

class CommandManager {
    private:
        std::stack<Command1*>* commandHistory = new std::stack<Command1*>();
        std::stack<Command1*>* redoHistory = new std::stack<Command1*>();

    public:
        void executeCommand(Command1* command) {
            command->execute();
            commandHistory->push(command);
            while (!redoHistory->empty()) {
                redoHistory->pop();
            }
        }

        void undo() {
            if (!commandHistory->empty()) {
                Command1* command = commandHistory->top();
                commandHistory->pop();
                command->undo();
                redoHistory->push(command);
            } else {
                std::cout << "No commands to undo!" << std::endl;
            }
    }

        void redo() {
            if (!redoHistory->empty()) {
                Command1* command = redoHistory->top();
                redoHistory->pop();
                command->execute();
                commandHistory->push(command);
            } else {
                std::cout << "No commands to redo!" << std::endl;
            }
        }
};


int main() {
    TextEditor* editor = new TextEditor();

    CommandManager* manager = new CommandManager();

    Command1* addHello = new AddTextCommand(editor, "Hello ");
    Command1* addWorld = new AddTextCommand(editor, "World!");

    manager->executeCommand(addHello);
    manager->executeCommand(addWorld);
    std::cout << "Current text: " << editor->getText() << std::endl;

    manager->undo();
    std::cout << "After undo: " << editor->getText() << std::endl;

    manager->redo();
    std::cout << "After redo: " << editor->getText() << std::endl;

    delete editor;
    delete manager;
    delete addHello;
    delete addWorld;

    return 0;
}