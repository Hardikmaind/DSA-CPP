#include <bits/stdc++.h>
using namespace std;

//! this is my solution
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        long long sum2=0;
        long long zcount1=0,zcount2=0;
        for(auto&x :nums1){
            if(x==0){
                x++;
                zcount1++;
            }
            sum1+=x;
        }
        for(auto&x :nums2){
            if(x==0){
                x++;
                zcount2++;
            }
            sum2+=x;
        }
        long long maxSum=max(sum1,sum2);
        if(sum1==sum2){
            return sum1;
        }
        if(maxSum==sum1){
            if(zcount2 && (sum1)>(sum2)){
                return sum1;
            }else{
                return -1;
            }
        }
        if(maxSum==sum2){
            if( zcount1 &&    (sum2)>(sum1)){
                return sum2;
            }else{
                return -1;
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=accumulate(nums1.begin(),nums1.end(),0);
        long long sum2=accumulate(nums2.begin(),nums2.end(),0);

        long long zcount1=count(nums1.begin(),nums1.end(),0);
        long long zcount2=count(nums2.begin(),nums2.end(),0);
        
        long long adjusttedSum1=sum1+zcount1;
        long long adjusttedSum2=sum2+zcount2;
        
        if (adjusttedSum1 == adjusttedSum2) {
            return adjusttedSum1;
        } else if (adjusttedSum1 > adjusttedSum2 && zcount2 > 0) {
            return adjusttedSum1;
        } else if (adjusttedSum2 > adjusttedSum1 && zcount1 > 0) {
            return adjusttedSum2;
        } else {
            return -1;
        }
    
    }
};




int main(){
    Solution s;
    Solution2 s2;
    vector<int> nums1 = {3,2,0,1,0};
    vector<int> nums2 = {6,5,0};
    cout<<s2.minSum(nums1,nums2)<<endl;
    cout << s.minSum(nums1, nums2) << endl; 
    return 0;
}