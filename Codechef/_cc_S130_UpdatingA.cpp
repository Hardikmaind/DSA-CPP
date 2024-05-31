#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    // in this the test cases are from given input and output files
    #ifndef ONLINE_JUDGE 
    freopen("../input.txt", "r", stdin); 
    freopen("../output.txt", "w", stdout); 
    #endif

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n],p[n+1];p[0]=0;
        int s=0;
        for(int i=0;i<n;i++){
            cin>>a[i];s+=a[i];
            p[i+1]=p[i]+a[i];
        }
        int mx=0,pmx=0;
        for(int i=2;i<n+1;i++){
            mx=max(mx,pmx-p[i]);
            pmx=max(pmx,p[i-1]);
        }
        cout<<s+2*mx<<"\n";
        
    }
}