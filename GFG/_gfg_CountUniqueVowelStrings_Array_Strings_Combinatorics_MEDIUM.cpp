#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int vowelCount(string& s) {
        map<char, int> mp;
        
        for(char c: s)
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') mp[c]++;
            
        int sz = mp.size(), ans = sz;
        
        
        for(int i = 2; i<sz; i++)  ans *= i;
        for(auto it: mp)    ans *= it.second;
        
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "aeiou";
    cout << sol.vowelCount(s) << endl; // Example usage
    return 0;
}