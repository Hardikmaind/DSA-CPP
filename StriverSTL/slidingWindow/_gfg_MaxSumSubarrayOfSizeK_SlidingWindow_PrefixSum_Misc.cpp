#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

    //! TIME COMPLEXITY IS O(1) AND SPACE COMPLEXITY IS O(1)
        int maximumSumSubarray(vector<int>& arr, int k) {
            // code here
            int maxsum=0;
            for(int i=0;i<k;i++){
                maxsum+=arr[i];
            }
            int res=maxsum;
            for(int i=k;i<arr.size();i++){
                maxsum+=arr[i] - arr[i - k];
                res=max(res,maxsum);
            }
            return res;
        }

};
int main(){
    vector<int> arr={100, 200, 300, 400};
    int k=2;
    Solution obj;
    int res=obj.maximumSumSubarray(arr,k);
    cout<<res<<endl;
    return 0;
}