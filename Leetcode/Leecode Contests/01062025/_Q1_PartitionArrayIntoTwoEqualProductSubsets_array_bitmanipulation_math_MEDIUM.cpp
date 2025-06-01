#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkEqualPartitions(vector<int>& arr, long long target) {
        long long int allprod=1;
        int n=arr.size();
        int bitmask=1<<n;
        for(int mask=1;mask<bitmask-1;mask++){
            long long prod1=1;
            long long prod2=1;
            bool valid =true;
            for(int i=0;i<n;i++){
                if(mask& (1<<i)){
                    if (arr[i] > 0 && prod1 > target / arr[i]) {  // checked here if prod1*arr[i]>target
                        valid = false;
                        break;
                    }
                    prod1 *= arr[i];
                }else{
                   if (arr[i] > 0 && prod2 > target / arr[i]) {
                        valid = false;
                        break;
                    }
                    prod2 *= arr[i];
                }
            }
            if(valid && prod1==target && prod2==target){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {2, 3, 4, 6};
    long long target = 12;
    bool result = obj.checkEqualPartitions(arr, target);
    
    if (result) {
        cout << "Yes, the array can be partitioned into two subsets with equal product." << endl;
    } else {
        cout << "No, the array cannot be partitioned into two subsets with equal product." << endl;
    }
    
    return 0;
}