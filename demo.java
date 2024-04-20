import java.util.*;

public class demo {
    // public static void main(String[] args) {
    // int []arr={1,2,3,4,5};
    // reverseArr(arr);
    // for(int x:arr){
    // System.out.print(x+ " ");
    // }
    // }
    // public static void reverseArr(int []arr){
    // int left=0;
    // int right=arr.length-1;
    // while(left<right){
    // int temp=arr[right];
    // arr[right]=arr[left];
    // arr[left]=temp;
    // left++;
    // right--;
    // }

    // }

    // public static void main(String[] args) {
    // int n=1234567;
    // int result=reverseno(n);
    // System.out.println(result);
    // }
    // public static int reverseno(int n){
    // int m=n;
    // int rev=0;
    // while(n>0){
    // int temp=n%10;
    // rev=rev*10+temp;
    // n/=10;

    // }
    // return rev;
    // }

    // public static void main(String[] args) {
    // int n=121;
    // boolean result=reverseno(n);
    // System.out.println(result);
    // }
    // public static boolean reverseno(int n){
    // int m=n;
    // int rev=0;
    // while(n>0){
    // int temp=n%10;
    // rev=rev*10+temp;
    // n/=10;

    // }
    // if(rev==m){return true;}
    // return false;

    // }

    // public static void main(String[] args) {
    // String s="hardik";
    // boolean result=palindrome(s);
    // System.out.println(result);
    // }
    // public static boolean palindrome(String s){
    // int left=0;
    // int right=s.length()-1;
    // while(left<right){
    // if(s.charAt(left)!=s.charAt(right)){
    // return false;
    // }
    // left++;
    // right--;
    // }
    // return true;

    // }

    // public static void main(String[] args) {
    // int n=5;
    // for(int i=0;i<=n;i++){
    // for(int j=0;j<i;j++){
    // System.out.print(i);
    // }
    // System.out.println();
    // }
    // }

    // public static void main(String[] args) {
    // int n=5;
    // for(int i=0;i<=n;i++){
    // for(int j=0;j<i;j++){
    // System.out.print(i);
    // }
    // System.out.println();
    // }
    // }

    // public static void main(String[] args) {
    // int n=5;
    // for(int i=0;i<=n;i++){
    // int count=1;
    // for(int j=0;j<=i;j++){
    // System.out.print(count);
    // count++;
    // }
    // System.out.println();
    // }
    // }

//     public static void main(String[] args) {
//         int rows = 5; // Number of rows in the pyramid

//         for (int i = 0; i < rows; i++) {
//             // Print spaces before the stars
//             for (int j = 0; j < rows - i - 1; j++) {
//                 System.out.print(" ");
//             }

//             // Print stars
//             for (int k = 0; k <= i; k++) {
//                 System.out.print("*");
//             }

//             // Move to the next line after each row
//             System.out.println();
//         }
//     }

// }



public static void main(String[] args) {
    String s2="beautiful";
    String s=remove(s2);
    System.out.println(s);
}
public static String remove(String str){
    var st=new Stack<Character>();
    for(int i=0;i<str.length();i++){
        if(str.charAt(i)=='u'){
            st.push('*');
        }
        if(str.charAt(i)!='u'){

            st.push(str.charAt(i));
        }
    }
    StringBuilder s1=new StringBuilder();
    while(!st.empty()){
    s1.append(st.pop());
}

    String  str2=s1.reverse().toString();
    return str2;

}
}