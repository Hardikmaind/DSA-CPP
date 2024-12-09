#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        set<int> store;
        for(int i = 1; i < n; i++)
            if((nums[i] % 2) == nums[i - 1] % 2)
                store.insert(i);

        vector<bool> ans;
        for(auto querie : queries)
        {
            int left = querie[0], right = querie[1];

            auto it = store.upper_bound(left);
            ans.push_back((*it <= right and it != store.end()) ? 0 : 1);
        }

        return ans;
    }


        //! THIS IS ANOTHER WAY TO SOLVE THE SAME PROBLEM. IN THIS I HAVE SUED THE SET TO STORE THE INDEXES OF THE ELEMENTS WHICH ARE NOT SPECIAL
        vector<bool> isArraySpecial2(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        set<int> store;
        for(int i = 1; i < n; i++)
            if((nums[i] % 2) == nums[i - 1] % 2)
                store.insert(i);

        vector<bool> ans;
        for(auto querie : queries)
        {
            int left = querie[0], right = querie[1];

            auto it = store.upper_bound(left);
            ans.push_back((*it <= right and it != store.end()) ? 0 : 1);
        }

        return ans;
    }
};


int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<vector<int>> queries = {{0, 3}, {3, 6}, {6, 7}};
    vector<bool> ans = s.isArraySpecial(nums, queries);
    for(auto x : ans)
        cout << boolalpha  << x << " ";         //because of this std::boolalpha, it is printing true/false instead of 1/0

    cout<<endl;

    vector<bool> ans2 = s.isArraySpecial2(nums, queries);
    for(auto x : ans2)
        cout << boolalpha  << x << " ";         //because of this std::boolalpha, it is printing true/false instead of 1/0

}




