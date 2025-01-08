#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
         sort(arr.begin(), arr.end()); 

        int count=0;
    for (int i = arr.size() - 1; i >= 2; i--) {
        int l = 0;         
        int r = i - 1;     

        while (l < r) {
            if (arr[l] + arr[r] > arr[i]) {
               
                count += (r - l);
                r--;       
            } else {
                l++;       
            }
        }
    }

    return count;
        
    }
};

int main(){
    Solution s;
    vector<int> arr = {10, 21, 22, 100, 101, 200, 300};
    cout<<s.countTriangles(arr);
}