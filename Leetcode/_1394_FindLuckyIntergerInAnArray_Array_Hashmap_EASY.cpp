#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int map[501]={0};
        for(auto &x:arr){
            map[x]++;

        }
        int maxlucky=-1;
        for(auto &x:arr){
            if(map[x]==x){
                maxlucky=max(x,maxlucky);
            }
        }
        return maxlucky;
    }
};
int main(){
    Solution obj;
    vector<int> arr = {2, 2, 3, 4};
    cout << "Lucky Integer: " << obj.findLucky(arr) << endl; // Output: 2
    return 0;
}