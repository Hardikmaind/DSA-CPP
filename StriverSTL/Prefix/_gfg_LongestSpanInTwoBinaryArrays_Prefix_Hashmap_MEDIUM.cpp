#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n = a1.size();
        int ans = 0;
        unordered_map<int, int> ind;
        
        ind[0] = -1;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += (a1[i]-a2[i]);
            if(ind.find(sum) != ind.end())
                ans = max(ans, i-ind[sum]);
            else
                ind[sum] = i;
        }
        
        return ans;
        
    }
};

int main(){
    Solution sol;
    vector<int> a1 = {1, 0, 1, 0, 1};
    vector<int> a2 = {0, 1, 0, 1, 0};
    cout << sol.longestCommonSum(a1, a2) << endl; // Output: 5
    return 0;
}