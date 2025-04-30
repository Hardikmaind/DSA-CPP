#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int count=0;
            for(auto &x:nums){
                if(( (int)log10(x) + 1)%2==0){
                    count++;
                }
            }
            return count;
        }
    };


    int main(){
        Solution s;
        vector<int> nums = {12, 345, 2, 6, 7896};
        cout << s.findNumbers(nums) << endl; // Output: 2
        return 0;
    }