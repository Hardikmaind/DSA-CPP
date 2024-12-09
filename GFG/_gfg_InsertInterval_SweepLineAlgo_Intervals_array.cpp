#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  static bool compare(const vector<int> v1,const vector<int>v2){
      return v1[0]<v2[0];
  }
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        if(intervals.empty()){
            
            return  {newInterval};
        }
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),compare);
        vector<vector<int>> ni;
        
        ni.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ni.back()[1]>=intervals[i][0]){
                ni.back()[1]=max(ni.back()[1],intervals[i][1]);
            }else{
                ni.push_back(intervals[i]);
            }
        }
        return ni;
    }
};



int main(){

    Solution s;
    vector<vector<int>> intervals={{1,3},{4,5},{6,7},{8,10}};
    vector<int> newInterval={5,6};
    vector<vector<int>> res=s.insertInterval(intervals,newInterval);
    for(auto x:res){
        cout<<x[0]<<" "<<x[1]<<endl;
    }
}