#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
/*
!When to Use while (l <= r)
The condition while (l <= r) is typically used in regular binary search when you need to search through all potential ranges, even when l is equal to r, to find a specific target element. In that case, l == r indicates a valid position that still needs checking.

Summary
?while (l < r): This condition is optimal for finding a single specific element, like the minimum, as it stops when you have exactly one candidate.

?while (l <= r): This is used for cases where the target element may be present anywhere in the range, and even when l == r, you need to check that final element.

*matlab l<=r wah use karte jaha binary serach mein hum woh last element bhi check karna hota hain, that if it equals to the target element,agar nahi hota toh hum -1 return kar dete hain.

*but yaha hume target se lena dena nahi hain and we just want to find the minimum,i.e the single element, so here we dont need to check the last element where l==r.
 */
        while (l < r) {
            int mid = l + (r - l) / 2;

            // If mid element is greater than the rightmost element,
            // the minimum is in the right half.
            if (arr[mid] > arr[r]) {
                l = mid + 1;
            } 
            // Otherwise, the minimum is in the left half (including mid).
            else {
                r = mid;
            }
        }
        // l == r will be the index of the minimum element.
        return arr[l];
    }
};

int main() {
    Solution s;
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    cout << s.findMin(arr) << endl;

    vector<int> arr2 = {91, 96};
    cout << s.findMin(arr2) << endl;

    vector<int> arr3 = {4, 5, 2, 3};
    cout << s.findMin(arr3) << endl;

    return 0;
}
