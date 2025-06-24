#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        stack<char> st;
        
        for(auto z : s){
          while((!st.empty()) && k && (st.top() < z)){
              st.pop();
              k--;
          }
          st.push(z);
        }
        
        while((!st.empty()) && k){
            st.pop();
            k--;
        }
        
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};




int main(){
    Solution sol;
    string s = "abcde";
    int k = 2;
    string result = sol.maxSubseq(s, k);
    
    cout << "Result: " << result << endl; // Expected output: "cde"
    
    return 0;
}