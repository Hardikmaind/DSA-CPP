#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-cost-for-tickets/solutions/3668433/minimum-cost-for-tickets
class Solution {
public:

    //! TABULATION METHOD tc: O(n) sc: O(n)
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, 0);
        
        int i = 0;
        for (int day = 1; day <= lastDay; day++) {
            if (day < days[i]) {
                dp[day] = dp[day - 1];
            } else {
                i++;
                dp[day] = min({dp[day - 1] + costs[0],
                               dp[max(0, day - 7)] + costs[1],
                               dp[max(0, day - 30)] + costs[2]});
            }
        }
     
        return dp[lastDay];
    }
};

class Solution2 {
public:

//! MEMOIZATION METHOD tc: O(n) sc: O(n)
    unordered_set<int> isTravelNeeded;
    
    int solve(vector<int>& dp, vector<int>& days, vector<int>& costs, int currDay) {
        // If we have iterated over travel days, return 0.
        if (currDay > days[days.size() - 1]) {
            return 0;
        }
        
        // If we don't need to travel on this day, move on to next day.
        if (isTravelNeeded.find(currDay) == isTravelNeeded.end()) {
            return solve(dp, days, costs, currDay + 1);
        }
        
        // If already calculated, return from here with the stored answer.
        if (dp[currDay] != -1) {
            return dp[currDay];
        }
        
        int oneDay = costs[0] + solve(dp, days, costs, currDay + 1);
        int sevenDay = costs[1] + solve(dp, days, costs, currDay + 7);
        int thirtyDay = costs[2] + solve(dp, days, costs, currDay + 30);
        
        // Store the cost with the minimum of the three options.
        return dp[currDay] = min(oneDay, min(sevenDay, thirtyDay));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // The last day on which we need to travel.
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, -1);
        
        // Mark the days on which we need to travel.
        for (int day : days) {
            isTravelNeeded.insert(day);
        }
        
        return solve(dp, days, costs, 1);
    }
};


int main(){
    Solution obj;
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    cout<<obj.mincostTickets(days, costs);
    return 0;

}