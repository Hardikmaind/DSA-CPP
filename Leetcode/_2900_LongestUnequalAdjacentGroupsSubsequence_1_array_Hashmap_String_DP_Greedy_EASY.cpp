#include <bits/stdc++.h>    
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>res;
        int n=words.size();
        if(n==1){
            res.push_back(words[0]);
            return res;
        }
        res.push_back(words[0]);
        for(int i=1;i<n;i++){
            if(groups[i]!=groups[i-1]){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};

//! check here the for loop here is diff
class Solution1 {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>res;
        int n=words.size();
        if(n==1){
            res.push_back(words[0]);
            return res;
        }
        res.push_back(words[0]);
        for(int i=0;i<n-1;i++){
            if(groups[i]!=groups[i+1]){
                res.push_back(words[i+1]);
            }
        }
        return res;
    }
};


int main(){
    Solution obj;
    vector<string> words = {"a","b","c","d"};
    vector<int> groups = {1,0,1,1};
    vector<string> result = obj.getLongestSubsequence(words, groups);
    
    for (const string& word : result) {
        cout << word << " ";
    }
    // Output: a b c
    return 0;
}