#include <bits/stdc++.h>
using namespace std;

//! Intro To monotonic stacks => https://www.geeksforgeeks.org/introduction-to-monotonic-stack-2/

class Solution {
  public:
    string removeKdigits(string s, int k) {
        // code here
        stack<char>st;
        int i=0;
        while(i<s.size()){
            while(!st.empty() && k>0 && s[i]<st.top()){
                st.pop();
                k--;
            }
            st.push(s[i]);
            i++;
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        
        string res="";
        while(!st.empty()){
            res+=st.top();st.pop();
            
        }
        reverse(res.begin(),res.end());
        int j=0;
        while(j<s.size() && res[j]=='0'){
            j++;
            
        }
        string result=res.substr(j);
        return  result.empty()?"0":result;
    }
};


int main(){
    Solution obj;
    string s = "1432219";
    int k = 3;
    cout << obj.removeKdigits(s, k) << endl; // Output: "1219"
    
    s = "10200";
    k = 1;
    cout << obj.removeKdigits(s, k) << endl; // Output: "200"
    
    s = "10";
    k = 2;
    cout << obj.removeKdigits(s, k) << endl; // Output: "0"
    
    return 0;
}