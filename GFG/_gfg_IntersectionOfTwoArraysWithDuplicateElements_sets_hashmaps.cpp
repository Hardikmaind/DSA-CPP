#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>set;;
        for(auto &x:a){
            set.insert(x);
        }
        vector<int>res;
        for(auto &x:b){
            if(set.count(x)>0){
                res.push_back(x);
                set.erase(x);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> a = {1, 2,1,3,1};
    vector<int> b = {3,1,3,4,1};
    vector<int> res = s.intersectionWithDuplicates(a, b);
    for(auto &x:res){
        cout<<x<<" ";
    }
}