#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        // could use prefix
        // TIME: 13mins 25seconds
        int n=s.length();
        vector<int>first_idx(26,-1),last_idx(26,-1);
        vector<int>pre(n,0);
        pre[0]=97+(s[0]-'a');
        first_idx[s[0]-'a']=0;
        last_idx[s[0]-'a']=0;
        for(int i=1;i<n;i++){
            int c=s[i]-'a';
            if(first_idx[c]==-1){
                first_idx[c]=i;
                last_idx[c]=i;
            }
            else{
                last_idx[c]=i;
            }
            pre[i]+=97+(c);
            pre[i]+=pre[i-1];
        }
        // for(int i=0;i<26;i++){
        //     cout<<first_idx[i]<<" "<<last_idx[i]<<endl;
        // }
        // for(int i=0;i<n;i++){
        //     cout<<pre[i]<<" ";
        // }
        // cout<<endl;
        vector<int>ans;
        for(int i=0;i<26;i++){
            if(first_idx[i]!=last_idx[i] && first_idx[i]!=-1){
                int sum=pre[last_idx[i]-1]-pre[first_idx[i]];
                if(sum!=0) ans.push_back(sum);
            }
        }
        return ans;
    }
};


int main(){
    Solution sol;
    string s = "abcdeabc";
    vector<int> result = sol.asciirange(s);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}