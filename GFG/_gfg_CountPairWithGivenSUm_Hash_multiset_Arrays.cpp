#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        multiset<int> st;
        int count=0;
        for(auto &x:arr){
            int complement = target - x;
            int setcount=st.count(complement);
            if (setcount > 0) {     
                count+=setcount;
            }
            st.insert(x);
        }
       
        return count;
    }
};
int main(){
    vector<int>arr={5,6,5,7,7,8};
    int target=13;
    Solution obj;
    cout<<obj.countPairs(arr,target);
}