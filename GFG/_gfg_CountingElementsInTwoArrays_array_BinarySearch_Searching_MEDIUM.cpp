#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // cosort(de here
        vector<pair<int,int>>v;
        for(int i = 0 ; i<a.size(); i++){
            v.push_back({a[i],i});
        }
        sort(v.begin(),v.end());
        sort(b.begin(),b.end());
        vector<int>result(a.size(),0);
        int n = a.size();
        int m = b.size();
        int j = 0;
        for(int i = 0 ; i<n ; i++){
            while(j<m && b[j]<=v[i].first){
                j++;
            }
            result[v[i].second]=j;
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> a = {1, 3, 2, 4};
    vector<int> b = {2, 3, 5};
    vector<int> result = sol.countLessEq(a, b);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}