// Java program to demonstrate Compile time polymorphism (Method overloading).
class Student {
    String name;
    int age;
    float income;

    public void displayInfo(String name) {
        System.out.println(name);
    }

    public void displayInfo(int age) {
        System.out.println(age);
    }

    public void displayInfo(String name, int age) {
        System.out.println(name + " " + age);
    }

    public float displayInfo() {
        return 500000;
    }

}

public class CompileTime_polym {
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.name = "Shradha";
        s1.age = 20;
        s1.displayInfo(s1.name);
        s1.displayInfo(s1.age);
        s1.displayInfo(s1.name, s1.age);

        s1.income = s1.displayInfo();
        System.out.println(s1.income);
    }
}
