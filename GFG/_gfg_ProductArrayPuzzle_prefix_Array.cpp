#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        long long prod=1;
        int zero=0;
        vector<int> ans;
        for(auto num:arr){
             if(num!=0) prod=prod*num;
             else zero++;
        }
        for(auto num:arr){
            if(zero>1) ans.push_back(0);
            else if(num!=0){
                if(zero>0) ans.push_back(0);
                else ans.push_back(prod/num);
            }
            else ans.push_back(prod);
        }
        return ans;

    }
};




class Solution2 {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> ans(n,1);
        for(int i=1;i<n;i++){
            ans[i]=arr[i-1]*ans[i-1];
        }
        int ryt=1;
        for(int i=n-1;i>=0;i--){
            ans[i]=ans[i]*ryt;
            ryt*=arr[i];
        }
        return ans;
    }
};




class Solution3 {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
        vector<int>res(n,1);
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]*arr[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]*arr[i+1];
        }
        for(int i=0;i<n;i++)
        {
             res[i]=prefix[i]*suffix[i];
        }
        return res;
    }
};

int main(){
    Solution2 sol;
    vector<int> arr={10, 3, 5, 6, 2};
    vector<int> ans=sol.productExceptSelf(arr);
    for(auto num:ans){
        cout<<num<<" ";
    }

    return 0;
}