#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     string clearStars(string s) {
//         priority_queue<char,vector<char>,greater<char>>pq;
//         int countstar=0;
//         for(auto&x:s){
//             if(x=='*'){

//             countstar++;
//             }
//         }
//         int i=0;
//         for(auto&x:s){
//             if(countstar>0){

//                 if(x=='*' && !pq.empty()){
//                     countstar--;
//                     pq.pop();

//                 }else{
//                     pq.push(x);
//                 }
//                 ++i;
//             }
//         }
//         string res="";
//         while(!pq.empty()){
//             res+=pq.top();
//             pq.pop();

//         }
//         res+=s.substr(i,s.size());
//         return res;
//     }
// };
class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<char, vector<char>, greater<char>> pq;  // Min-heap
        unordered_map<char, vector<int>> m;  // Stores indices of each character
        vector<bool> v(n, true);  // Marks whether each char in s should be kept

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                char temp = pq.top();  // Get smallest char so far
                pq.pop();
                int last = m[temp].back();  // Get last occurrence index
                m[temp].pop_back();
                v[i] = false;       // Remove '*'
                v[last] = false;    // Remove corresponding smallest char
            } else {
                pq.push(s[i]);
                m[s[i]].push_back(i);
            }
        }

        string result = "";
        for (int i = 0; i < n; i++) {
            if (v[i]) result += s[i];
        }
        return result;
    }
};


int main(){
    Solution sol;
    string s = "ab*c*d";
    cout << sol.clearStars(s) << endl;  // Output: "abcd"
    return 0;
}