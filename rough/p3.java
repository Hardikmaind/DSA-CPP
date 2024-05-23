import java.util.*;
import java.lang.*;
import java.io.*;
//write a prograrm to remove the duplicate elememt from the array
public class p3 {
    public static void main(String[] args) {
        // Your code goes here
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int []arr=new int[N];
        for(int i=0;i<N;i++){
            arr[i]=in.nextInt();
        }
        // TreeSet<Integer>hs =new TreeSet<>();        //since used the tree set it will sort the keys in ascending order

        // if used the LinkedHashset it will not disturb the order of the keys..lets try below

        LinkedHashSet<Integer>hs=new LinkedHashSet<>();         //this will note disturb the order of the trees
        for(int x:arr){
            hs.add(x);
        }
        System.out.println("this is the output ==========>>>>>>>>>>>>>>>>>> ");
        for(Integer x: hs){
             System.out.print(x+ " ");
        }
        in.close();
    }
}