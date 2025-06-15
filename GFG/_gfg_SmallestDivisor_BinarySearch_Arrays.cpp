#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int helper(vector<int>& arr, int divisor){
        int sum=0;
        for(int i=0; i<arr.size(); i++){
            sum+=ceil((double)arr[i]/(double)divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int low=1, high=*max_element(arr.begin(), arr.end()), ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int currsum=helper(arr,mid);
            if(currsum<=k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1, 2, 5, 9};
    int k = 6;
    cout << "Smallest Divisor: " << sol.smallestDivisor(arr, k) << endl; // Example usage
    return 0;
}