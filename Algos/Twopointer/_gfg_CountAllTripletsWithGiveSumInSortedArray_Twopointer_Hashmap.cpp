#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int count=0;
        int n=arr.size();
        for(int i=0;i<=n-3;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum>target) k--;
                else if(sum<target)j++;
                else if(sum==target){
                    count++;
                    int temp=j+1;
                    while(temp<k&& arr[temp]==arr[temp-1])count++,temp++;
                    k--;
                }
            }
        }
        return count;
    }
};
int main(){
    Solution s;
    vector<int> arr={-3, -1, -1, 0, 1, 2};
    int target=-2;
    cout<<s.countTriplets(arr,target);
}