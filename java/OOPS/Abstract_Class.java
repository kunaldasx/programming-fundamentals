// Java progarm to demonstrate the use of abstract class.
abstract class Animal {
    abstract void walk();

    void breathe() {
        System.out.println("This animal breathes air");
    }

    Animal() {
        System.out.println("You are about to create an animal");
    }
}

class Horse extends Animal {
    Horse() {
        System.out.println("Wow! You have created a horse");
    }

    void walk() {
        System.out.println("Horse walks on  4 legs");
    }
}

class Chicken extends Animal {
    Chicken() {
        System.out.println("Wow! You have created a Chicken");
    }

    void walk() {
        System.out.println("Chicken walks on  2 legs");
    }
}

public class Abstract_Class {
    public static void main(String args[]) {
        Horse horse = new Horse();
        horse.walk();
        horse.breathe();

        System.out.println();
        Chicken chicken = new Chicken();
        chicken.walk();
        chicken.breathe();
    }
}
