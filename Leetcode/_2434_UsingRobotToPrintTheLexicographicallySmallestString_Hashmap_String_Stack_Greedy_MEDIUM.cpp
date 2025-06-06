#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string robotWithString(string s) {
        stack<char>t;
        string paper="";
        unordered_map<char,int>hm;
        for(auto&x:s){
            hm[x]++;
        }
        char minChar='a';
            for(auto x:s){
            t.push(x);
            hm[x]--;
            while(!hm[minChar] && minChar<'z'){     //yaha minChar change kiya hain
                minChar++;
            }
            while(!t.empty() && t.top()<=minChar){      //ya minChar se compare kiya hain
                paper+=t.top();
                t.pop();
            }
        }
        while(!t.empty()){          //yaha stack flush kiya hai akhri mein, jo bache the woh
            paper+=t.top();
            t.pop();
        }
        return paper;
    }
};

int main(){
    Solution sol;
    string s = "zza";
    cout << sol.robotWithString(s) << endl; // Output: "azz"
    return 0;
}