
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        unordered_map<char,int> p;
        for(char ch:a){
            p[ch]++;
        }
        for(char ch:b){
            p[ch]++;
        }
        int n;
        cin>>n;
        unordered_map<char,int> child;
        while(n--){
            string c;
            cin>>c;
            for(char ch:c){
                child[ch]++;
            }
        }
        bool flag = true;
        for(auto ch:child){
            if(child[ch.first]>p[ch.first]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}


// test case
// 3
// tom marvoloriddle
// 2
// lord
// voldemort
// cheap up
// 1
// heapcup
// bruce wayne
// 2
// bat
// man

//output
// YES
// YES
// NO