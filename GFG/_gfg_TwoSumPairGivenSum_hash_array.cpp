#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_set<int> st;
        for(auto &x:arr){
            int complement = target - x;
            if (st.count(complement) > 0) {     //here before adding we are checking. so in this way we can avoid the self pairing
                return true;
            }
            st.insert(x);
        }
       
        return false;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 16;
    cout<<s.twoSum(arr, target);
}