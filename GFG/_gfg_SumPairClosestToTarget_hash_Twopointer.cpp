#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //! THIS IS M1 USING HASH MAP. TC IS O(N) AND SC IS O(N)
    vector<int> sumClosest(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        int s = 0, e = arr.size() - 1;
        int diff = INT_MAX;
        vector<int> ans;
        while (s < e)
        {
            int pairsum = arr[s] + arr[e];
            if (abs(target - pairsum) < diff)
            {
                diff = min(abs(target - pairsum), diff);
                ans = {arr[s], arr[e]};
            }
            if (pairsum < target)
                s++;
            else if (pairsum > target)
                e--;
            else
                return ans;
        }
        return ans;
    }
    //! THIS IS M2 USING TWO POINTER. TC IS O(NLOGN) AND SC IS O(1)
    vector<int> sumClosest2(vector<int> &arr, int target)
    {
        // code here
        if (arr.size() == 1)
        {
            return {};
        }

        sort(arr.begin(), arr.end());
        int i = 0;
        int j = arr.size() - 1;
        int ans1 = 0;
        int ans2 = 0;
        int diff;
        int maxi = INT_MAX;

        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum == target)
            {
                return {arr[i], arr[j]};
            }
            else
            {
                int rem = abs(target - sum);
                if (maxi > rem)
                {
                    ans1 = arr[i];
                    ans2 = arr[j];
                    maxi = rem;
                    diff = arr[j] - arr[i];
                }
                else if (maxi == rem)
                {
                    int di = arr[j] - arr[i];
                    if (diff < di)
                    {
                        ans1 = arr[i];
                        ans2 = arr[j];
                        diff = di;
                    }
                }
            }

            if (sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return {ans1, ans2};
    }

    // function to print hash map
    void printMap(map<int, vector<int>> &hm)
    {
        for (auto &x : hm)
        {
            cout << x.first << "->";
            for (auto &y : x.second)
            {
                cout << y << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr = {5, 2, 7, 1, 4};
    int target = 10;
    vector<int> res = s.sumClosest(arr, target);
    for (auto &x : res)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> res2 = s.sumClosest2(arr, target);
    for (auto &x : res2)
    {
        cout << x << " ";
    }
}