#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0); 
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0)) {
                prefix[i]++;
            }
        }
        vector<bool> ans;
        for (auto& q : queries) {
            int left = q[0], right = q[1];
            int specialCount = prefix[right] - (left > 0 ? prefix[left] : 0);
            ans.push_back(specialCount == 0);
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
    vector<int> nums = {3,4,1,2,6};
    vector<vector<int>> queries = {{0, 4}};
    vector<bool> ans = s.isArraySpecial(nums, queries);
    for(auto x : ans)
        cout << boolalpha  << x << " ";         //because of this std::boolalpha, it is printing true/false instead of 1/0

    cout<<endl;

    vector<bool> ans2 = s.isArraySpecial2(nums, queries);
    for(auto x : ans2)
        cout << boolalpha  << x << " ";         //because of this std::boolalpha, it is printing true/false instead of 1/0

}




