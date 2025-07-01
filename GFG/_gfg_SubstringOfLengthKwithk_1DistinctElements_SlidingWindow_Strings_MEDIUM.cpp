#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        unordered_map<char, int> m1;
        int distinct = 0;
        int ans = 0;
        for(int i = 0; i < k; i++){
            m1[s[i]]++;
            if(m1[s[i]] == 1){
                distinct++;
            }
        }
        if(distinct == k-1){
            ans++;
        }
        int i = 0;
        int j = k;
        while(j < s.size()){
            m1[s[j]]++;
            if(m1[s[j]] == 1){
                distinct++;
            }
            m1[s[i]]--;
            if(m1[s[i]] == 0){
                distinct--;
            }
            if(distinct == k-1){
                ans++;
            }
            i++;
            j++;
        }
        return ans;
    }
};


int main(){
    Solution sol;
    string s = "abcabc";
    int k = 3;
    cout << sol.substrCount(s, k) << endl; // Output: 4
    return 0;
}