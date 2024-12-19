#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int n=arr.size();
        int cnt=0, diff=0;
        for(int i=0; i<n; i++){
            diff+=arr[i]-i;
            cnt+=(diff==0);
        }
        return cnt;
    }
};
int main(){
    vector<int> arr={4,3,2,1,0};
    Solution obj;
    cout<<obj.maxChunksToSorted(arr);        //ans is 1
    return 0;
}