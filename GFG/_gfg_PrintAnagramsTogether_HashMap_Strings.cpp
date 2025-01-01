#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        map<string,vector<string>>mp;
        for(auto i:arr){
            string temp =i;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(i);
        }
        vector<vector<string>>res;
        for(auto i:mp){
            res.push_back(i.second);
        }
        return res;
    }
};


int main(){
    Solution s;
    vector<string> arr = {"act","god","cat","dog","tac"};
    vector<vector<string>> res = s.anagrams(arr);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}