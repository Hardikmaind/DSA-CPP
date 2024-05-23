import java.util.*;
import java.lang.*;
import java.io.*;
//this is  a code to reverse a number
public class p5 {
    public static int reverseno(int num){
        int rev=0;
        while(num>0){
            int lastnum=num%10;
            rev=rev*10+lastnum;
            num=num/10;
        }
        return rev;
    }
    public static void main(String[] args) {
        // Your code goes here
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        System.out.println(reverseno(T));
        in.close();
    }
}