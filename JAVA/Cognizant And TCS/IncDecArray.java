import java.util.*;
import java.lang.*;
import java.io.*;

public class IncDecArray {

    public static int min(int []arr){
        Arrays.sort(arr);
        int mid=arr[arr.length/2];
        int pos=arr.length/2;
        int ele=mid-pos;
        int sum=0;
        for(int i=0;i<arr.length;i++){
            sum+=Math.abs(arr[i]-ele);
            ele++;
        }
        
        return sum;

    }
    public static void main(String[] args) {
        // Your code goes here
        int []arr={13, 6, 11, 18, 4};
        int result=min(arr);
        System.out.println("this is the sum =>"+result);
    }
}