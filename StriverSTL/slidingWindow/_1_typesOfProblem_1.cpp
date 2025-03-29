#include <bits/stdc++.h>
using namespace std;

// * CONSTANT WINDOW PATTERN


int maxSumInWindow(vector<int>arr,int window){
    int n = arr.size();
    if(n<window) return -1; // Invalid case
    int maxSum = INT_MIN;
    int currentSum = 0;
    
    // Calculate the sum of the first window
    for(int i = 0; i < window; i++){
        currentSum += arr[i];
    }
    maxSum = currentSum;
    
    // Slide the window
    for(int i = window; i < n; i++){
        currentSum += arr[i] - arr[i - window]; // Add new element and remove the first element of the previous window
        maxSum = max(maxSum, currentSum); // Update max sum if needed
    }
    
    return maxSum;
}
int main(){
    vector<int> arr = {4,12,3,5,12,3,4,3,2,4,4,5,6,9,7,5,6,8,4,3,4,6,7,3,8,4,7,5,7};
    int windowSize = 3;
    int res=maxSumInWindow(arr, windowSize);
    cout << "Maximum sum in a window of size " << windowSize << " is: " << res << endl;         //6,9,7
    return 0;
}