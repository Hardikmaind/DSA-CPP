#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        int first=-1;
        int second=-1;
        int count=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                count++;
                if(first==-1){
                    first=i;
                }else{
                    second=i;
                }
            }
        }
        if(count!=2){
            return false;
        }
        return s1[first]==s2[second] && s1[second]==s2[first];
    }
};

int main() {
    Solution obj;
    string s1="bank";
    string s2="kanb";
    cout<<boolalpha<<obj.areAlmostEqual(s1,s2);
    return 0;
}   
