#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        
        
        int n=a.size();
        int m=b.size();
        for(auto &x:b){
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        b.clear();
        for(int i=0;i<m;i++){
            
            b.push_back(a[i+n]);
        }
        for(int i=0;i<m;i++){
            a.pop_back();
            
        }
        
    }
};

int main(){
    Solution s;
    vector<int> a={1, 5, 9, 10, 15, 20};
    vector<int> b={2, 3, 8, 13};
    s.mergeArrays(a,b);
    for(auto x:a){
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto x:b){
        cout<<x<<" ";
    }
    cout<<endl;

}