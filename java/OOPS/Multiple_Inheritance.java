// Java program to implement Multiple Inheritance using Interfaces
interface Animal {
    void walk();
}

interface Herbivore {
    void eat();
}

class Horse implements Animal, Herbivore { // Here two one derived class is formed from two base classes
    public void walk() {
        System.out.println("Horse walks on 4 legs");
    }

    public void eat() {
        System.out.println("Horse eats plants");
    }
}

public class Multiple_Inheritance {
    public static void main(String[] args) {
        Horse horse = new Horse();
        horse.walk();
        horse.eat();
    }
}
