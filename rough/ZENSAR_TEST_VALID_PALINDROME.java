// Problem Statement: Valid Vowel Palindrome
// You are given a series of strings. For each string, extract all the vowels from it and check if the extracted vowels form a palindrome. If the extracted vowels form a palindrome, print "YES". Otherwise, print "NO".

// Input Format:
// The first line contains an integer T, the number of test cases.
// The next T lines each contain a single string s.
// Output Format:
// For each test case, print "YES" if the extracted vowels form a palindrome. Otherwise, print "NO".
// Constraints:
// 1 <= T <= 100
// Each string s will have a length between 1 and 1000.



import java.util.*;
import java.lang.*;
import java.io.*;

// this was the ZENSAR TEST....I FUCKED UP HERE
public class ZENSAR_TEST_VALID_PALINDROME {
    public static String extractVowel(String s){
        char []ch=s.toCharArray();
        StringBuilder str=new StringBuilder();
        for(int i=0;i<ch.length;i++){
            char c=ch[i];
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ){
                str.append(c);
            }
        }
        return str.toString();
    }

    public static boolean checkPalindrome(String s) {
        int l=0;
        int r=s.length()-1;
        while(l<=r){
            if(s.charAt(l)!=s.charAt(r)){
                return false;
            }
            l++;
            r--;
        }
        return true;

    }
    public static void main(String[] args) {
        // Your code goes here
        Scanner in = new Scanner(System.in);
        System.out.println("enter no of Strings ");
        int T = in.nextInt();
        in.nextLine();  // Consume the leftover newline    (or) us the in.nextLine()   see below             int T = Integer.parseInt(in.nextLine());  // Use nextLine() and parse the integer
        
        // Yes, there is another way to handle the input and processing more effectively. You can use nextLine() for all input reading and then parse the integer and strings as needed. This approach avoids issues with leftover newline characters and makes the code cleaner. Here’s how you can do it:

        while (T > 0) {
            System.out.println("Enter the Strings: ");
            String s = in.nextLine();
            String str = extractVowel(s);
            if (checkPalindrome(str)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
            T--;
        }
        in.close();
    }
}