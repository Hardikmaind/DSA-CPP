#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int x = 0, y = 0, cur = 0;
            for (int d : differences) {
                cur += d;
                x = min(x, cur);
                y = max(y, cur);
                if (y - x > upper - lower) {
                    return 0;
                }
            }
            return (upper - lower) - (y - x) + 1;
        }
    };


    int main(){
        Solution obj;
        vector<int>vec={1,2,3,4,5,6,7,8,9,10};
        cout<<obj.numberOfArrays(vec,1,10);
        return 0;
    }