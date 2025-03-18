
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector < int >
#define vll vector < ll >
#define vvi vector < vi >
#define pii pair < int, int >
#define pll pair < long long, long long >
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define mem(a, val) memset(a, val, sizeof(a))
#define eb emplace_back
#define gcd(a, b) ((b) == 0 ? (a) : GCD((b), (a) % (b)))
#define safelcm(a, b) (((a) / GCD((a), (b))) * (b))
#define f first
#define s second

using namespace std;

void solve(){
    //code here
    int n,m,k;
       cin>>n>>m>>k;

       int a = max({n,m,k});
       int b = min({n,m,k});
       int c = (n+m+k)-(a+b);
       if(b+c==a) cout<< "YES"<<endl;
       else cout<< "NO"<<endl;
    
  
    
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
     int T;
     cin >> T;
     // cin.ignore(); must be there when using getline(cin, s)
     while (T--)
     {

        solve();

     }
    return 0;
}


/*
!THIS ARE THE TEST CASES

3
3 1 2
2 2 4
3 2 5

!THIS IS THE OUTPUT
YES
YES
YES

*/


