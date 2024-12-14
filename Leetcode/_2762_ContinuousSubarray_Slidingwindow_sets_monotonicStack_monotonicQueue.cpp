#include <bits/stdc++.h>
using namespace std;
class Solution {
public:



//! WORKS ONLY WHEN DISTINT ELEMENTS ARE THERE
    long long continuousSubarrays(vector<int>& arr) {
        // Sliding window code
        int l = 0;
        int r = 0;
        long long count = 0;  // Use long long to store the count

        while (r < arr.size()) {
            int diff = abs(arr[l] - arr[r]);

            if (diff <= 2) {
                // All subarrays between l and r are valid
                count += (r - l + 1);
                r++;  // Expand the window
            } else {
                // Contract the window by moving l
                l++;
            }
        }

        return count;
    }



        //! Workds for all cases. but tc is O(n^2) and therefore give TLE
     long long continuousSubarrays2(vector<int>& arr) {
        int l = 0;
        int r = 0;
        long long count = 0;  // Use long long to store the count
        int min_val = arr[0];
        int max_val = arr[0];

        while (r < arr.size()) {
            // Update min and max values for the current window
            min_val = std::min(min_val, arr[r]);
            max_val = std::max(max_val, arr[r]);

            // Check if the difference exceeds 2
            if (max_val - min_val > 2) {
                // Shrink the window from the left
                if (arr[l] == min_val || arr[l] == max_val) {
                    // Recalculate min and max if we are removing their value
                    l++;
                    min_val = *std::min_element(arr.begin() + l, arr.begin() + r + 1);
                    max_val = *std::max_element(arr.begin() + l, arr.begin() + r + 1);
                } else {
                    l++;
                }
            } else {
                // All subarrays between l and r are valid
                count += (r - l + 1);
                r++;
            }
        }

        return count;
    }

    //!Uses deque to store the max and min values of the current window. tc is O(n) and sc is O(n)
     long long continuousSubarrays3(vector<int>& arr) {
        int l = 0;
        long long count = 0;
        deque<int> maxDeque;  // To track maximum values
        deque<int> minDeque;  // To track minimum values

        for (int r = 0; r < arr.size(); ++r) {
            // Maintain maxDeque to track the max value in the current window
            while (!maxDeque.empty() && arr[maxDeque.back()] <= arr[r]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(r);

            // Maintain minDeque to track the min value in the current window
            while (!minDeque.empty() && arr[minDeque.back()] >= arr[r]) {
                minDeque.pop_back();
            }
            minDeque.push_back(r);

            // Shrink the window if the difference between max and min exceeds 2
            while (arr[maxDeque.front()] - arr[minDeque.front()] > 2) {
                l++;
                // Remove indices from deques if they are out of the current window
                if (!maxDeque.empty() && maxDeque.front() < l) {
                    maxDeque.pop_front();
                }
                if (!minDeque.empty() && minDeque.front() < l) {
                    minDeque.pop_front();
                }
            }

            // Add all valid subarrays ending at r
            count += (r - l + 1);
        }

        return count;
    }



/*In C++, a "multiset" is a container within the Standard Template Library (STL) that allows you to store a collection of elements where duplicate values are permitted, meaning you can have multiple instances of the same element within the set, while still maintaining a sorted order based on the element's value; unlike a regular set which only allows unique elements.
//? Key points about multisets: 

• Duplicates allowed: The main difference from a standard set is that a multiset can store multiple elements with the same value. [1, 2, 4]  
• Sorted order: Elements within a multiset are always kept in ascending order based on their value. [1, 2, 5]  
• Access and manipulation: You can insert, delete, and search for elements in a multiset using operations similar to a regular set. [2, 5, 6]  

Example usage: 
#include <set>
int main() {

    std::multiset<int> myMultiset;
    myMultiset.insert(10);
    myMultiset.insert(5);
    myMultiset.insert(10); // This will be added as a duplicate
    // Accessing elements (will be printed in sorted order)
    for (int element : myMultiset) {
        std::cout << element << " ";
    }
}
https://en.cppreference.com/w/cpp/container/multiset
*/
    //! THIS IS THE BEST SOLUTION. USES MULTISET TO STORE THE ELEMENTS OF THE CURRENT WINDOW. TC IS O(N) AND SC IS O(N)
     long long continuousSubarrays4(vector<int>& arr) {
        long long count = 0;
        int l = 0;  // Left pointer
        multiset<int> window;  // To maintain the elements in the current window

        for (int r = 0; r < arr.size(); ++r) {
            window.insert(arr[r]);

            // Ensure the difference between max and min in the window is <= 2
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(arr[l]));
                l++;
            }

            // Add all valid subarrays ending at index r
            count += (r - l + 1);
        }

        return count;
    }


    //! This is another soltion with the use of minHeap and maxHeap. TC is O(NlogN) and SC is O(N)
    long long continuousSubarrays5(vector<int>& arr) {
        long long count = 0;
        int l = 0;  // Left pointer

        // Min-Heap to track the minimum value in the current window
        priority_queue<int, vector<int>, greater<int>> minHeap;
        // Max-Heap to track the maximum value in the current window
        priority_queue<int> maxHeap;

        for (int r = 0; r < arr.size(); ++r) {
            // Add the current element to both heaps
            minHeap.push(arr[r]);
            maxHeap.push(arr[r]);

            // Shrink the window if the difference exceeds 2
            while (!minHeap.empty() && !maxHeap.empty() && maxHeap.top() - minHeap.top() > 2) {
                // Remove the leftmost element from the heaps lazily
                if (arr[l] == minHeap.top()) minHeap.pop();
                if (arr[l] == maxHeap.top()) maxHeap.pop();
                l++;
            }

            // Add all valid subarrays ending at index r
            count += (r - l + 1);
        }

        return count;
    }
};


int main(){
    Solution s;
    vector<int> arr = {5,4,2,4};
    cout << s.continuousSubarrays(arr) << endl;
    cout << s.continuousSubarrays2(arr) << endl;
    cout << s.continuousSubarrays3(arr) << endl;
    cout << s.continuousSubarrays4(arr) << endl;
}