#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string smallestPalindrome(string s) {
            int n =s.size();
            if(n==1 || n==2){
                return s;
            }
            string half=s.substr(0,n/2);
            sort(half.begin(),half.end());
            string rev=half;
            reverse(rev.begin(),rev.end());
            if(n%2==1){
                half+=s[n/2];
            }
            return half+rev;
            
        }
    };


    int main(){
        Solution s;
        string str="babab";
        cout<<s.smallestPalindrome(str)<<endl;
        return 0;
    }