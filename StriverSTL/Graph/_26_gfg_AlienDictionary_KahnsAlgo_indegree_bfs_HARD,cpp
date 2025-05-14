#include <bits/stdc++.h>
using namespace std;


//! this uses the kahn's algorithm to find the topological sort of the graph. and uses vector present to check cycle


class Solution1 {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        vector<vector<int>> adj(26);          // For 26 letters
        vector<bool> present(26, false);      // Marks present letters
        vector<int> indegree(26, 0);          // For all characters

        // Mark present characters
        for (auto &word : words) {
            for (char c : word) {
                present[c - 'a'] = true;
            }
        }

        // Build graph from adjacent words
        for (int i = 0; i < n - 1; i++) {
            string str1 = words[i];        
            string str2 = words[i + 1];        
            int len = min(str1.size(), str2.size());
            bool check = false;
            for (int ind = 0; ind < len; ind++) {
                if (str1[ind] != str2[ind]) {
                    adj[str1[ind] - 'a'].push_back(str2[ind] - 'a');
                    indegree[str2[ind] - 'a']++;
                    check = true;
                    break;
                }
            }
            // Invalid case: word1 is longer and is prefix of word2
            if (!check && str1.length() > str2.length()) {
                return "";
            }
        }

        // Topological sort (Kahn's algorithm)
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans = ""; 
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans += char(node + 'a');

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Check for cycle
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] > 0) {
                return "";  // Cycle detected
            }
        }

        return ans;
        
    }
};

//! tc is better than above because of set
class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        vector<vector<int>> adj(26);          // For 26 letters
        unordered_set<int> present;     
        vector<int> indegree(26, 0);          // For all characters
        // Mark present characters
        for (auto &word : words) {
            for (char c : word) {
                present.insert(c - 'a');
            }
        }
        // Build graph from adjacent words
        for (int i = 0; i < n - 1; i++) {
            string str1 = words[i];        
            string str2 = words[i + 1];        
            int len = min(str1.size(), str2.size());
            bool check = false;
            for (int ind = 0; ind < len; ind++) {
                if (str1[ind] != str2[ind]) {
                    adj[str1[ind] - 'a'].push_back(str2[ind] - 'a');
                    indegree[str2[ind] - 'a']++;
                    check = true;
                    break;
                }
            }
            // Invalid case: word1 is longer and is prefix of word2
            if (!check && str1.length() > str2.length()) {
                return "";
            }
        }
        // Topological sort (Kahn's algorithm)
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (present.count(i) && indegree[i] == 0) {
                q.push(i);
            }
        }
        string ans = ""; 
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans += char(node + 'a');

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        //! instead of thi, if used the set as present , then we can directly check cyucle present or not , with => if ans.size()==set.size() then no cycle present else present
        // Check for cycle
        return ans.size()==present.size()?ans:"";
        
    }
};


int main(){
    // Example usage
    vector<string> words = {"caa", "aaa", "aab"};
    Solution sol;
    string order = sol.findOrder(words);
    cout << "Alien Dictionary Order: " << order << endl;

    // this is more optimized version of the above code
    Solution1 sol1;
    string order1 = sol1.findOrder(words);
    cout << "Alien Dictionary Order: " << order1 << endl;
    

    return 0;
}