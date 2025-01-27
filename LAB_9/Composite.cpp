#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class FileSystemComponent {
public:
    virtual void display(std::string indent) = 0;
};


class File : public FileSystemComponent {
private:
    std::string name;

public:
    File(std::string name) : name(name) {}

    void display(std::string indent) override {
        std::cout << indent << "- File: " << name << std::endl;
    }
};


class Directory : public FileSystemComponent {
private:
    std::string name;
    std::vector<FileSystemComponent*> components = std::vector<FileSystemComponent*>();

public:
    Directory(std::string name) : name(name) {}

    void addComponent(FileSystemComponent* component) {
        components.push_back(component);
    }

    void removeComponent(FileSystemComponent* component) {
        components.erase(std::remove(components.begin(), components.end(), component), components.end());
    }

    void display(std::string indent) override {
        std::cout << indent << "+ Directory: " << name << std::endl;
        for (auto component : components) {
            component->display(indent + "\t");
        }
    }
};

int main() {
    Directory* root = new Directory("root");
    Directory* folder1 = new Directory("folder1");
    Directory* folder2 = new Directory("folder2");
    Directory* folder3 = new Directory("folder3");

    File* file1 = new File("file1.txt");
    File* file2 = new File("file2.txt");
    File* file3 = new File("file3.txt");
    File* file4 = new File("file4.txt");
    File* file5 = new File("file5.txt");
    File* file6 = new File("file6.txt");

    root->addComponent(folder1);
    root->addComponent(file1);
    root->addComponent(file6);

    folder1->addComponent(folder2);
    folder1->addComponent(folder3);
    folder1->addComponent(file2);

    folder2->addComponent(file3);

    folder3->addComponent(file4);
    folder3->addComponent(file5);

    root->display("");

    std::cout << "\nRemoving Directory folder2\n" << std::endl;

    folder1->removeComponent(folder2);

    root->display("");
}