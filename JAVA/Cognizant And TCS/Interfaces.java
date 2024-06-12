// Interface
interface Animal {
    // Abstract method (without a body)
    void makeSound();

    // Default method (with a body)
    default void sleep() {
        System.out.println("This animal is sleeping.");
    }
}

// Another interface
interface Pet {
    // Abstract method
    void play();
}

// Class implementing the Animal and Pet interfaces
class Dog implements Animal, Pet {
    // Providing implementation for the makeSound() method
    public void makeSound() {
        System.out.println("Bark");
    }

    // Providing implementation for the play() method
    public void play() {
        System.out.println("Dog is playing.");
    }
}

// Another class implementing the Animal and Pet interfaces
class Cat implements Animal, Pet {
    // Providing implementation for the makeSound() method
    public void makeSound() {
        System.out.println("Meow");
    }

    // Providing implementation for the play() method
    public void play() {
        System.out.println("Cat is playing.");
    }
}

public class Interfaces {
    public static void main(String[] args) {
        Animal myDog = new Dog();
        Animal myCat = new Cat();

        myDog.makeSound(); // Output: Bark
        myDog.sleep();     // Output: This animal is sleeping.

        myCat.makeSound(); // Output: Meow
        myCat.sleep();     // Output: This animal is sleeping.

        Pet myPetDog = new Dog();
        Pet myPetCat = new Cat();

        myPetDog.play();   // Output: Dog is playing.
        myPetCat.play();   // Output: Cat is playing.
    }
}


