#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string resultingString(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if((!st.empty() && abs(st.top()-s[i])==1 )|| (!st.empty() && st.top()=='a' && s[i]=='z' ) || (!st.empty() && st.top()=='z' && s[i]=='a' )){
                st.pop();
            }else{

                st.push(s[i]);
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
    Solution sol;
    string s = "zadb";
    cout << sol.resultingString(s) << endl; // Example usage
    return 0;
}