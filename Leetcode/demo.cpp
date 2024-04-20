
#include <iostream>
#include <string>
#include <vector>
using namespace std;



#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:   
    bool checkValidString(string& s) {
        int n=s.size();
        int bMin=0, bMax=0;
        for(int i=n-1; i>=0; i--){
            char c=s[i];
            bMin+=(c==')')-(c=='(')-(c=='*');
            bMax+=(c==')')-(c=='(')+(c=='*');
            if (bMax<0) return 0;
            bMin=max(bMin, 0);
        }
        return bMin==0;
    }




    bool checkValidString2(string& s) {
        int n=s.size();
        int dp[2][102]={0};// reduced space
        dp[n&1][0]=1;//base case
        for(int i=n-1; i>=0; i--){
            char c=s[i];
            for(int balance=0; balance<=n; balance++){
                int ans=0;
                switch(c){
                case '(': ans=dp[(i+1)&1][balance+1]; break;
                case ')': if (balance>0) ans=dp[(i+1)&1][balance-1]; break;
                case '*': 
                    ans|=dp[(i+1)&1][balance+1]||dp[(i+1)&1][balance];
                    if (balance>0) ans|=dp[(i+1)&1][balance-1];
                }
                dp[i&1][balance]=ans;
            }
        }
        return dp[0][0]==1;
    }






    int n;
    int dp[101][100];
    int f(int i, int balance, string& s){
        if (i==n) return balance==0;
        if (dp[i][balance]!=-1) return dp[i][balance];
        int ans=0;
        switch(s[i]){
            case '(': ans=f(i+1, balance+1, s); break;
            case ')': if (balance>0) ans=f(i+1, balance-1, s); break;
            case '*': 
                ans|=f(i+1, balance+1, s)||f(i+1, balance, s);
                if (balance>0) ans|=f(i+1, balance-1, s);
        }
        return dp[i][balance]=ans;
    }
    bool checkValidString(string& s) {
        n=s.size();
        memset(dp, -1, sizeof(dp));
        return f(0, 0, s)==1;
    }









    bool checkValidString(string& s) {
        int n=s.size();
        int dp[101][102]={0};

//early stop for unbalanced parenthesis string, set range for balance
        int bMin=0, bMax=0;
        vector<pair<int, int>> bRange(n);
        for(int i=n-1; i>=0; i--){//backward iteration, consistent with DP
            char c=s[i];
            bMin+=(c==')')-(c=='(')-(c=='*');//right-bracket +1, left-bracket -1
            bMax+=(c==')')-(c=='(')+(c=='*');//wildcard * might be -1,0,1
            if (bMax<0) return 0;// early stop
            bMin=max(bMin, 0);
        //    cout<<i<<"->"<<bMin<<","<<bMax<<endl;
            bRange[i]={bMin, bMax};//range ends for balance for index=i
        }

        dp[n][0]=1;//base case
        for(int i=n-1; i>=0; i--){
            char c=s[i];
            for(int balance=bRange[i].first; balance<=bRange[i].second; balance++){
                int ans=0;
                switch(c){
                case '(': ans=dp[(i+1)][balance+1]; break;
                case ')': if (balance>0) ans=dp[(i+1)][balance-1]; break;
                case '*': 
                    ans|=dp[(i+1)][balance+1]||dp[(i+1)][balance];
                    if (balance>0) ans|=dp[(i+1)][balance-1];
                }
                dp[i][balance]=ans;
            }
        }
        return dp[0][0]==1;
    }
};



auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


int main(){
    Solution s;
    string str="(*))";
    cout<<s.checkValidString(str);
    return 0;
}