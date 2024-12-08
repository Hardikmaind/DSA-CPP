#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    static bool compare(const vector<int>& e1, const vector<int>& e2) {
        if (e1[0] == e2[0]) {
            return e1[1] < e2[1];
        }
        return e1[0] < e2[0];
    }
    



    //! THIS IS METHOD 1
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> arr;
        arr.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (arr.back()[1] >= intervals[i][0]) {

                arr.back()[1] = max(intervals[i][1], arr.back()[1]);
            } else {
                arr.push_back(intervals[i]);
            }
        }
        return arr;
    }
        //! THIS IS METHOD 2
     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // Sort intervals by start time
        int k = 0; // Index for merged intervals
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[k][1] >= intervals[i][0]) { // Overlap detected
                intervals[k][1] = max(intervals[k][1], intervals[i][1]); // Merge
            } else {
                k++; // Move to the next position
                intervals[k] = intervals[i]; // Replace in-place
            }
        }
        
        intervals.resize(k + 1); // Resize to include only merged intervals
        return intervals;
    }
};

int main(){

    //!THIS IS ONE WAY TO CALL THE FUNCTION
    Solution s;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = s.merge(intervals);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }



   //! THIS IS ANOTHER WAY TO CALL THE FUNTION

   //to implement below code, we need to change the function parameter to accept const reference, and then create a copy inside the function, as shown in the code below

     // Passing an anonymous (temporary) vector to the function
    // auto result = s.merge({{1, 3}, {2, 6}, {8, 10}, {15, 18}});

     // Print the result
    // for (const auto& interval : result) {
    //     cout << "[" << interval[0] << ", " << interval[1] << "] ";
    // }

}



/*




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& e1, const vector<int>& e2) {
        if (e1[0] == e2[0]) {
            return e1[1] < e2[1];
        }
        return e1[0] < e2[0];
    }
    
    vector<vector<int>> merge(const vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        
        // ?  Create a modifiable copy of the input
        vector<vector<int>> sortedIntervals = intervals;
        sort(sortedIntervals.begin(), sortedIntervals.end(), compare);
        
        vector<vector<int>> arr;
        arr.push_back(sortedIntervals[0]);
        
        for (int i = 1; i < sortedIntervals.size(); i++) {
            if (arr.back()[1] >= sortedIntervals[i][0]) {
                arr.back()[1] = max(sortedIntervals[i][1], arr.back()[1]);
            } else {
                arr.push_back(sortedIntervals[i]);
            }
        }
        return arr;
    }
};

int main() {
    //! First way: using a named vector
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res = s.merge(intervals);
    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    //! Second way: using an anonymous (temporary) vector
    auto result = s.merge({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}



*/


/*The issue in your code is that you're trying to pass a temporary (anonymous) vector directly to the `merge` function, which takes a non-const reference (`vector<vector<int>>& intervals`). Temporaries cannot bind to non-const references, causing a compilation error.

### Fix
1. **Change the Function Parameter to Accept `const` Reference**:
   Modify the parameter of the `merge` function to accept `const vector<vector<int>>&`. This allows the function to accept temporary vectors.

2. **Create a Copy Inside the Function**:
   Since you need to modify the input vector (sort it and merge intervals), create a copy inside the function.

### Updated Code:
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& e1, const vector<int>& e2) {
        if (e1[0] == e2[0]) {
            return e1[1] < e2[1];
        }
        return e1[0] < e2[0];
    }
    
    vector<vector<int>> merge(const vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        
        // Create a modifiable copy of the input
        vector<vector<int>> sortedIntervals = intervals;
        sort(sortedIntervals.begin(), sortedIntervals.end(), compare);
        
        vector<vector<int>> arr;
        arr.push_back(sortedIntervals[0]);
        
        for (int i = 1; i < sortedIntervals.size(); i++) {
            if (arr.back()[1] >= sortedIntervals[i][0]) {
                arr.back()[1] = max(sortedIntervals[i][1], arr.back()[1]);
            } else {
                arr.push_back(sortedIntervals[i]);
            }
        }
        return arr;
    }
};

int main() {
    //! First way: using a named vector
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res = s.merge(intervals);
    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

    //! Second way: using an anonymous (temporary) vector
    auto result = s.merge({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}
```

### Key Changes:
1. **Changed Parameter to `const vector<vector<int>>& intervals`**:
   - This allows the function to accept temporary vectors and prevents accidental modification of the original data.

2. **Made a Copy of `intervals`**:
   - To sort and modify the input, a local copy (`sortedIntervals`) is created.

### Output:
```
1 6
8 10
15 18
[1, 6] [8, 10] [15, 18] 
``` */