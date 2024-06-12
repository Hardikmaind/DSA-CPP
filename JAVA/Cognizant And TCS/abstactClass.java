// Abstract class
abstract class Animal {
    // Abstract method (does not have a body)
    public abstract void makeSound();

    // Regular method
    public void sleep() {
        System.out.println("This animal is sleeping.");
    }
}

// Subclass (inherits from Animal)
class Dog extends Animal {
    // Providing implementation for the abstract method
    public void makeSound() {
        System.out.println("Bark");
    }
}

// Another subclass (inherits from Animal)
class Cat extends Animal {
    // Providing implementation for the abstract method
    public void makeSound() {
        System.out.println("Meow");
    }
}

public class abstactClass {
    public static void main(String[] args) {
        Animal myDog = new Dog();
        Animal myCat = new Cat();
 
        myDog.makeSound(); // Output: Bark
        myDog.sleep();     // Output: This animal is sleeping.

        myCat.makeSound(); // Output: Meow
        myCat.sleep();     // Output: This animal is sleeping.
    }
}










