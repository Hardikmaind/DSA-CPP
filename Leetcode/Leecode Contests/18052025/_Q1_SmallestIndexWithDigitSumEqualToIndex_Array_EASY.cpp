#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cal(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i==cal(nums[i])){
                return i;
            }
        }
        return -1;
    }
};
int main(){
        Solution sol;
        vector<int> nums = {1,10,11};
        cout << sol.smallestIndex(nums) << endl; // Output: 0
        return 0;
}
