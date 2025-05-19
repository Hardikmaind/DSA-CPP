#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a=nums[0],b=nums[1],c=nums[2];
        int sum=a+b+c;
        if(sum-a<=a || sum-b <=b || sum-c<=c){
            return "none";
        }
        if(a==b && b==c && c==a){
            return "equilateral";
        }
        if(a==b ||b==c ||c==a){
            return "isosceles";
        }
        return "scalene";
    }
};



int main(){
    Solution s;
    vector<int> nums={2,2,3};
    cout<<s.triangleType(nums)<<endl; // Output: isosceles
    nums={1,2,3};
    cout<<s.triangleType(nums)<<endl; // Output: none
    nums={3,3,3};
    cout<<s.triangleType(nums)<<endl; // Output: equilateral
    return 0;
}