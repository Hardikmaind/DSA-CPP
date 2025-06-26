#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minValue(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;
        
        priority_queue<int> pq;
        for (auto& it : freq)
            pq.push(it.second);
        
        while (k-- > 0 && !pq.empty()) {
            int top = pq.top();
            pq.pop();
            top--;
            if (top > 0)
                pq.push(top);
        }

        int result = 0;
        while (!pq.empty()) {
            int count = pq.top();
            pq.pop();
            result += count * count;
        }

        return result;
    }
};


int main() {
    Solution sol;
    string s = "aabbcc";
    int k = 2;
    cout << sol.minValue(s, k) << endl; // Example usage
    return 0;
}