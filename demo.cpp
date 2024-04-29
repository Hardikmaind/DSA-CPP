
#include <bits/stdc++.h>
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define lil long long int
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define input(i, a, n);          \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> a[i];            \
    }
#define wh(t) \
    int t;    \
    cin >> t; \
    while (t--)

using namespace std;


int main(){
    fastio;
    vector<int>v;
    wh(t){
        lil n;
        cin >> n;
        v.push_back(n);
        
    }
    for(auto& x: v){
        cout<<x<<" ";
    }
}