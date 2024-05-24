import java.util.*;
import java.lang.*;
import java.io.*;

public class generateSubset {
    public static void main(String[] args) {
        // Your code goes here
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();       //inp array size
        int[]arr=new int[N];        //arr declared
        for(int i=0;i<N;i++){       
            int ele=in.nextInt();       //array element input taken
            arr[i]=ele;
        }
        List<List<Integer>>al=new ArrayList<>();
        subsets(arr,0, new ArrayList<>(),al);
        
        System.out.println();
        System.out.println("below are all the subsets");
        for(List<Integer> ls:al){
            System.out.println(ls);
        }

        in.close();
    }
    public static void subsets(int []arr,int idx, List<Integer> currentSubset,List<List<Integer>>al){
        
        
        if (idx == arr.length) {
            al.add(new ArrayList<>(currentSubset));
            return;
        }

        // Not take current element
        subsets(arr, idx + 1, currentSubset, al);

        // Take current element
        currentSubset.add(arr[idx]);
        subsets(arr, idx + 1, currentSubset, al);

        // Backtrack to remove the last added element
        currentSubset.remove(currentSubset.size() - 1);
        
    }
}