
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
#define vvi vector<vi>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define mem(a, val) memset(a, val, sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    // cin.ignore(); must be there when using getline(cin, s)
    while (T--)
    {
        int N;
        cin >> N;
        vi A(N), D(N);

        // Read both arrays
        for (auto &x : A)
            cin >> x;
        for (auto &x : D)
            cin >> x;

        // Frequency map
        unordered_map<int, int> freqMap;
        for (auto &x : A)
            freqMap[x]++;
        for (auto &x : D)
            freqMap[x]++;

        // Find max frequency
        int maxFrequency = 0;
        for (const auto &x : freqMap)
        {
            maxFrequency = max(maxFrequency, x.second);
        }

        cout << maxFrequency << endl;
    }
    return 0;
}

/*
3
3
1 1 2
2 2 3
4
1 5 4 3
4 6 10 4
3
1 4 3
2 6 5
 */