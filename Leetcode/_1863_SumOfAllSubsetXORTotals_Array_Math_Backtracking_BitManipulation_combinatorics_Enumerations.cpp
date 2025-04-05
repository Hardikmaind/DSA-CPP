#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //! this is one way of writing the backtracking
        int util(int ind,vector<int>&arr,int sum){
            if(ind==arr.size()){
                return sum;
            }
            return util(ind+1,arr,sum^arr[ind]) + util(ind+1,arr,sum);
        }
        int subsetXORSum(vector<int>& nums) {
            return util(0,nums,0);
        }


        //! this is another way writing he backtrakcing. here we not directly returning . but first we are calculating it.
        int util2(int ind,vector<int>&arr,int sum){
            if(ind==arr.size()){
                return sum;
            }
            int withele=util2(ind+1,arr,sum^arr[ind]);
            int withoutele=util2(ind+1,arr,sum);
            return  withele + withoutele;
        }
        int subsetXORSum2(vector<int>& nums) {
            return util(0,nums,0);
        }

    };

int main() {
    Solution sol;
    vector<int> nums = {5,1,6};
    cout << sol.subsetXORSum(nums) << endl; // Output: 6
    cout<<sol.subsetXORSum2(nums)<<endl;
    return 0;
}