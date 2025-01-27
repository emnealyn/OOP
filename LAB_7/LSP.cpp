#include <iostream>


class Rectangle {
    private:
        double width;
        double height;
    
    public:
        void setWidth(double width) {
            this->width = width;
        }

        void setHeight(double height) {
            this->height = height;
        }

        double getArea() {
            return width * height;
        }
};

class Square : public Rectangle {
    public:
        void setWidth(double width) {
            Rectangle::setWidth(width);
            Rectangle::setHeight(width);
        }

        void setHeight(double height) {
            setWidth(height);
        }
};


int main() {
    Rectangle rectangle;
    rectangle.setWidth(5);
    rectangle.setHeight(10);

    std::cout << "Rectangle area: " << rectangle.getArea() << std::endl;

    Square square;
    square.setWidth(5);

    std::cout << "Square area: " << square.getArea() << std::endl;

    square.setHeight(10);

    std::cout << "Square area: " << square.getArea() << std::endl;

    return 0;
}