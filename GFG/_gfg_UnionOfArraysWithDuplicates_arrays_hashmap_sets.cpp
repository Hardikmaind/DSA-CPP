#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>st;
        for(auto &x:a){
            st.insert(x);
        }
        for(auto &x:b){
            st.insert(x);
        }
        return st.size();
    }
};
int main(){
    Solution ob;
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 3, 4, 4, 5};
    cout<<ob.findUnion(a,b)<<endl;
}