#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& e1, const vector<int>& e2) {
        if (e1[0] == e2[0]) {
            return e1[1] < e2[1];
        }
        return e1[0] < e2[0];
    }

    static vector<vector<int>> mergeMeetings(vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), compare);
        vector<vector<int>> merged;
        
        merged.push_back(meetings[0]);
        for (int i = 1; i < meetings.size(); i++) {
            if (merged.back()[1] >= meetings[i][0]) {
                merged.back()[1] = max(meetings[i][1], merged.back()[1]);
            } else {
                merged.push_back(meetings[i]);
            }
        }
        return merged;  // Return merged intervals
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        meetings = mergeMeetings(meetings); // Use merged intervals

        int freeDays = 0;
        
        // Free days before the first meeting
        if (meetings[0][0] > 1) {
            freeDays += (meetings[0][0] - 1);
        }

        // Free days between meetings
        for (int i = 1; i < meetings.size(); i++) {
            freeDays += (meetings[i][0] - meetings[i - 1][1] - 1);
        }

        // Free days after the last meeting
        if (meetings.back()[1] < days) {
            freeDays += (days - meetings.back()[1]);
        }

        return freeDays;
    }
};

    int main(){
        Solution s;
        vector<vector<int>> meetings = {{5,7},{1,3},{9,10}};
        cout<<s.countDays(10,meetings);
        return 0;
    }