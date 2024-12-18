#include <bits/stdc++.h>
using namespace std;

// Function to check if it's possible to allocate books such that
// no student gets more than `maxPages` pages and all books are assigned.
bool checkValid(vector<int> &arr, int k, int maxPages) {
    int students = 1; // Start with one student
    int currentSum = 0;

    for (int pages : arr) {
        if (currentSum + pages > maxPages) {
            students++;        // Assign a new student
            currentSum = pages; // Reset current sum to the current book's pages

            // If students exceed `k`, the configuration is invalid
            if (students > k) return false;
        } else {
            currentSum += pages;
        }
    }

    return true; // Valid configuration
}

// Function to find the minimum possible value of the maximum number of pages
int findPages(vector<int> &arr, int k) {
    // If there are fewer books than students, it's not possible
    if (arr.size() < k) return -1;

    int l = *max_element(arr.begin(), arr.end()); // Lower bound: max single book
    int r = accumulate(arr.begin(), arr.end(), 0); // Upper bound: total pages
    int result = r;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        // Check if this maxPages value is valid
        if (checkValid(arr, k, mid)) {
            result = mid; // Update result with the current minimum
            r = mid - 1;  // Try for a smaller maximum
        } else {
            l = mid + 1;  // Try for a larger maximum
        }
    }

    return result;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2; // Number of students
    cout << "Minimum maximum pages: " << findPages(arr, k) << endl;
    return 0;
}
