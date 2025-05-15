#include <bits/stdc++.h>
using namespace std;    

class Solution {
  public:
  //! this is the brute force appraoh. tc is O(n^2)
    int countSubstring(string &s) {
        // code here
        int count=0;
        
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(s[i]==s[j]){
                    count++;
                }
            }
        }
        return count;
    }
};


int main(){
    Solution obj;
    string s="abcab";
    cout<<obj.countSubstring(s)<<endl;
    // Output: 7

    return 0;
}