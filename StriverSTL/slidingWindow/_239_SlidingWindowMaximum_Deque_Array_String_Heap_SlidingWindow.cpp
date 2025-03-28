#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

    //! THIS IS THE MOST OPTIMISED CODE. TC IS O(N) AND SC IS O(N)
        vector<int>maxSlidingWindow(vector<int>&nums,int k){
            vector<int>res;
            deque<int>dq;
            for(int i=0;i<nums.size();i++){
                if(!dq.empty() && dq.front()==(i-k)){
                    dq.pop_front();
                }
                while(!dq.empty() && nums[dq.back()]<nums[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
                if(i>=k-1){
                    res.push_back(nums[dq.front()]);
                }
            }
            return res;
        }

        //* THIS CODE HAS TC O(N*K) AND SC O(N-K+1)
        vector<int>maxSlidingWindow2(vector<int>&nums,int k){
            vector<int>res;
            int maxele=INT_MIN;
        
            int l=0;
            int r=k-1;
            while(r<nums.size()){
                while(l<=r){
                    maxele=max(maxele,nums[l]);
                    l++;
                }
                r++;
                l=r-k+1;
                res.push_back(maxele);
                maxele=INT_MIN;
            }
            return res;
        }

};
int main(){
    Solution obj;
    vector<int>nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int>res=obj.maxSlidingWindow(nums,k);
    for(auto i:res){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"==========================================="<<endl;

    vector<int>nums2={1,3,-1,-3,5,3,6,7};
    int k2=3;
    vector<int>res2=obj.maxSlidingWindow2(nums2,k2);
    for(auto i:res2){
        cout<<i<<" ";
    }
    return 0;
}