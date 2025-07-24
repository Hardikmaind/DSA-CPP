#include <bits/stdc++.h>
using namespace std;

// // User function Template for C++

// class Solution {
//   public:
//     vector<vector<string>> findSequences(string beginWord, string endWord,vector<string>& wordList) {
//         // code here
//         unordered_set<string>set(wordList.begin(),wordList.end());
//         queue<vector<string>>q;
//         q.push({beginWord});
//         int minlen=0;
//         while(!q.empty()){
//             int size=q.size();
//             string top=q.front().back();
//             if(top==endWord){
//                  minlen=q.front().size();
//                  break;
//             }
//             for(int k=0;k<size;k++){
//                 vector<string>vec;
//                 for(int i=0;i<top.size();i++){
//                     char og=top[i];
//                     for(char j='a';j<'z';j++){
//                         top[i]=j;
//                         if(set.find(top)!=set.end()){
//                             vec.push_back(top);
//                         }
                        
//                     }
//                     top[i]=og;
//                 }
//                 q.push(vec);
//             }
//             set.erase(top);
//         }
//         vector<vector<string>>res;
//         while(--minlen){
//             res.push_back(q.front());
//             q.pop();
//         }
//         return res;
        
        
//     }
// };

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> visited;
        bool found = false;

        while (!q.empty() && !found) {
            int levelSize = q.size();
            unordered_set<string> levelVisited;

            for (int i = 0; i < levelSize; ++i) {
                vector<string> path = q.front();
                q.pop();
                string lastWord = path.back();

                for (int j = 0; j < lastWord.size(); ++j) {
                    string temp = lastWord;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        temp[j] = ch;
                        if (dict.count(temp)) {
                            vector<string> newPath = path;
                            newPath.push_back(temp);
                            if (temp == endWord) {
                                result.push_back(newPath);
                                found = true;
                            } else {
                                q.push(newPath);
                                levelVisited.insert(temp);
                            }
                        }
                    }
                }
            }
            for (const auto& word : levelVisited)
                dict.erase(word);  // erase only after full level
        }
        return result;
    }
};


int main(){
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    vector<vector<string>> result = sol.findSequences(beginWord, endWord, wordList);
    
    for (const auto& sequence : result) {
        for (const auto& word : sequence) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}