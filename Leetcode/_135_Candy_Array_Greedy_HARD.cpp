#include <bits/stdc++.h>
using namespace std;


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // Step 1: Initialize all to 1

        // Step 2: Left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Step 3: Right to left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Step 4: Sum up the candies
        int total = 0;
        for (int c : candies) {
            total += c;
        }

        return total;
    }
};


int main(){
    Solution obj;
    vector<int> ratings1 = {1, 0, 2};
    cout << obj.candy(ratings1) << endl; // Output: 5

    vector<int> ratings2 = {1, 2, 2};
    cout << obj.candy(ratings2) << endl; // Output: 4

    vector<int> ratings3 = {1, 3, 2, 2, 1};
    cout << obj.candy(ratings3) << endl; // Output: 9

    return 0;
}