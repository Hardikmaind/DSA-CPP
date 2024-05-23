// import java.util.Scanner;

// public class ArrayInputWithoutSize {
//     public static void main(String[] args) {
//         Scanner scanner = new Scanner(System.in);

//         // Taking array input as a line of space-separated integers
//         System.out.print("Enter elements of the array separated by spaces: ");
//         String inputLine = scanner.nextLine();
        
//         // Splitting the input line into string elements
//         String[] stringElements = inputLine.split(" ");
        
//         // Parsing string elements to integers and storing them in an array
//         int[] array = new int[stringElements.length];
//         for (int i = 0; i < stringElements.length; i++) {
//             array[i] = Integer.parseInt(stringElements[i]);
//         }

//         // Printing the array to confirm the input
//         System.out.print("You entered the array: ");
//         for (int element : array) {
//             System.out.print(element + " ");
//         }
//         System.out.println();
        
//         // Close the scanner
//         scanner.close();
//     }
// }








import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read from the console
        Scanner scanner = new Scanner(System.in);
        
        // Create an ArrayList to store the integers
        ArrayList<Integer> numbers = new ArrayList<>();
        
        // Prompt the user to enter integers
        System.out.println("Enter integers separated by spaces:");

        // Read the entire line of input
        String inputLine = scanner.nextLine();
        
        // Split the input line into individual string representations of integers
        String[] tokens = inputLine.split(" ");
        
        // Parse each token as an integer and add it to the list
        for (String token : tokens) {
            try {
                int number = Integer.parseInt(token);
                numbers.add(number);
            } catch (NumberFormatException e) {
                // Handle the case where the token is not a valid integer
                System.out.println("Invalid input: " + token);
            }
        }

        // Close the scanner
        scanner.close();

        // Output the integers to verify they were read correctly
        System.out.println("You entered: " + numbers);
    }
}
