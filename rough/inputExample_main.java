import java.util.ArrayList;
import java.util.Scanner;

public class inputExample_main {
    public static void main(String[] args) {
        // Create a Scanner object to read from the console
        Scanner scanner = new Scanner(System.in);
        
        // Create an ArrayList to store the integers
        ArrayList<Integer> arr = new ArrayList<>();
        
        // Prompt the user to enter integers
        System.out.println("Enter integers separated by spaces:");

        // Read the entire line of input
        String inputLine = scanner.nextLine();
        
        // Split the input line into individual string representations of integers
        String[] tokens = inputLine.trim().split("\\s+");
        
        // Parse each token as an integer and add it to the list
        for (String token : tokens) {
            arr.add(Integer.parseInt(token));
        }

        // Close the scanner
        scanner.close();

        // Output the integers to verify they were read correctly
        System.out.print("You entered: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
