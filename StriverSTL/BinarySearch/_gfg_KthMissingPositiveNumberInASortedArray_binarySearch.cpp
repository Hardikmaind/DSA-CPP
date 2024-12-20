#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int left = 0, right = arr.size() - 1;
    
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - (mid + 1);
            
            if (missing < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return left + k;
        
    }
};
int main(){
    int k=1;
    vector<int> arr={2,3,5,9,10};
    Solution obj;
    cout<<obj.kthMissing(arr,k);        //ans is 1
    return 0;
}

/*
!HINT
To solve the problem of finding the kth missing positive number, consider these hints:

1. **Understand the missing count**: For each element in `arr`, calculate how many positive integers are missing before that element. Use the formula:  
   
   missing_count = arr[i] - (i + 1)

   This formula represents the difference between the actual number and its expected position in a fully continuous sequence starting from 1.

2. **Binary Search**: Use binary search to find the smallest index `i` where the number of missing integers up to `arr[i]` is greater than or equal to `k`.

3. **Final Missing Number**: Once the position is identified, calculate the exact kth missing number using:
   
   kth_missing = expected_value + remaining_k
   

4. **Edge Cases**: If `k` is larger than the total number of missing numbers in the array, handle it by finding numbers beyond the last element in `arr`.

This approach ensures the solution is efficient and leverages the sorted nature of the array.*/