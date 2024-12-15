/*The problem you're describing involves finding the maximum number of guests that are at the hotel simultaneously, given a set of arrival and departure times. This is a common problem in interval management, and we can solve it efficiently using a sweep-line algorithm.

### Problem Breakdown:

For each test case:
1. We are given `N` arrival times and `N` departure times.
2. Our task is to calculate the maximum number of guests that are at the hotel at the same time.
3. If a guest arrives exactly when another departs, they are not considered to be at the hotel simultaneously.

### Approach:

To solve this problem efficiently:
1. **Event-based approach**: Treat each arrival and departure as events. An arrival increases the count of guests at the hotel, and a departure decreases it. We need to process these events in a sorted order to simulate the changes in the number of guests at the hotel.

2. **Sorting**:
   - We can treat each arrival as an event that increases the count of guests, and each departure as an event that decreases the count.
   - Sort these events by time. If two events have the same time, prioritize departures first (to ensure that guests who leave at the same time as others arrive are not considered as present simultaneously).

3. **Simulate guest counts**: Traverse through the sorted events and track the number of guests present at the hotel at each point in time, keeping track of the maximum number observed.

### Algorithm:

1. For each test case:
   - Create two lists: one for arrival times and one for departure times.
   - Create a list of events where each event is either an arrival or a departure, marking each as `+1` (arrival) or `-1` (departure).
   - Sort the events by time, prioritizing departures in case of ties.
   - Traverse the sorted events and maintain a running count of guests at the hotel, updating the maximum count whenever a new higher count is found.

### C++ Code Implementation:

```cpp

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure for events
struct Event
{
    int time;
    int type; // +1 for arrival, -1 for departure
};

bool compareEvents(const Event &e1, const Event &e2)
{
    // If times are the same, prioritize departure (type -1 before type +1)
    if (e1.time == e2.time)
    {
        return e1.type < e2.type;
    }
    return e1.time < e2.time;
}

int maxGuestsAtHotel(int N, vector<int> &arrivals, vector<int> &departures)
{
    vector<Event> events;

    // Add arrival and departure events to the list
    for (int i = 0; i < N; i++)
    {
        events.push_back({arrivals[i], 1});    // 1 indicates arrival
        events.push_back({departures[i], -1}); // -1 indicates departure
    }

    // Sort events by time (and type in case of tie)
    sort(events.begin(), events.end(), compareEvents);

    int currentGuests = 0;
    int maxGuests = 0;

    // Process events
    for (const auto &event : events)
    {
        currentGuests += event.type;               // Add 1 for arrival, subtract 1 for departure
        maxGuests = max(maxGuests, currentGuests); // Update maxGuests if needed
    }

    return maxGuests;
}

int main()
{
    int T;
    cin >> T; // Number of test cases

    while (T--)
    {
        int N;
        cin >> N; // Number of guests
        vector<int> arrivals(N), departures(N);

        // Input arrival times
        for (int i = 0; i < N; i++)
        {
            cin >> arrivals[i];
        }

        // Input departure times
        for (int i = 0; i < N; i++)
        {
            cin >> departures[i];
        }

        // Calculate and output the maximum number of guests at the hotel
        cout << maxGuestsAtHotel(N, arrivals, departures) << endl;
    }

    return 0;
}

/*
```

### Explanation of the Code:
1. **Input Parsing**:
   - The first integer `T` represents the number of test cases.
   - For each test case, we read the number of guests `N`, followed by two lists: `arrivals` and `departures`.

2. **Event Representation**:
   - We create two events for each guest: one for their arrival (`+1`) and one for their departure (`-1`).
   - These events are stored in a vector of `Event` structures.

3. **Sorting the Events**:
   - Events are sorted first by time, and if the time is the same for an arrival and a departure, the departure is processed first (as `-1` comes before `+1`).

4. **Processing the Events**:
   - We iterate through the sorted events, updating the `currentGuests` count based on whether the event is an arrival or a departure.
   - We track the maximum number of guests (`maxGuests`) encountered during the simulation.

5. **Output**:
   - After processing all events for a test case, the maximum number of simultaneous guests is printed.

### Time Complexity:
- Sorting the events takes `O(N log N)`, where `N` is the number of guests.
- Processing the events takes `O(N)`.
Thus, the time complexity for each test case is `O(N log N)`. Given that `T` can be up to 100 and `N` up to 100, this approach will run efficiently within the given constraints.

### Example Walkthrough:

#### Input:
```
3
3
1 2 3
4 5 6
5
1 2 3 4 5
2 3 4 5 6
7
13 6 5 8 2 10 12
19 18 6 9 9 11 15
```

#### Output:
```
3
1
3`
```

- In the first test case, the maximum overlap occurs when all three guests are at the hotel at the same time.
- In the second test case, the maximum overlap occurs with two guests at the hotel at once.
- In the third test case, the maximum overlap is three guests.

This solution efficiently handles multiple test cases and computes the desired result using sorting and event simulation.
*/