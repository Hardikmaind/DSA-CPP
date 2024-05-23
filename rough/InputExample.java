import java.util.Scanner;

public class InputExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking string input
        System.out.print("Enter a string: ");
        String str = scanner.nextLine();
        System.out.println("You entered: " + str);

        // Taking integer input
        System.out.print("Enter an integer: ");
        while (!scanner.hasNextInt()) {
            System.out.println("That's not a valid integer!");
            System.out.print("Enter an integer: ");
            scanner.next(); // Discard invalid input
        }
        int num = scanner.nextInt();
        System.out.println("You entered: " + num);

        // Taking boolean input
        System.out.print("Enter a boolean (true/false): ");
        while (!scanner.hasNextBoolean()) {
            System.out.println("That's not a valid boolean!");
            System.out.print("Enter a boolean (true/false): ");
            scanner.next(); // Discard invalid input
        }
        boolean bool = scanner.nextBoolean();
        System.out.println("You entered: " + bool);

        // Close the scanner
        scanner.close();
    }
}
