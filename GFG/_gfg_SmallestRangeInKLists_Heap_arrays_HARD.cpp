#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    
        // vector<int> findSmallestRange(vector<vector<int>>& arr) {
            
        //     int k = arr.size();         
        //     int n = arr[0].size();   
        
        //     // Pointers for each of the k rows
        //     vector<int> ptr(k, 0);
        
        //     int minRange = INT_MAX;
        //     int start = -1, end = -1;
        
        //     while (true) {
        
        //         int minVal = INT_MAX;
        //         int maxVal = INT_MIN;
        //         int minRow = -1;
        
        //         // Traverse all k rows to get current min and max
        //         for (int i = 0; i < k; i++) {
        
        //             // If any list is exhausted, stop the loop
        //             if (ptr[i] == n) {
        //                 return {start, end};
        //             }
        
        //             // Track min value and its row index
        //             if (arr[i][ptr[i]] < minVal) {
        //                 minVal = arr[i][ptr[i]];
        //                 minRow = i;
        //             }
        
        //             // Track current max value
        //             if (arr[i][ptr[i]] > maxVal) {
        //                 maxVal = arr[i][ptr[i]];
        //             }
        //         }
        
        //         // Update the result range if a 
        //         // smaller range is found
        //         if (maxVal - minVal < minRange) {
        //             minRange = maxVal - minVal;
        //             start = minVal;
        //             end = maxVal;
        //         }
        
        //         // Move the pointer of the 
        //         // row with minimum value
        //         ptr[minRow]++;
        //     }
        
        //     return {start, end};
        // }
        
            
    // vector<int> findSmallestRange(vector<vector<int>>& arr) {
        
    //     int k = arr.size();  
    //     // Stores the current index for each list
    //     vector<int> pointers(k, 0);
    //     // Stores the current smallest range
    //     vector<int> smallestRange = {0, INT_MAX};
    
    //     while (true) {
    //         int currentMin = INT_MAX, currentMax = INT_MIN;
    //         int minListIndex = -1;
    
    //         // Find the minimum and maximum among current elements of all lists
    //         for (int i = 0; i < k; i++) {
    //             int value = arr[i][pointers[i]];
    
    //             if (value < currentMin) {
    //                 currentMin = value;
    //                 minListIndex = i;
    //             }
    
    //             if (value > currentMax) {
    //                 currentMax = value;
    //             }
    //         }
    
    //         // Update the smallest range if this one is smaller
    //         if (currentMax - currentMin < smallestRange[1] - smallestRange[0]) {
    //             smallestRange[0] = currentMin;
    //             smallestRange[1] = currentMax;
    //         }
    
    //         // Move the pointer in the list that had the minimum value
    //         pointers[minListIndex]++;
    //         // If that list is exhausted, break the loop
    //         if (pointers[minListIndex] == arr[minListIndex].size()) break;
    //     }
    
    //     return smallestRange;
    // }
    //  Struct to represent elements in the heap
    struct Node {
        int val, row, col;
        bool operator>(const Node& other) const {
            return val > other.val;
        }
    };
    // Function to find the smallest range
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int N = arr.size();        // Number of rows
        int K = arr[0].size();     // Number of columns (same for each row)
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        int maxVal = INT_MIN;
        // Push the first element of each list into the min-heap
        for (int i = 0; i < N; i++) {
            pq.push({arr[i][0], i, 0});
            maxVal = max(maxVal, arr[i][0]);
        }
        int minRange = INT_MAX, minEl, maxEl;
        while (true) {
            Node curr = pq.top(); pq.pop();
            int minVal = curr.val;
            // Update range if better
            if (maxVal - minVal < minRange) {
                minRange = maxVal - minVal;
                minEl = minVal;
                maxEl = maxVal;
            }
            // If we've reached the end of a list, break
            if (curr.col + 1 == K) break;
    
            // Push next element from the same list
            int nextVal = arr[curr.row][curr.col + 1];
            pq.push({nextVal, curr.row, curr.col + 1});
            maxVal = max(maxVal, nextVal);
        }
        return {minEl, maxEl};
    }
};


int main(){
    Solution obj;
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = obj.findSmallestRange(arr);
    cout << "Smallest Range: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}