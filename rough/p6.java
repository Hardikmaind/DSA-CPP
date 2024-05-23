import java.util.*;
import java.lang.*;
import java.io.*;
// take a string as input and print in reverse
public class p6 {
    public static void main(String[] args) {
        // Your code goes here
        Scanner in = new Scanner(System.in);
        String T = in.nextLine();
        StringBuilder str=new StringBuilder();
        String rev = reverse(T, T.length()-1,str).toString();
        System.out.println(rev);


        // this is another function
        System.out.println("this is the reversed string(reverse of reverse ) =>>>>>>>>>");
        reversePrint(rev, rev.length()-1);

        System.out.println();


        // this is another method to print the string
        System.out.println("this is the reversed string(reverse of reverse ) =>>>>>>>>>");
        reversePrint2(rev, 0);


        in.close();
    }
    public static void reversePrint(String str,int in){
        if(in<0){
            return ;
        }

        System.out.print(str.charAt(in)+" ");
        reversePrint(str, in-1);
    }
    public static void reversePrint2(String str,int in){
        if(in==str.length()){
            return ;
        }

        reversePrint2(str, in+1);
        System.out.print(str.charAt(in)+" ");
    }

    public static StringBuilder reverse(String s,int in,StringBuilder str){
        if(in<0){
            return str;
        }
        char c=s.charAt(in);
        str.append(c);
        reverse(s,in-1,str);
        return str;
    }
}