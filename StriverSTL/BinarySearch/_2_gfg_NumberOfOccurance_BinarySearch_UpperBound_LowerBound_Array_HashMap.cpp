#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  //! THIS IS APPROACH 1
    int countFreq(vector<int>& arr, int target) {
        // // code here
        // int nums[arr[arr.size()-1]]={0};
        // for(auto &x:arr){
        //     nums[x]++;
        // }
        // if(target>arr.back()){
        //     return 0;
        // }
        // return nums[target];
        
        auto lower = std::lower_bound(arr.begin(), arr.end(), target);
        auto upper = std::upper_bound(arr.begin(), arr.end(), target);
    
        // Check if the target exists
        if (lower == arr.end() || *lower != target) {
            return 0; // Target not found
        }
    
        return upper - lower; // Difference in iterators gives the count
        
    }

//?===========================================APPROACH-2================================================================

    //! THIS IS APPROACH 2
    // Function to find the first occurrence of the target
static int firstOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid; // Update result and search left
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1; // Search right
        } else {
            high = mid - 1; // Search left
        }
    }
    return result;
}

// Function to find the last occurrence of the target
static int lastOccurrence(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid; // Update result and search right
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1; // Search right
        } else {
            high = mid - 1; // Search left
        }
    }
    return result;
}

int countFreq2(const vector<int>& arr, int target) {
    int first = firstOccurrence(arr, target);
    if (first == -1) return 0; // Target not found
    int last = lastOccurrence(arr, target);
    return last - first + 1;
}



//?===========================================APPROACH-3================================================================

    //! THIS IS APPROACH 3
    int countFreq3(std::vector<int>& arr, int target) {
    std::unordered_map<int, int> freqMap;

    // Count frequencies
    for (const auto& x : arr) {
        freqMap[x]++;
    }

    // Return frequency of the target
    return freqMap[target];
}

};

int main(){


    Solution s;
    vector<int> arr={1, 1, 2, 2, 2, 2, 3};
    int m=2;

    cout<<s.countFreq(arr,m)<<endl;
    cout<<s.countFreq2(arr,m)<<endl;
    cout<<s.countFreq3(arr,m)<<endl;
}