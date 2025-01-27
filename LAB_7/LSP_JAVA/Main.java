package LSP_JAVA;

public class Main {
    public static void main(String[] args) {
        Rectangle rectangle = new Rectangle();

        rectangle.setWidth(5);
        rectangle.setHeight(10);
        System.out.println("Rectangle area: " + rectangle.getArea());

        Square square = new Square();

        square.setWidth(5);
        System.out.println("Square area: " + square.getArea());

        square.setHeight(10);
        System.out.println("Square area: " + square.getArea());
    }
}