
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int, int>> ranges;
        for (int x : nums) {
            ranges.push_back({x - k, x + k});
        }
        sort(ranges.begin(), ranges.end());
        int maxBeauty = 0;
        multiset<int> endPoints; // Stores the end points of the active intervals
        for (const auto& range : ranges) {
            int start = range.first, end = range.second;
            // Remove intervals that no longer overlap
            while (!endPoints.empty() && *endPoints.begin() < start) {
                endPoints.erase(endPoints.begin());
            }

            // Add the current interval's endpoint
            endPoints.insert(end);

            // Update maximum beauty
            maxBeauty = max(maxBeauty, (int)endPoints.size());
        }

        return maxBeauty;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {4,6,1,2};
    int k = 2;
    cout << sol.maximumBeauty(nums, k) << endl;
    return 0;
}






















// #include <bits/stdc++.h>

// using namespace std;
// class Solution {
// public:
// static bool allElementsSame(const std::vector<int>& nums) {
//     if (nums.empty()) {
//         return true; // Empty vector can be considered as having all elements "same".
//     }
//     return std::all_of(nums.begin(), nums.end(), [&](int x) { return x == nums[0]; });
// }
//     static bool compare(const vector<int>&a,const vector<int>&b){
//         if(a[0]==b[0]){
//             return a[1]<b[1];
//         }

//         return a[0]<b[0];
//     }
//     int maximumBeauty(vector<int>& nums, int k) {
// if (allElementsSame(nums)) {
//     return nums.size();
// }

//         vector<vector<int>> arr;
//         for(auto &x:nums){
//             arr.push_back({x-k,x+k});
//         }
//         sort(arr.begin(),arr.end(),compare);
//         int count=0;
//         vector<vector<int>> res;
//         auto prev=arr[0];
//         for(int i=1;i<arr.size();i++){
//             if(prev[1]>arr[i][0]){
//             prev[1] = max(prev[1], arr[i][1]); // Merge intervals
//                 count++;
//             }else{
//                 prev=arr[i];

//             }
//         }
//         return count;
        
//     }
// };



