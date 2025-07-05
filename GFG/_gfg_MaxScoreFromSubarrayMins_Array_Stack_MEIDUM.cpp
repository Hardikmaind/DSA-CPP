#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int count=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            count=max(count,arr[i]+arr[i+1]);
        }
        return count;
    }
};

int main(){
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Maximum sum of adjacent elements: " << obj.maxSum(arr) << endl;
    return 0;
}