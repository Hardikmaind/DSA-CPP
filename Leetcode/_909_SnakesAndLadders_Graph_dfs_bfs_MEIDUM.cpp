#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/snakes-and-ladders/solutions/6797437/using-bfs-with-images-example-walkthrough-c-python-java
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> min_rolls(n * n + 1, -1);
        queue<int> q;
        min_rolls[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 1; i <= 6 && x + i <= n * n; i++) {
                int t = x + i, row = (t - 1) / n, col = (t - 1) % n;
                int v = board[n - 1 - row][row % 2 ? n - 1 - col : col];
                int y = v > 0 ? v : t; // follow ladder / snake if present
                if (y == n * n)
                    return min_rolls[x] + 1;
                if (min_rolls[y] == -1) {
                    min_rolls[y] = min_rolls[x] + 1;
                    q.push(y);
                }
            }
        }
        return -1;
    }
};

int main(){


    Solution obj;
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, 35, -1, 13, -1},
        {-1, 15, -1, 2, 14, -1},
        {-1, 11, -1, 7, 6, -1},
        {-1, -1, -1, -1, -1, 36}
    };
    int result = obj.snakesAndLadders(board);
    cout << "Minimum number of rolls to reach the end: " << result << endl; // Output: Minimum number of rolls to reach the end
    return 0;
}