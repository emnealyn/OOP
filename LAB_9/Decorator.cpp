#include <iostream>

// Interfejs okna
class Window {
public:
    virtual void render() = 0;
    virtual ~Window() {}
};

// Klasa bazowa
class SimpleWindow : public Window {
public:
    void render() override {
        std::cout << "Rendering simple window" << std::endl;
    }
};


// Dekorator
class WindowDecorator : public Window {
protected:
    Window* decoratedWindow;

public:
    WindowDecorator(Window* window) : decoratedWindow(window) {}

    void render() override {
        decoratedWindow->render();
    }
};


// Konkretne dekoratory
class BorderedWindow : public WindowDecorator {
public:
    BorderedWindow(Window* window) : WindowDecorator(window) {}

    void render() override {
        WindowDecorator::render();
        std::cout << "Now window has borders" << std::endl;
    }

};


class ScrollableWindow : public WindowDecorator {
public:
    ScrollableWindow(Window* window) : WindowDecorator(window) {}

    void render() override {
        WindowDecorator::render();
        std::cout << "Now window is scrollable" << std::endl;
    }

};

// Window Builder
class WindowBuilder {
private:
    Window* window;

public:
    // Start with a simplest window
    WindowBuilder() {
        window = new SimpleWindow();
    }

    WindowBuilder addBorders() {
        window = new BorderedWindow(window);
        return *this;
    }

    WindowBuilder addScroll() {
        window = new ScrollableWindow(window);
        return *this;
    }

    Window* build() {
        return window;
    }
};


// Klient
int main() {
    std::cout << "\n====================================\n" << std::endl;

    Window* simpleWindow = WindowBuilder().build();

    std::cout << "Simple Window:" << std::endl;
    simpleWindow->render();
    
    std::cout << "\n====================================\n" << std::endl;

    Window* borderedWindow = WindowBuilder().addBorders().build();

    std::cout << "Bordered Window:" << std::endl;
    borderedWindow->render();

    std::cout << "\n====================================\n" << std::endl;

    Window* scrollableWindow = WindowBuilder().addScroll().build();

    std::cout << "Scrollable Window:" << std::endl;
    scrollableWindow->render();

    std::cout << "\n====================================\n" << std::endl;

    Window* decoratedWindow = WindowBuilder().addBorders().addScroll().build();

    std::cout << "Bordered and Scrollable Window:" << std::endl;
    decoratedWindow->render();

    std::cout << "\n====================================\n" << std::endl;
    
    return 0;
}