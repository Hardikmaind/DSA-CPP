#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/solutions/6214544/count-prefix-and-suffix-pairs-i
class Solution {
public:
// ! THIS IS A SUBSTRING LOGIC
static bool isPrefixAndSuffix2(string &s1, string &s2) {
    // Check if s1 is a prefix of s2
    bool isPrefix = s2.substr(0, s1.length()) == s1;

    // Check if s1 is a suffix of s2
    bool isSuffix = s2.substr(s2.length() - s1.length()) == s1;

    // Return true if both conditions are satisfied
    return isPrefix && isSuffix;
}

//! this is a lenght logic
    static bool isPrefixAndSuffix(string &s1, string &s2) {
        if (s1.length() > s2.length()) {
            return false; 
        }

        bool isPrefix = (s2.find(s1) == 0);

        bool isSuffix = (s2.rfind(s1) == s2.length() - s1.length());

        return isPrefix && isSuffix;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int j=words.size()-1;j>=0;j--){
            for(int i=0;i<j;i++){
                if(isPrefixAndSuffix(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
        
    }
};
int main(){
    Solution s;
    vector<string> words={"a","aba","ababa","aa"};
    cout<<s.countPrefixSuffixPairs(words);
    return 0;
}