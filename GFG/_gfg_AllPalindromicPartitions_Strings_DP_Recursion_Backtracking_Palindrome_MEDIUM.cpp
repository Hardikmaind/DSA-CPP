#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
     void f(int i, string &s, vector<string>&v, vector<vector<string>>& ans){
        if(i>=s.size()){
            ans.push_back(v);
            return ;
        }
        for(int j = i;j<s.size();j++){
            string p = s.substr(i, j-i+1);
            string r = p;
            reverse(p.begin(), p.end());
            if(p==r){
                v.push_back(p);
                f(j+1,s,v,ans);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> ans;
        vector<string>v;
        f(0,s,v,ans);
        return ans;
    }
};


int main(){
    Solution sol;
    string s = "aab";
    vector<vector<string>> result = sol.palinParts(s);
    
    for (const auto& partition : result) {
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }
    
    return 0;
}