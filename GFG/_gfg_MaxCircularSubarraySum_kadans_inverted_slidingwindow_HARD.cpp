#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int total = 0;
        int max_ending_here = 0, max_so_far = INT_MIN;
        int min_ending_here = 0, min_so_far = INT_MAX;

        for (int num : arr) {
            total += num;

            // Kadane's for max subarray
            max_ending_here = max(num, max_ending_here + num);
            max_so_far = max(max_so_far, max_ending_here);

            // Kadane's for min subarray
            min_ending_here = min(num, min_ending_here + num);
            min_so_far = min(min_so_far, min_ending_here);
        }

        if (max_so_far < 0)
            return max_so_far;  // All elements negative

        return max(max_so_far, total - min_so_far);
    }
};




// class Solution {
//   public:
//     int maxCircularSum(vector<int> &arr) {
//         // code here
//         //this code can be solved by max sum of n elements in 2n array length;
        
//         vector<int>nums=arr;
//         reverse(arr.begin(),arr.end());
//         int i=0;
//         for(auto &x:arr){
//             if(i==0){
//                 continue;
//             }
//             nums.push_back(x);
//             ++i;
//         }
//         int maxsum=0;
//         int l=0;
//         int r=0, n=arr.size()*2;
//         int k=n/2;
//         for(int i=0;i<k;i++){
//             maxsum+=nums[i];
//         }
//         int res=maxsum;
//         for(int i=k;i<nums.size();i++){
//             maxsum+=nums[i] - nums[i - k];
//             res=max(res,maxsum);
//         }
//         return res;

//     }
// };


int main(){
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    Solution obj;
    int res = obj.maxCircularSum(arr);
    cout << res << endl;
    return 0;
}