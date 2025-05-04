#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> freq;
        int count = 0;

        for (auto &x : dominoes) {
            // Normalize the domino so that smaller number comes first
            int a = min(x[0], x[1]);
            int b = max(x[0], x[1]);
            pair<int, int> p = {a, b};

            // Count how many times this normalized domino has already appeared
            count += freq[p];

            // Record its occurrence
            freq[p]++;
        }

        return count;
    }


};


class Solution {
    public:
       int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            unordered_map<int, int> freq;
            int count = 0;
            
            for (auto &d : dominoes) {
                int a = min(d[0], d[1]);
                int b = max(d[0], d[1]);
                int key = a * 10 + b; // since numbers are 1 to 9, this makes unique keys like 12, 21 => 12
                
                count += freq[key]; // for each previous match, you can form a new pair
                freq[key]++;
            }
            
            return count;
        }
    
    };


    int main(){
        Solution s;
        vector<vector<int>> dominoes = {{1,2}, {2,1}, {3,4}, {5,6}};
        cout << s.numEquivDominoPairs(dominoes) << endl; // Output: 1
        
        Solution2 s2;
        cout << s2.numEquivDominoPairs(dominoes) << endl; // Output: 1
        

        return 0;
    }