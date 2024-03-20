// Java program to demonstrate the three different types of Constructors.
class Student {
    String name;
    int age;

    // Non-Parameterized Constructor
    Student() {
        System.out.println("Constructor Called");
    }

    // Parameterized Constructor
    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Copy Constructor
    Student(Student student) {
        this.name = student.name;
        this.age = student.age;
    }

    public void printInfo() {
        System.out.println("The name of this student is " + this.name);
        System.out.println("The age of this student is " + this.age);
    }
}

public class Constructors {
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.name = "Shradha";
        s1.age = 20;
        s1.printInfo();

        Student s2 = new Student("Aman", 24);
        s2.printInfo();

        Student s3 = new Student(s1);
        s3.printInfo();
    }
}
