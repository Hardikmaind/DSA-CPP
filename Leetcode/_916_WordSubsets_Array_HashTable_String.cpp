#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:
//! time complexity is O(n * m) where n is the number of words in A and m is the number of words in B. and because we are using a hash table to store the frequency of characters, the space complexity is O(1) as the size of the hash table is fixed to 26.
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        
        // Step 1: Build the character frequency map for words2.
        unordered_map<char, int> required;
        for (const string& word : words2) {
            unordered_map<char, int> temp;
            for (char c : word) {
                temp[c]++;
                required[c] = max(required[c], temp[c]);
            }
        }

        // Step 2: Iterate through words1 and check if they satisfy the conditions.
        for (const string& word : words1) {
            unordered_map<char, int> wordCount;
            for (char c : word) {
                wordCount[c]++;
            }

            bool isValid = true;
            for (const auto& entry : required) {
                if (wordCount[entry.first] < entry.second) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                res.push_back(word);
            }
        }

        return res;
    }
};



class Solution {
public:
// ! tc is O(n) where n is the total number of characters in all the words in A and B and sc is O(1) as the size of the maxCharFreq and tempCharFreq is fixed to 26.
    vector<string> wordSubsets(vector<string>& mainWords, vector<string>& requiredWords) {
        int maxCharFreq[26] = {0};
        int tempCharFreq[26];
        
        for (const auto& word : requiredWords) {
            memset(tempCharFreq, 0, sizeof tempCharFreq);//To Set Temp freq all to zero 
//You can do vector<int> tempCharFreq(26,0);
            for (char ch : word) {
                tempCharFreq[ch - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxCharFreq[i] = max(maxCharFreq[i], tempCharFreq[i]);
            }
        }
        
        vector<string> universalWords;
        
        for (const auto& word : mainWords) {
            memset(tempCharFreq, 0, sizeof tempCharFreq);
            for (char ch : word) {
                tempCharFreq[ch - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (maxCharFreq[i] > tempCharFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                universalWords.emplace_back(word);
            }
        }
        
        return universalWords;
    }
};
int main(){
    Solution s;
    vector<string> mainWords = {"amazon","apple","facebook","google","leetcode"};
    vector<string> requiredWords = {"e","o"};
    vector<string> res = s.wordSubsets(mainWords,requiredWords);
    for(auto x:res){
        cout<<x<<" ";
    }

cout<<endl;
    Solution2 s2;
    vector<string> mainWords2 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> requiredWords2 = {"e","o"};
    vector<string> res2 = s2.wordSubsets(mainWords2,requiredWords2);
    for(auto x:res2){
        cout<<x<<" ";
    }
    return 0;
}