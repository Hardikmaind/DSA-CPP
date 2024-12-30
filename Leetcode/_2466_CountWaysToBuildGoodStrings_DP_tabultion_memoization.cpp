#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int mod=1e9+7;
        int dp[100001]={0};
        dp[0]=1;
        for(int i=1; i<=high; i++){
            long long ans=1;
            if (i>=zero) ans+=dp[i-zero];
            if (i>=one) ans+=dp[i-one];
            dp[i]=ans%mod;
        }
        return (dp[high]-dp[low-1]+mod)%mod;
    }
};
int main(){
    Solution s;
    cout<<s.countGoodStrings(1, 2, 1, 1)<<endl;
    cout<<s.countGoodStrings(3, 3, 1, 1)<<endl;
    cout<<s.countGoodStrings(1, 8, 2, 3)<<endl;
    cout<<s.countGoodStrings(4, 5, 0, 0)<<endl;
    cout<<s.countGoodStrings(50, 100, 25, 25)<<endl;
    return 0;
}