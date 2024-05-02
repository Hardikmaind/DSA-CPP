#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)


signed main()
{
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n , l , r;
        cin >> n >> l >> r;
        int a[n + 5];
        int point = 0 , low = 0 , high = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(l <= a[i] && a[i] <= r)
                point++;
            else
                point--;

            low = min(low , point);
            high = max(high , point);
        }
        cout << high << " " << low << '\n';

    }
}
// 2 
// 4 1 3
// 4 3 2 1
// 2 5 5
// 1 4