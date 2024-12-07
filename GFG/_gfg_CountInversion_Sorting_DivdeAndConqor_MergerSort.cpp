#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int>& arr) {
        int count = 0; // Initialize local count
        mergeSort(arr, 0, arr.size() - 1, count);
        return count;
    }

  private:
    void mergeSort(vector<int>& arr, int start, int end, int& count) {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start) / 2; // Avoid overflow
        mergeSort(arr, start, mid, count);
        mergeSort(arr, mid + 1, end, count);
        merge(arr, start, mid, end, count);
    }

    void merge(vector<int>& arr, int left, int mid, int right, int& count) {
        int n1 = mid - left + 1; // Size of left subarray
        int n2 = right - mid;    // Size of right subarray

        // Create temporary arrays
        vector<int> leftArray(n1);
        vector<int> rightArray(n2);

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++) {
            leftArray[i] = arr[left + i];
        }
        for (int i = 0; i < n2; i++) {
            rightArray[i] = arr[mid + 1 + i];
        }

        // Merge the temporary arrays back into arr[left..right]
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                arr[k++] = leftArray[i++];
            } else {
                // Count inversions
                count += (n1 - i); // All remaining elements in leftArray are greater
                arr[k++] = rightArray[j++];
            }
        }

        // Copy remaining elements of leftArray, if any
        while (i < n1) {
            arr[k++] = leftArray[i++];
        }

        // Copy remaining elements of rightArray, if any
        while (j < n2) {
            arr[k++] = rightArray[j++];
        }
    }
};

int main() {
    Solution solution;
    vector<int> arr = {2, 4, 1, 3, 5};
    cout << "Inversion Count: " << solution.inversionCount(arr) << endl;
    return 0;
}