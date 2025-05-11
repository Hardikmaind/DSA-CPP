#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        for(auto&x:arr){
            if(!(x%2)){
                count=0;
            }
            else if(x%2){
                count++;
            }
            if(count==3){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution obj;
    vector<int>arr={2,6,4,1};
    cout<<boolalpha<<obj.threeConsecutiveOdds(arr)<<endl;
    return 0;
}