#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string,int>>q;
        unordered_set<string>set(wordList.begin(),wordList.end());
        if (set.find(targetWord) == set.end()) return 0;
        q.push({startWord,1});
        set.erase(startWord);
        while(!q.empty()){
            auto top=q.front();
            string str=top.first;
            int steps=top.second;
            q.pop();
            if (str == targetWord){
                return steps;
            }
            for(int i=0;i<str.size();i++){
                char og=str[i];
               for(char j='a';j<='z';j++){
                str[i]=j;
                if(set.find(str) != set.end()){
                    set.erase(top.first);
                    q.push({str,steps+1});
                }
               }
               str[i]=og;       //! If you don’t restore it, then the next iteration (i+1) will operate on an already-mutated string, which corrupts the original word.
            }
        }
        return 0;           // no path found
    }
};

int main()
{
    Solution sol;
    std::vector<std::string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    std::string startword = "der";
    std::string endword = "dfs";
    auto res = sol.wordLadderLength(startword, endword, wordList);
    cout << res << endl; // Output the result
    return 0;
}