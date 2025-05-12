#include <bits/stdc++.h>
using namespace std;

//! "most booked meeting room" problem, where you want to determine which room is booked the most number of times given n meeting rooms and a list of meetings
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {

        sort(meetings.begin(), meetings.end());
        // Available rooms (min-heap)
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) {
            available.push(i);
        }
        // Ongoing meetings: (endTime, roomNumber)
        typedef pair<long long, int> Meeting;
        priority_queue<Meeting, vector<Meeting>, greater<Meeting>> ongoing;
        // Track bookings
        vector<int> roomCount(n, 0);
        for (int i = 0; i < meetings.size(); ++i) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            // Free rooms whose meetings have ended
            while (!ongoing.empty() && ongoing.top().first <= start) {
                int freedRoom = ongoing.top().second;
                ongoing.pop();
                available.push(freedRoom);
            }
            if (!available.empty()) {
                int room = available.top();
                available.pop();
                ongoing.push({end, room});
                roomCount[room]++;
            } else {
                // Delay meeting until earliest room is free
                Meeting topMeeting = ongoing.top();
                ongoing.pop();
                long long newStart = topMeeting.first;
                long long duration = end - start;
                long long newEnd = newStart + duration;
                ongoing.push({newEnd, topMeeting.second});
                roomCount[topMeeting.second]++;
            }
        }
        // Find most used room
        int mostUsedRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (roomCount[i] > roomCount[mostUsedRoom]) {
                mostUsedRoom = i;
            }
        }
        return mostUsedRoom;
    }
};
//! THIS IS C++ 17 SUPPORTED CODE "The compilation error you're getting is due to structured bindings (auto [a, b] = pair;) — this syntax is only available in C++17 or later."
class Solution2 {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {

        //    code here
        sort(meetings.begin(), meetings.end());

        // Priority queue for available rooms (min-heap)
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) {
            available.push(i);
        }

        // Min-heap for ongoing meetings: (endTime, roomNumber)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> ongoing;

        // Count of how many times each room is used
        vector<int> roomCount(n, 0);

        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            // Free up rooms that have completed before current meeting's start
            while (!ongoing.empty() && ongoing.top().first <= start) {
                available.push(ongoing.top().second);
                ongoing.pop();
            }

            if (!available.empty()) {
                // Assign meeting to the smallest available room
                int room = available.top();
                available.pop();
                ongoing.push({end, room});
                roomCount[room]++;
            } else {
                // Delay meeting until earliest room becomes free
                auto [endTime, room] = ongoing.top();
                ongoing.pop();
                long long newEnd = endTime + (end - start); // extend duration
                ongoing.push({newEnd, room});
                roomCount[room]++;
            }
        }

        // Find the room with the most bookings
        int maxRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (roomCount[i] > roomCount[maxRoom]) {
                maxRoom = i;
            }
        }
        return maxRoom;
        
    }
};


int main(){
    Solution sol;
    vector<vector<int>> meetings = {{0, 6}, {2, 3}, {3, 7}, {4, 8},{6,8}};
    int n = 2;
    cout << sol.mostBooked(n, meetings) << endl; // Output: 0
    
    Solution2 sol2;
    cout << sol2.mostBooked(n, meetings) << endl; // Output: 0


    
    
    return 0;

}