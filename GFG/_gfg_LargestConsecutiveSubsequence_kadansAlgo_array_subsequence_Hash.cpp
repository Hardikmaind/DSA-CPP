#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //! THIS IS DONE WITH THE HELP OF THE KADANS ALGORITHMS
    //* THIS IS MY METHOD. DONE BY ME. TC IS O(N) AND SC IS O(N)
    int longestConsecutive(vector<int>& arr) {
        if (arr.empty()) return 0; // Handle edge case where array is empty

        // Find max and min elements in the array
        int maxele = *max_element(arr.begin(), arr.end());
        int minele = *min_element(arr.begin(), arr.end());

        // Create a frequency array of appropriate size
        vector<int> res(maxele - minele + 1, 0);

        // Mark presence of elements in the frequency array
        for (auto &x : arr) {
            res[x - minele] = 1;
        }

        // Find the longest streak of consecutive ones in the frequency array
        int maxcount = 0, count = 0;
        for (auto &x : res) {
            if (x == 1) {
                count++;
                maxcount = max(count, maxcount);
            } else {
                count = 0;
            }
        }

        return maxcount;
    }
};


class Solution2 {
public:
//! THIS IS DONE WITH THE HELP OF THE HASHING.
//* TC IS O(N) AND SC IS O(N)
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> numSet(arr.begin(), arr.end());
        int maxStreak = 0;

        for (int num : numSet) {
            // Only start counting when it's the beginning of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                maxStreak = max(maxStreak, currentStreak);
            }
        }

        return maxStreak;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 9, 3, 10, 4, 20, 2};
    cout << obj.longestConsecutive(arr);
    cout<<endl;
    Solution2 obj2;
    vector<int> arr2 = {1, 9, 3, 10, 4, 20, 2};
    cout << obj2.longestConsecutive(arr2);
    return 0;
}
