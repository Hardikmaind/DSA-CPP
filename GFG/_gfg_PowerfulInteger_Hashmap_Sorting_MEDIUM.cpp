#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        map<int, int> mp;
        for(auto x : intervals){
            mp[x[0]]++;
            mp[x[1]+1]--;
        }
        int cnt = 0, check = 0, Max = -1;
        for(auto x : mp){
            cnt += x.second;
            if(cnt >= k){
                Max = x.first;
            }
            else if(check >= k){
                Max = x.first-1;
            }
            check = cnt;
        }
        return Max;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 5}, {4, 6}};
    int k = 2;
    cout << sol.powerfulInteger(intervals, k) << endl; // Output:
    return 0;
    
}