// Java program to demonstrate Multilevel Inheritance.

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

class EquilateralTriangle extends Triangle {
    public void printInfo() {
        System.out.println("You have accessed the base class");
    }
}

public class Multilevel_Inheritance {
    public static void main(String[] args) {
        EquilateralTriangle obj = new EquilateralTriangle();
        obj.display();
        obj.area(5, 7);
        obj.printInfo();
    }

}
