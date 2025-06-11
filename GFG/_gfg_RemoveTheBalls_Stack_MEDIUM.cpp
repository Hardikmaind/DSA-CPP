#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

  //! in the below code i have pushed the color and radius in a stack. i.e the values
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int,int>>st;
        for(int i=0;i<color.size();i++){
            if(!st.empty() && color[i]==st.top().first && radius[i]==st.top().second){
                st.pop();
            }else{
                
            st.push({color[i],radius[i]});
            }
        }
        return st.size();
        
    }
};

//! in the below code i have pushed the index of the color and radius in a stack.
class Solution2{
    public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<int> st;
    for (int i = 0; i < N; i++) {
        if (!st.empty() &&
            color[i] == color[st.top()] &&
            radius[i] == radius[st.top()]) {
            st.pop();
        } else {
            st.push(i);
        }
    }
    return st.size();
    }
};


int main(){
    Solution sol;
    vector<int> color = {1, 2, 1, 2, 1};
    vector<int> radius = {1, 2, 1, 2, 1};
    cout << sol.findLength(color, radius) << endl; // Example usage


    Solution2 sol2;
    vector<int> color2 = {1, 2, 1, 2, 1};
    vector<int> radius2 = {1, 2, 1, 2, 1};
    cout << sol2.finLength(5, color2, radius2) << endl; // Example usage
    
    return 0;
}