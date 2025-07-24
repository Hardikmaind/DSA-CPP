#include <bits/stdc++.h>
using namespace std;

//? THIS BELOW USES THE BACKTRACKING APPROACH
class Solution {
private:
    unordered_map<string, int> map;
    vector<vector<string>> ans;
    string b;
    void dfs(string word, vector<string> seq) {
        if (word==b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = map[word];
        for (int i = 0; i < word.size(); i++) {
            char og = word[i];
            for (char j = 'a'; j <= 'z'; j++) {
                word[i] = j;
                if (map.find(word) != map.end() && map[word] + 1 == steps) {
                    seq.push_back(word);

                    dfs(word, seq);
                    seq.pop_back();
                }
                word[i] = og;
            }
        }
    }

public:
    vector<vector<string>> findLadders(string startWord, string targetWord,
                                       vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> set(wordList.begin(), wordList.end());
        b = startWord;
        q.push(startWord);
        map[startWord] = 1;
        set.erase(startWord);
        while (!q.empty()) {
            string str = q.front();
            int steps = map[str];
            q.pop();
            if (str == targetWord) {
                break;
            }
            for (int i = 0; i < str.size(); i++) {
                char og = str[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    str[i] = j;
                    if (set.find(str) != set.end()) {
                        q.push(str);
                        set.erase(str);
                        map[str] = steps + 1;
                    }
                }
                str[i] =
                    og; //! If you don’t restore it, then the next iteration
                        //! (i+1) will operate on an already-mutated string,
                        //! which corrupts the original word.
            }
        }
            if (map.find(targetWord) != map.end()) {
                vector<string> seq;
                seq.push_back(targetWord);
                dfs(targetWord, seq);
            }
        return ans; // no path found
    }
};


//? THIS BELOW USES THE BFS APPROACH AND SHOULD BE PREFERRED FOR EASE OF UNDERSTANDING
class Solution2 {
public:
    int isPresent(string &a, vector<string>& w) {
        for (int i = 0; i < w.size(); ++i) {
            if (a == w[i]) return i;
        }
        return -1;
    }

    bool differBy1(const string &a, const string &b) {
        if (a.size() != b.size()) return false;
        int count = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                count++;
                if (count > 1) return false;
            }
        }
        return count == 1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int src = isPresent(beginWord, wordList);
        int dest = isPresent(endWord, wordList);

        if (dest == -1) return {};

        if (src == -1) {
            wordList.push_back(beginWord);
            src = wordList.size() - 1;
        }

        int n = wordList.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (differBy1(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // BFS to build parent pointers
        vector<int> dist(n, INT_MAX);
        vector<vector<int>> parents(n);
        queue<int> q;
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    parents[v].clear();
                    parents[v].push_back(u);
                    q.push(v);
                } else if (dist[v] == dist[u] + 1) {
                    parents[v].push_back(u);
                }
            }
        }

        vector<vector<string>> res;
        if (dist[dest] == INT_MAX) return {};

        vector<int> path;
        function<void(int)> dfs = [&](int u) {
            path.push_back(u);
            if (u == src) {
                vector<string> seq;
                for (int i = path.size() - 1; i >= 0; --i)
                    seq.push_back(wordList[path[i]]);
                res.push_back(seq);
            } else {
                for (int p : parents[u])
                    dfs(p);
            }
            path.pop_back();
        };

        dfs(dest);
        return res;
    }
};
// auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });       //! THIS WILL MAKE THE RUNTIME OF THE FILE IN LEETCODE TO BE ZERO



int main(){
    Solution sol;
    std::vector<std::string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    std::string startword = "der";
    std::string endword = "dfs";
    auto res = sol.findLadders(startword, endword, wordList);
    
    for (const auto& seq : res) {
        for (const auto& word : seq) {
            cout << word << " ";
        }
        cout << endl; // Output each sequence
    }
    

    Solution2 sol2;
    auto res2 = sol2.findLadders(startword, endword, wordList);
    for (const auto& seq : res2) {
        for (const auto& word : seq) {
            cout << word << " ";
        }
        cout << endl; // Output each sequence
    }
    return 0;
}