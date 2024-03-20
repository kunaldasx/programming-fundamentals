// Java program to demonstrate run time polymorphism (method overriding).
class Shape {
    public void area() {
        System.out.println("Displays area of Shape");
    }
}

class Triangle extends Shape {
    public void area(int base, int height) {
        System.out.println("Area = " + (0.5 * base * height));
    }
}

class Circle extends Shape {
    public void area(int radius) {
        System.out.println("Area = " + (3.14 * radius * radius));
    }
}

public class RunTime_polym {
    public static void main(String[] args) {
        Triangle triangle = new Triangle();
        triangle.area(5, 7);

        Circle circle = new Circle();
        circle.area(4);
    }
}
