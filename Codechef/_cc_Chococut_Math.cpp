
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
     int n,m,k;cin>>n>>m>>k;
      int t=(ceil(1.0*k/n)*n)-k;
	    int r=(ceil(1.0*k/m)*m)-k;
	    if(t<r)
	    {
	        cout<<n*(m-(ceil(1.0*k/n)))<<endl;
	    }
	    else{
	        cout<<m*(n-(ceil(1.0*k/m)))<<endl;
	        
	    }
   
     
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
 input:
5
3 4 2
3 4 4
6 5 28
9 7 23
5 5 0

output:
9
8
0
36
25

 */