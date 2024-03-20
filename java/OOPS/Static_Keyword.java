// Java program to implement the use of Static Kewword.
class Student {
    static String school;
    String name;

    static void setInfo() {
        school = "new school";
    }
}

public class Static_Keyword {
    public static void main(String args[]) {
        Student.school = "JMV";
        Student student = new Student();
        student.name = "Shradha";
        System.out.println(student.name);
        System.out.println(Student.school);
        Student.setInfo();
        System.out.println(Student.school);

    }
}
