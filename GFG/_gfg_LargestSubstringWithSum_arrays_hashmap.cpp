#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> mp;
        int initialSum=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            initialSum+=arr[i];
            if(initialSum==k)
            count=i+1;
            else if(mp[initialSum-k]!=0)
            count=max(count,i-mp[initialSum-k]+1);
            if(mp[initialSum]==0)
            mp[initialSum]=i+1;
        }
        return count;
    }
};
int main(){
    Solution s;

    vector<int> arr={10, 5, 2, 7, 1, -10};
    int k=15;
    cout<<s.longestSubarray(arr,k);
}