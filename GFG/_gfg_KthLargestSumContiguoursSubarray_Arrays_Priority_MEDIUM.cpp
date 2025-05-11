#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int kthLargest(vector<int>&arr,int k){
            priority_queue<int,vector<int>,greater<int>>pq;
            for(int i=0;i<arr.size();i++){
                int sum=0;
                for(int j=i;j<arr.size();j++){
                    sum+=arr[j];
                    if(pq.size()<k){
                        pq.push(sum);
                    }else{
                        if(sum>pq.top()){
                            pq.pop();
                            pq.push(sum);
                        }
                    }
                }
            }
            return pq.top();
        }
};
int main(){
    Solution obj;
    vector<int>arr={2,6,4,1};
    int k=3;
    cout<<obj.kthLargest(arr,k);
    return 0;
}