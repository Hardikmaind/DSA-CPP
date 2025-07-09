#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size(), res = 0, t = 0;
        for (int i = 0; i < n; i++) {
            t += endTime[i] - startTime[i];
            int left = i <= k - 1 ? 0 : endTime[i - k];
            int right = i == n - 1 ? eventTime : startTime[i + 1];
            res = max(res, right - left - t);
            if (i >= k - 1) {
                t -= endTime[i - k + 1] - startTime[i - k + 1];
            }
        }
        return res;
    }
};


int main(){
    Solution sol;
    int eventTime = 10;
    int k = 2;
    vector<int> startTime = {1, 3, 5, 7};
    vector<int> endTime = {2, 4, 6, 8};
    
    cout << sol.maxFreeTime(eventTime, k, startTime, endTime) << endl; // Output: 2
    return 0;
}