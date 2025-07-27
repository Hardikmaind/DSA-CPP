#include <bits/stdc++.h>
using namespace std;


/*
! Why at most 2?
!Let’s say your array has length n. If there are k elements each appearing more than n/3 times, then:

k * (n/3) < n  →  k < 3  →  k ≤ 2
So, 3 elements each appearing > n/3 times is impossible.


Let me know if you want the version generalized to more than n/k elements (at most k - 1 such elements)!

*/
class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        // int cand1 = 0, cand2 = 1;  // start with two distinct values
        int cand1 = 0, cand2 = 0;  // ! if taken same value then add the below check, (cand1!=cand2)      
        int counter1 = 0, counter2 = 0;

        for (int num : nums) {
            if (num == cand1) {
                counter1++;
            } else if (num == cand2) {
                counter2++;
            } else if (counter1 == 0) {
                cand1 = num;
                counter1 = 1;
            } else if (counter2 == 0) {
                cand2 = num;
                counter2 = 1;
            } else {
                counter1--;
                counter2--;
            }
        }

        // Verify candidates
        int count1 = 0, count2 = 0;
        for (int num : nums) {
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
        }

        vector<int> res;
        if (count1 > nums.size() / 3)
            res.push_back(cand1);
        if (count2 > nums.size() / 3   && cand2 != cand1)       //add this check if cand1 aqnd cand2 are taken as same value while initializing
            res.push_back(cand2);
        if (res.size() == 2 && res[0] > res[1])
            swap(res[0], res[1]);

        return res;
    }
};

//! "At most k - 1 elements can appear more than n/k times."

class Solution2 {
public:
    vector<int> majorityElement(vector<int>& nums, int k) {
        unordered_map<int, int> candidates;

        for (int num : nums) {
            if (candidates.count(num)) {
                candidates[num]++;
            } else if (candidates.size() < k - 1) {
                candidates[num] = 1;
            } else {
                // Decrease all counters
                for (auto it = candidates.begin(); it != candidates.end(); ) {
                    if (--(it->second) == 0)
                        it = candidates.erase(it);
                    else
                        ++it;
                }
            }
        }

        // Verify candidates
        unordered_map<int, int> actual_count;
        for (int num : nums) {
            if (candidates.count(num))
                actual_count[num]++;
        }

        vector<int> result;
        int threshold = nums.size() / k;
        for (auto &[num, count] : actual_count) {
            if (count > threshold)
                result.push_back(num);
        }

        sort(result.begin(), result.end()); // optional
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 1, 2, 1, 2, 2, 1};
    vector<int> result = obj.findMajority(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;


    Solution2 obj2;
    vector<int> nums2 = {1, 2, 3, 1, 2, 1, 2, 2, 1, 3, 3, 3};
    int k = 4; // Find all elements that appear more than n/4 times
    vector<int> result2 = obj2.majorityElement(nums2, k);

    for (int x : result2)
        cout << x << " ";
    cout << endl;

    return 0;
}