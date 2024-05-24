// import java.util.*;
// import java.lang.*;
// import java.io.*;
// // 5 X
// // 1 Y
// // 2 N
// //              height arr elements
// // 9 
// // 10


// // test case-2

// // 5
// // 1
// // 2
// // 7
// // 9
// public class Zensar_bhopal_wall {
//     public static void main(String[] args) {
//         // Your code goes here
//         Scanner in = new Scanner(System.in);
//         int X = in.nextInt();
//         int Y = in.nextInt();
//         int N = in.nextInt();
//         var al=new ArrayList<Integer>();
//         for(int i=0;i<N;i++){
//             al.add(in.nextInt());
//         }
//         int count=0;
//         for(int i=0;i<al.size();i++){
//             int height=al.get(i);
//             while(height>0){
//                 height=height-X+Y;
//                 count++;
//             }
//         }
//         System.out.println(count-1);

//         in.close();
//     }
// }








// Certainly! Here is a possible question based on the provided code:

// Problem Statement: Wall Climbing Simulation
// You are given a series of walls of different heights. You need to simulate the process of climbing each wall. You can climb X meters in one attempt, but after each attempt, you slide down Y meters due to slippery conditions. Your task is to determine the total number of attempts required to climb all the walls.

// Input Format:
// The first integer X represents the number of meters you can climb in one attempt.
// The second integer Y represents the number of meters you slide down after each attempt.
// The third integer N represents the number of walls.
// The next N integers represent the heights of the walls.
// Output Format:
// Print the total number of attempts required to climb all the walls.
// Constraints:
// 1 <= X, Y <= 1000
// 1 <= N <= 100
// 1 <= height of each wall <= 10000



import java.util.*;
import java.lang.*;
import java.io.*;

public class ZensarBhopalWall {
    public static void main(String[] args) {
        // Your code goes here
        Scanner in = new Scanner(System.in);
        int X = in.nextInt();
        int Y = in.nextInt();
        int N = in.nextInt();
        ArrayList<Integer> al = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            al.add(in.nextInt());
        }

        int count = 0;
        for (int i = 0; i < al.size(); i++) {
            int height = al.get(i);
            while (height > 0) {
                height -= X;
                count++;
                if (height <= 0) break;
                height += Y;
            }
        }
        System.out.println(count);

        in.close();
    }
}
