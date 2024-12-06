#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        int ar[26]={0};
        queue<int> q;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            ar[c-'a']++;
            q.push(i);

            while(!q.empty() && ar[s[q.front()]-'a']>1){
                q.pop();
            }

        }
            if(q.empty()){
                return -1;
            }else{
                return q.front();
            }
    }
};



int main(){
    Solution s;
    string s="leetcode";

    cout<<s.firstUniqChar(s)<<endl;
}

