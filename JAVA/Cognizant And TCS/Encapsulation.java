// Class with encapsulated fields
class Person {
    // Private fields
    private String name;
    private int age;

    // Constructor
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Getter for name
    public String getName() {
        return name;
    }

    // Setter for name
    public void setName(String name) {
        this.name = name;
    }

    // Getter for age
    public int getAge() {
        return age;
    }

    // Setter for age
    public void setAge(int age) {
        if (age > 0) { // Adding validation logic
            this.age = age;
        } else {
            System.out.println("Age must be positive.");
        }
    }

    // Method to display person details
    public void display() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

public class Encapsulation {
    public static void main(String[] args) {
        // Creating an object of Person class
        Person person = new Person("Alice", 30);

        // Accessing fields using getters
        System.out.println("Name: " + person.getName()); // Output: Name: Alice
        System.out.println("Age: " + person.getAge());   // Output: Age: 30

        // Modifying fields using setters
        person.setName("Bob");
        person.setAge(35);

        // Displaying updated details
        person.display(); // Output: Name: Bob, Age: 35

        // Trying to set an invalid age
        person.setAge(-5); // Output: Age must be positive.
    }
}
