import java.util.ArrayList;
import java.util.List;

interface FileSystemComponent {
    void display(String indent);
}

class File implements FileSystemComponent {
    private final String name;

    public File(String name) {
        this.name = name;
    }

    @Override
    public void display(String indent) {
        System.out.println(indent + "- File: " + name);
    }
}

class Directory implements FileSystemComponent {
    private final String name;
    private final List<FileSystemComponent> components = new ArrayList<>();

    public Directory(String name) {
        this.name = name;
    }

    public void addComponent(FileSystemComponent component) {
        components.add(component);
    }

    public void removeComponent(FileSystemComponent component) {
        components.remove(component);
    }

    @Override
    public void display(String indent) {
        System.out.println(indent + "+ Directory: " + name);
        for (FileSystemComponent component : components) {
            component.display(indent + "\t");
        }
    }
}

public class Composite {
    public static void main(String[] args) {
        Directory root = new Directory("root");
        Directory folder1 = new Directory("folder1");
        Directory folder2 = new Directory("folder2");
        Directory folder3 = new Directory("folder3");

        File file1 = new File("file1.txt");
        File file2 = new File("file2.txt");
        File file3 = new File("file3.txt");
        File file4 = new File("file4.txt");
        File file5 = new File("file5.txt");
        File file5 = new File("file6.txt");

        root.addComponent(folder1);
        root.addComponent(file1);
        root.addComponent(file6);

        folder1.addComponent(folder2);
        folder1.addComponent(folder3);
        folder1.addComponent(file2);

        folder2.addComponent(file3);

        folder3.addComponent(file4);
        folder3.addComponent(file5);

        root.display("");

        System.out.println("\nRemoving Directory folder2\n");

        folder1.removeComponent(folder2);
        
        root.display("");
    }
}