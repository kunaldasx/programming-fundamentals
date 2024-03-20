// Basic Java program to demonstrate Classes and Object

class Student {
    String name;
    int age;

    public void printInfo() {
        System.out.println("The name of this student is " + this.name);
        System.out.println("The age of this student is " + this.age);
    }
}

public class Class_Object {
    public static void main(String[] args) {
        // Creating the first object
        Student s1 = new Student();
        s1.name = "Aman";
        s1.age = 22;
        s1.printInfo();

        // Creating the second object
        Student s2 = new Student();
        s2.name = "Shradha";
        s2.age = 20;
        s2.printInfo();
    }
}