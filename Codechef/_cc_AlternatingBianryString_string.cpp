



// this is writeen by me




// #include <iostream>

// #include <string>

// using namespace std;

// int minOperationsToAlternating(string s) {
//     int count = 0;

//     for (int i = 1; i < s.length(); i++) {
//         if (s[i] == s[i - 1]) {
//             count++;
//             // Flip every character from index i to the end
//             for (int j = i; j < s.length(); j++) {
//                 s[j] = (s[j] == '0') ? '1' : '0'; // Flip the character
//             }
//         }
//     }

//     return count;
// }

// int main() {
//     int T;
//     cin >> T;

//     while (T--) {
//         int N;
//         cin >> N;
//         string S;
//         cin >> S;

//         int operations = minOperationsToAlternating(S);
//         cout << operations << endl;
//     }

//     return 0;
// }









// this is the fastio solution
#include <iostream>

// #include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define yy cout<<"YES"<<endl
#define nn cout<<"NO"<<endl
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define mapii map<int,int>
#define mapci map<char,int>
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define wh(t) int t; cin>>t; while(t--)

int main(){
	fastio;
	wh(t){
        int n;;
        cin >> n;
        string s;
        cin >> s; 
        int ans = 0;
        // for(int i = 1; i < n; i++){
        //     if(s[i] == s[i-1]){
        //         ans++;
        //     }
        // }

        // the above can also be written as since f1 is already defined and n is initialized and i is also initialized inside the f1.
        f1(i,n){
            if(s[i] == s[i-1]){
                ans++;
            }
        }
        cout << ans << endl;
        
    }
	return 0;
}