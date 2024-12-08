/*Solution Explanation: Maximizing the Sum of Two Non-overlapping Events 🌟
Intuition 💡
The problem asks us to select at most two non-overlapping events such that the sum of their values is maximized. The key challenge is ensuring that the two selected events do not overlap. We need an approach that allows us to efficiently find the best combination of two events.

Thought Process 🧠:
Event Structure: Each event is represented by three values: the start time, the end time, and the value. The goal is to choose two events where one starts strictly after the other ends. The more valuable the event, the better, so we want to maximize the sum of their values.

Sorting by Start Time 📅: One of the first things we can do to organize the events is to sort them by their start time. This makes it easier to look ahead at events that may be a valid candidate for pairing.

Avoid Redundancy with a Suffix Array 🔄: Instead of searching for the best second event for every single event, we can create a suffix array that stores the maximum possible value for non-overlapping events that occur after a given event. This allows us to quickly get the best possible event for pairing, saving us from redundant checks.

Efficient Searching with Binary Search 🔍: After sorting the events, we can use binary search to find the next valid event that starts after the current event ends. This ensures that we can efficiently check for valid pairs without having to iterate over all subsequent events.

Approach 🔧
1. Sort Events by Start Time 📊
The first step is to sort the events based on their start time. This way, we process each event in chronological order, making it easy to find the subsequent event that starts after the current event ends. Sorting ensures that we can quickly identify events that may or may not overlap with the current one.

2. Create a Suffix Array 🗂
We create a suffix array to keep track of the maximum possible value of non-overlapping events from the current event to the last event. The idea behind the suffix array is simple:

Start by initializing the last event’s value as the maximum value.
Then, working backwards through the list of events, update the suffix array with the highest event value encountered so far.
This array allows us to quickly access the best possible future event without needing to repeatedly check all future events.
3. Binary Search for Non-overlapping Events 🔍
For each event, we need to find the first event that starts after the current event ends. Since the events are sorted by start time, we can use binary search to efficiently find this next valid event. If no such event exists, we just move on to the next one. If a valid event is found, we can easily retrieve its value from the suffix array and calculate the total value.

4. Maximize the Total Value 💸
For each event:

First, we check if attending only this event yields a higher value than the current maximum sum.
Then, if a valid second event is found (using the binary search), we calculate the sum of the current event’s value and the best possible future event value (from the suffix array).
We update the maximum sum accordingly, ensuring that we track the best combination of non-overlapping events.
Complexity 📈
Time Complexity ⏱️:

Sorting the events by their start time takes (O(n \log n)).
For each event, binary search is used to find the next event that starts after the current event ends, which takes (O(\log n)).
Therefore, the overall time complexity is (O(n \log n)), where (n) is the number of events.
Space Complexity 📦:

We use an array of size (n) to store the suffix maximum values. This space is necessary to store the maximum values of non-overlapping events starting from each index.
Therefore, the space complexity is (O(n)). */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
        }
        
        int maxSum = 0;
        
        for (int i = 0; i < n; ++i) {
            int left = i + 1, right = n - 1;
            int nextEventIndex = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1]) {
                    nextEventIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            if (nextEventIndex != -1) {
                maxSum = max(maxSum, events[i][2] + suffixMax[nextEventIndex]);
            }
            
            maxSum = max(maxSum, events[i][2]);
        }
        
        return maxSum;
    }
};

int main(){
    Solution s;
    vector<vector<int>> events = {{1, 2, 3}, {3, 4, 4}, {5, 6, 5}, {7, 8, 6}, {9, 10, 7}};
    cout << s.maxTwoEvents(events) << endl;
    return 0;
}