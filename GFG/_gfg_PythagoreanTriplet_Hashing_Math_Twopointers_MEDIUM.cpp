#include <bits/stdc++.h>
using namespace std;


//! this below code uses two pointers and sorting approach. tc is O(n^2) and sc is O(1)
class Solution1 {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        // Square all elements
        for (int i = 0; i < n; ++i) {
            arr[i] = arr[i] * arr[i];
        }
        // Sort the squared array
        sort(arr.begin(), arr.end());
        // Fix one element (c^2) and use two pointers to find a^2 + b^2 = c^2
        for (int i = n - 1; i >= 2; --i) {
            int left = 0;
            int right = i - 1;
            while (left < right) {
                if (arr[left] + arr[right] == arr[i]) {
                    return true;
                } else if (arr[left] + arr[right] < arr[i]) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return false;
    
    }
};


//! this below code uses hashing approach. tc is O(n^2) and sc is O(n).
//* This is O(n^2) too, but may be faster in practice due to early exit and no sorting.
class Solution2 {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> squares;
        
        for (int i = 0; i < n; ++i) {
            squares.insert(arr[i] * arr[i]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a2 = arr[i] * arr[i];
                int b2 = arr[j] * arr[j];
                if (squares.count(a2 + b2)) {
                    return true;
                }
            }
        }

        return false;
    }
};
