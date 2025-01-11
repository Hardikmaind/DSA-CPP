#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        // unordered_set<char>set;
        // int maxcount=INT_MIN;
        
        
        // for(int i=0;i<s.length();i++){
        //     if(set.count(s[i])>0){
        //         set.clear();
        //     }else{
        //         set.insert(s[i]);
        //         maxcount=max(maxcount,set.size());
        //     }
        // }
        // return maxcount;
         std::unordered_set<char> set;
        int maxcount = 0;
        int start = 0;
    
        for (int end = 0; end < s.length(); end++) {
            while (set.count(s[end]) > 0) {
                set.erase(s[start]);  // Remove characters from the start of the window
                start++;              // Move the start of the window forward
            }
            set.insert(s[end]);        // Add the current character to the set
            maxcount = std::max(maxcount, (int)set.size());
        }
        return maxcount;
    }
};

int main(){
    Solution s;
    string str="geeksforgeeks";
    cout<<s.longestUniqueSubstr(str);
    return 0;
}