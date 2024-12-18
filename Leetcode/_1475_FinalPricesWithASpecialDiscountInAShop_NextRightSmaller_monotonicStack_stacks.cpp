#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // this is the next smaller int problem,we can do this with the help of
        // the monotonic stack
        stack<int> st;
        vector<int> NextSmallerRightInt(prices.size());
        for (int i = prices.size() - 1; i >= 0; i--) {
            while (!st.empty() && prices[i] < prices[st.top()]) {
                st.pop();
            }
            NextSmallerRightInt[i] = st.empty() ? -1 : prices[st.top()];
            st.push(i);
        }
        int i = 0;
        for (auto& x : prices) {
            if (NextSmallerRightInt[i] == -1) {

                i++;
                continue;
            } else {

                x -= NextSmallerRightInt[i];
                i++;
            }
        }
        return prices;
    }
};

int main(){
    Solution s;
    vector<int> prices = {8,4,6,2,3};
    vector<int> res = s.finalPrices(prices);
    for(auto x: res){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}