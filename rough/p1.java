import java.util.*;
import java.lang.*;
import java.io.*;
// to find the largest and the second largest and then take its average in the array .
// also take user input from the array
public class p1 {
    public static void main(String[] args) {
        // Your code goes here
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        var al =new ArrayList<Integer>();

        for(int i=0;i<N;i++){
            int ele=in.nextInt();
            // al.add(in.nextInt());
            al.add(ele);
        }
        int largest=Integer.MIN_VALUE;
        for(int i=0;i<al.size();i++){
            largest=Math.max(largest, al.get(i));
        }
        var al2=new ArrayList<Integer>();
        for(int x:al){
            if(x!=largest){

                al2.add(x);
            }
        }
        int secondLargest=Integer.MIN_VALUE;
        for(int x:al2){
            secondLargest=Math.max(secondLargest, x);
        }
        float average=(float)(secondLargest+largest)/2;
        System.out.println(secondLargest+" "+largest+" their average is : "+average    );;
        in.close();
    }
}