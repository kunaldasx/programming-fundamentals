// Java program to demonstrate Single Inheritance.
class Shape {
    public void display() {
        System.out.println("Displays area of Shape");
    }
}

class Triangle extends Shape {
    public void area(int base, int height) {
        System.out.println("Area = " + (0.5 * base * height));
    }
}

public class Single_Inheritance {
    public static void main(String[] args) {
        Triangle triangle = new Triangle();
        triangle.display();
        triangle.area(5, 7);
    }
}
