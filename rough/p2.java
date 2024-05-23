import java.util.*;
import java.lang.*;
import java.io.*;
//take find a factorial of a number and priitn its sum of digits
public class p2 {
    public static void main(String[] args) {
        // Your code goes here
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int factorial=getFactorial( N);
        int factorialbyDp=getFactorialDp( N);
        System.out.println(factorial+" this is fact by dp=> "+factorialbyDp);
        int sumOfDigit=getSumOfDigit(factorial);
        System.out.println(sumOfDigit);
        in.close();
    }
    public static int getSumOfDigit(int num){
        int sum=0;
        while(num>0){
            int rem=num%10;
            int trim=num/10;
            num=trim;
            sum+=rem;
        }
        return sum;
    }
    public static int getFactorial(int num){
        if(num==0 ||num==1){
            return 1;
        }
        int fact=num*getFactorial(num-1);

        return fact;
    }
    public static int getFactorialDp(int num){
        int []dp=new int[num+1];
        dp[0]=1;
        for(int i=1;i<=num;i++){

            dp[i]=i*dp[i-1];
        }
        return dp[num];
        
    }
}