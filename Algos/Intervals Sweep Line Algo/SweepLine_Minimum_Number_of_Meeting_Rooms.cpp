#include <bits/stdc++.h>
using namespace std;

//! "Minimum Number of Meeting Rooms" problem can indeed be rephrased as finding the "maximum number of overlapping meetings" at any time.
struct Event {
    int time;
    int type; // +1 = start, -1 = end
};

bool compareEvents(const Event &a, const Event &b) {
    if (a.time == b.time)
        return a.type < b.type; // End (-1) before Start (+1) if times equal
    return a.time < b.time;
}

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<Event> events;

        for (const auto& interval : intervals) {
            events.push_back({interval[0], 1});   // Meeting starts
            events.push_back({interval[1], -1});  // Meeting ends
        }

        sort(events.begin(), events.end(), compareEvents);

        int maxRooms = 0;
        int current = 0;

        for (const auto& e : events) {
            current += e.type;
            maxRooms = max(maxRooms, current);
        }

        return maxRooms;
    }
};

//! this is Heap Based Solution. tc is O(nlogn) and sc is O(n)
class Solution2 {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Step 1: Sort by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Min-heap to track end times
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Step 3: Push the end time of the first meeting
        minHeap.push(intervals[0][1]);

        // Step 4: Process the rest
        for (int i = 1; i < intervals.size(); ++i) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            // If room is free, reuse it
            if (!minHeap.empty() && minHeap.top() <= start) {
                minHeap.pop();
            }

            // Assign room (new or reused)
            minHeap.push(end);
        }

        // The size of the heap is the number of rooms needed
        return minHeap.size();
    }
};


int main() {
    Solution sol;
    vector<vector<int>> meetings = {{0, 30}, {5, 10}, {15, 20}};
    cout << "Minimum number of meeting rooms required: " << sol.minMeetingRooms(meetings) << endl;

    Solution2 sol2;
    cout << "Minimum number of meeting rooms required (Heap): " << sol2.minMeetingRooms(meetings) << endl;
    return 0;
}

/*
Thus:
🔁 "Minimum number of meeting rooms"
is exactly equal to
🔁 "Maximum number of overlapping meetings at any point in time"

✅ Example:
Input:
[[0, 30], [5, 10], [15, 20]]

Timeline:
Meeting 1: 0 to 30
Meeting 2: 5 to 10
Meeting 3: 15 to 20

At time 5, meetings 1 and 2 are overlapping → need 2 rooms.
At time 15, meetings 1 and 3 are overlapping → still 2 rooms.

➡️ Maximum overlap = 2 ⇒ Minimum number of rooms = 2

🧠 Tip:
When you see “minimum X to schedule intervals,” it often means:

"Maximum number of overlaps" — because each overlapping group needs its own resource (room, processor, etc.)

*/