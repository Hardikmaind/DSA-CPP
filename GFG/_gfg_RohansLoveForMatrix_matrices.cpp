// User function Template for C++

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int firstElement(int n) {
        // code here
        if(n==0 || n==1) return 1;
        int a=1, b=1;
        int mod= 1000000007;
        int c;
        for(int i=0;i<n-2;i++){
            c=(a+b)%mod;
            a=b%mod;
            b=c%mod;
        }
        return c%mod;
    }
};

int main(){
    int n = 3;
    Solution obj;
    cout << obj.firstElement(n);
    return 0;
}