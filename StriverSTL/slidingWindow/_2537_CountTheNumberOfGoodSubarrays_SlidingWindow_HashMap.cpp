#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long countGood(vector<int> &nums, int k) {
        long long count = 0;
        int l = 0, r = 0;
        int n = nums.size();
        unordered_map<int, int> map;
        long long pairs = 0;

        while (r < n) {
            // ✅ Corrected: increment frequency first, then update pair count
            pairs += map[nums[r]];
            map[nums[r]]++;

            // ✅ Shrink the window from the left until pairs < k
            while (pairs >= k) {
                count += n - r; // All subarrays [l..r], [l..r+1], ..., [l..n-1] are valid
                map[nums[l]]--;
                pairs -= map[nums[l]];
                l++;
            }

            r++;
        }

        return count;
    }

    //! this is m2
    long long countGood2(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        int right = 0;
        int left = 0;
        long long res = 0;

        while (right < n) {
            k -= m[nums[right++]]++;

            while (k <= 0)
                k += --m[nums[left++]];

            res += left;
        }

        return res;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {3, 1, 4, 3, 2, 2, 4};
    int k = 2;
    auto res = obj.countGood(arr, k);
    cout << res << endl;
    return 0;
}

