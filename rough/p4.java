import java.util.*;
import java.lang.*;
import java.io.*;
// write a program to read an array of size N . which takes and input of temperature  in degree fahrenhite , calcute the average temperature in degree celcius upto two decimal places
public class p4 {
    public static void main(String[] args) {
        // Your code goes here
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        var al =new ArrayList<Float>();

        for(int i=0;i<N;i++){
            al.add(in.nextFloat());
            
        }
        var celsiusList = new ArrayList<Float>();

        for(int i=0;i<al.size();i++){
            float degincelcius=(al.get(i)-32)*5.0f/9.0f;
            celsiusList.add(degincelcius);
        }
        float avgtemp=0.0f;
        for(float x:celsiusList){
            avgtemp+=x;
        }
        System.out.printf("%.2f",avgtemp/N);

        in.close();
    }
}