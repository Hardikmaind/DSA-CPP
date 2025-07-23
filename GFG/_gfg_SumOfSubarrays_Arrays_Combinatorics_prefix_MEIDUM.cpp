#include <bits/stdc++.h>
using namespace std;

//! this below is the most optimal solution with O(n) time complexity and O(1) space complexity
class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++){
            total += arr[i] * (i + 1) * (n - i);

        }
        return total;
        
    }
};


//! this below is the brute force solution with O(n^2) .but still faster that brute force
class Solution2 {
  public:
    int subarraySum(vector<int>& arr) {
        vector<int> prefix(arr.size() + 1, 0);
        for (int i = 1; i <= arr.size(); i++) {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }
        int total = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i; j < arr.size(); j++) {
                total += prefix[j + 1] - (i>0?prefix[i]:0);
            }
        }
        return total;

        
    }
};

//this is pure brute force solution with O(n^2) time complexity and O(1) space complexity
class Solution3 {
  public:
    int subarraySum(vector<int>& arr) {
        int total=0;
        for(int i=0;i<arr.size();i++){
            int sum=0;
            for(int j=i;j<arr.size();j++){
                sum += arr[j];
                total += sum;
            }
        }        
        return total;
    }
};

int main(){
    Solution obj;
    Solution2 obj2;
    Solution3 obj3;
    vector<int> arr = {1, 2, 3, 4};
    cout << "Optimal Solution: " << obj.subarraySum(arr) << endl;
    cout << "Brute Force with Prefix Sum: " << obj2.subarraySum(arr) << endl;
    cout << "Pure Brute Force: " << obj3.subarraySum(arr) << endl;
    return 0;
}