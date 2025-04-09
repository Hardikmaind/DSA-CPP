#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            unordered_set<int> st;
            for (int x : nums) {
                if (x < k) {
                    return -1;
                } else if (x > k) {
                    st.insert(x);
                }
            }
            return st.size();
        }
    };


    int main(){
        Solution s;
        vector<int>arr={5,2,5,4,5};
        int k=2;
        cout<<s.minOperations(arr,k)<<endl;
        return 0;
    }