#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int search(vector<int>& arr, int key) {
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;  
        if (arr[mid] == key) {
            return mid; 
        }

        // Determine which half is sorted
        if (arr[l] <= arr[mid]) {  // Left half is sorted
            if (key >= arr[l] && key < arr[mid]) {
                r = mid - 1;  // Key lies in the left half
            } else {
                l = mid + 1;  // Key lies in the right half
            }
        } else {  // Right half is sorted
            if (key > arr[mid] && key <= arr[r]) {
                l = mid + 1;  // Key lies in the right half
            } else {
                r = mid - 1;  // Key lies in the left half
            }
        }
    }

    return -1;  // Element not found
}

};



int main(){
    Solution s;
    vector<int> arr = {4,5,6,7,0,1,2};

    cout<<s.search(arr, 0)<<endl;
}