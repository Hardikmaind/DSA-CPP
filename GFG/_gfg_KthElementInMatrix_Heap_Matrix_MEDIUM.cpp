#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:  
    int count(vector<vector<int>> &arr, int mid)
    {
        int n=arr.size();
        int l=0,h=n-1,c=0;
        while(l<n && h>=0)
        {
            if(arr[l][h]<=mid)
            {
                c+=h+1;
                l++;
            }
            else    //if arr[l][h]>mid
                h--;
        }
        return c;
    }
    int kthSmallest(vector<vector<int>> &arr, int k) {
        int n=arr.size();
        int ans=0;
        int start=arr[0][0],end=arr[n-1][n-1];
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int c=count(arr,mid); //how many ele r less than or eq to mid
            if(c>=k){
                ans=mid;//as we r taking equal case here only
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
};


int main(){
    Solution obj;
    vector<vector<int>> arr = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;
    int result = obj.kthSmallest(arr, k);
    cout << "The " << k << "th smallest element in the matrix is: " << result << endl; // Output: The 8th smallest element in the matrix is: 13
    return 0;
}