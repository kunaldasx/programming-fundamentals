// Java program to implement the use of Interfaces.
interface Animal {
    void walk();
}

class Horse implements Animal {
    public void walk() {
        System.out.println("Horse walks on 4 legs");
    }
}

class Chicken implements Animal {
    public void walk() {
        System.out.println("Chicken walks on 2 legs");
    }
}

public class Interfaces {
    public static void main(String args[]) {
        Horse horse = new Horse();
        horse.walk();

        Chicken chicken = new Chicken();
        chicken.walk();
    }
}
