
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


// Define a structure for events
struct Event {
    int time;
    int type; // +1 for arrival, -1 for departure
};

bool compareEvents(const Event &e1, const Event &e2) {
    // If times are the same, prioritize departure (type -1 before type +1)
    if (e1.time == e2.time) {
        return e1.type < e2.type;
    }
    return e1.time < e2.time;
}

int maxGuestsAtHotel(int N, vector<int>& arrivals, vector<int>& departures) {
    vector<Event> events;
    
    // Add arrival and departure events to the list
    for (int i = 0; i < N; i++) {
        events.push_back({arrivals[i], 1});  // 1 indicates arrival
        events.push_back({departures[i], -1});  // -1 indicates departure
    }

    // Sort events by time (and type in case of tie)
    sort(events.begin(), events.end(), compareEvents);

    int currentGuests = 0;
    int maxGuests = 0;
    
    // Process events
    for (const auto& event : events) {
        currentGuests += event.type;  // Add 1 for arrival, subtract 1 for departure
        maxGuests = max(maxGuests, currentGuests);  // Update maxGuests if needed
    }

    return maxGuests;
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    // cin.ignore(); must be there when using getline(cin, s)
    while (T--){
        int N;
        cin >> N;  // Number of guests
        vector<int> arrivals(N), departures(N);
        
        // Input arrival times
        for (int i = 0; i < N; i++) {
            cin >> arrivals[i];
        }
        
        // Input departure times
        for (int i = 0; i < N; i++) {
            cin >> departures[i];
        }

        // Calculate and output the maximum number of guests at the hotel
        cout << maxGuestsAtHotel(N, arrivals, departures) << endl;
        
    }
    return 0;
}