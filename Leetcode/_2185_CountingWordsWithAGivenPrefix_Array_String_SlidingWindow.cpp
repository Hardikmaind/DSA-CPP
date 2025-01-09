#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/counting-words-with-a-given-prefix/solutions/6210583/counting-words-with-a-given-prefix

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(auto &x:words){
            if(x.find(pref) == 0){
                count++;
            }
        }
        return count;
    }
};

 int main(){
    Solution s;
    vector<string> words = {"pay","attention","practice","attend"};
    string pref = "at";
    cout<<s.prefixCount(words, pref);
 }