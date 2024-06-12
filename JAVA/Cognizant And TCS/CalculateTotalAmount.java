import java.util.Scanner;

public class CalculateTotalAmount {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the input line
        String input = scanner.nextLine();
        
        // Split the input line into parts
        String[] parts = input.split(" ");
        
        // Convert parts to integers
        int[] counts = new int[6];
        for (int i = 0; i < 6; i++) {
            counts[i] = Integer.parseInt(parts[i]);
        }
        
        // Denomination values in dollars
        double[] values = {0.20, 0.40, 1.00, 2.00, 5.00, 10.00};
        
        // Calculate the total amount
        double totalAmount = 0.0;
        for (int i = 0; i < 6; i++) {
            totalAmount += counts[i] * values[i];
        }
        
        // Print the result rounded to one decimal place
        System.out.printf("%.1f", totalAmount);
    }
}
