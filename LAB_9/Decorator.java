// Interfejs okna
interface Window {
    void render();
}

// Klasa bazowa
class SimpleWindow implements Window {
    @Override
    public void render() {
        System.out.println("Rendering simple window");
    }
}

// Dekorator
abstract class WindowDecorator implements Window {
    protected Window decoratedWindow;

    public WindowDecorator(Window decoratedWindow) {
        this.decoratedWindow = decoratedWindow;
    }

    @Override
    public void render() {
        decoratedWindow.render();
    }
}

// Konkretne dekoratory
class BorderedWindow extends WindowDecorator {
    public BorderedWindow(Window decoratedWindow) {
        super(decoratedWindow);
    }

    @Override
    public void render() {
        super.render();
        System.out.println("Now window has borders");
    }
}

class ScrollableWindow extends WindowDecorator {
    public ScrollableWindow(Window decoratedWindow) {
        super(decoratedWindow);
    }

    @Override
    public void render() {
        super.render();
        System.out.println("Now window is scrollable");
    }
}

// Window Builder
class WindowBuilder {
    private Window window;

    // Start with simplest window
    public WindowBuilder() {
        window = new SimpleWindow();
    }

    public WindowBuilder addBorder() {
        window = new BorderedWindow(window);
        return this;
    }

    public WindowBuilder addScroll() {
        window = new ScrollableWindow(window);
        return this;
    }

    public Window build() {
        return window;
    }
}

// Klient
public class Decorator {
    public static void main(String[] args) {
        System.out.println("\n====================================\n");

        Window simpleWindow = new WindowBuilder().build();

        System.out.println("Simple Window:");
        simpleWindow.render();
        
        System.out.println("\n====================================\n");

        Window borderedWindow = new WindowBuilder().addBorder().build();

        System.out.println("Bordered Window:");
        borderedWindow.render();

        System.out.println("\n====================================\n");

        Window scrollableWindow = new WindowBuilder().addScroll().build();

        System.out.println("Scrollable Window:");
        scrollableWindow.render();

        System.out.println("\n====================================\n");

        Window decoratedWindow = new WindowBuilder().addBorder().addScroll().build();

        System.out.println("Bordered and Scrollable Window:");
        decoratedWindow.render();

        System.out.println("\n====================================\n");
    }
}