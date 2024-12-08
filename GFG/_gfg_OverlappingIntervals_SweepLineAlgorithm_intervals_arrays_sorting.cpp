#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    static bool compare(const vector<int> &v1,const vector<int> &v2){
        if(v1[0]==v2[0]){
            return v1[1]<v2[1];
        }
        return v1[0]<v2[0];
    }
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        if(arr.empty()){
            return {};          //this returns the default constructor of return type of the function
        }
        sort(arr.begin(),arr.end(),compare);
        vector<vector<int>> vec;
        
        vec.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(vec.back()[1]>=arr[i][0]){
                
                vec.back()[1]=max(vec.back()[1],arr[i][1]);
                
            }else{
                vec.push_back(arr[i]);
            }
        }
        return vec;
    }
};




int main(){

    Solution s;
    vector<vector<int>> intervals = {{1,3},{2,4},{6,8},{9,10}};
    vector<vector<int>> res = s.mergeOverlap(intervals);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }

}