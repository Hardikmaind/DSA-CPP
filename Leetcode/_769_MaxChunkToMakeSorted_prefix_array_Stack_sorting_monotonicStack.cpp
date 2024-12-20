#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    /*
    The best way to do this is to think that as all the numbers are unique and we know the size of array, so we know all elements in the array. so, we know that in the sorted array arr[i] = i, it means that if we compute a running sum of elements in the array, then if at any moment, the sum = i*(i+1)/2, then we should make a partition at that point. continuing this process will give us the max no. of partitions.
    like : 1, 0, 2, 3, 4
    running sum : 1, 1, 3, 6, 10
    i*(i+1)/2 : 0, 1, 3, 6, 10
    for this, sum = i*(i+1)/2 condition is correct 4 times, so answer is 4
    */
   //! below is the same above login but in a more optimized way
    int maxChunksToSorted(vector<int>& arr) {
        const int n=arr.size();
        int cnt=0, diff=0;
        for(int i=0; i<n; i++){
            diff+=arr[i]-i;
            cnt+=(diff==0);                 //!here we are checking if the sum is equal to i*(i+1)/2 or not(basically arr[i]==i). if yes, then we make a partition and increase the count of partitions else we add zero to the count of partitions
            // why sorting is not needed? because we know that all elements are unique and we know the size of array, so we know all elements in the array. so, we know that in the sorted array arr[i] = i
        }
        return cnt;
    }
};
int main(){
    vector<int> arr={4,3,2,1,0};
    //here running sum will be 4, 7, 9, 10, 10
    // and i*(i+1)/2 will be 0, 1, 3, 6, 10.            so only 1 term is same in both which is 10. so no of partitions = 1
    Solution obj;
    cout<<obj.maxChunksToSorted(arr);        //ans is 1
    return 0;
}