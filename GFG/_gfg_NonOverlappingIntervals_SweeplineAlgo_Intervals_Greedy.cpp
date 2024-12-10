#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

   //!   Sorting by end time is the key to implementing a greedy algorithm that ensures the maximum number of non-overlapping intervals can be included. 
  //below Sorting is done by the endtimes. that is why i have used a[1]. if to sort by start times then use a[0]
    static bool compare (const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    }

    //tc is O(nlogn) because of the sorting. and SC is O(n) becasue of the extra res vector we have used. we can reduce the space complexity of the algo
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        if(intervals.empty()){
            return {};
        }
        vector<vector<int>>res;
        sort(intervals.begin(),intervals.end(),compare);
        res.push_back(intervals[0]);
        
        int count=0;
        for(int i=1;i<intervals.size();i++){
            if(res.back()[1]>intervals[i][0]){
                count++;
            }else{
                res.push_back(intervals[i]);
                // res.pop_back();
            }
        }
        return count;
    }


    //TC is O(nlogn) SC is O(1). no extra space is used above method
    int minRemoval2(vector<vector<int>> &intervals) {
        // code here
        if(intervals.empty()){
            return {};
        }
        sort(intervals.begin(),intervals.end(),compare);
        auto prev=intervals[0];                 //here prev is the int[]arr
        int count=0;
        for(int i=1;i<intervals.size();i++){
            if(prev[1]>intervals[i][0]){
                count++;
            }else{
                prev=intervals[i];
            }
        }
        return count;
    }
};




int main(){
    Solution s;
    vector<vector<int>> v={{1,2},{2,3},{3,4},{1,3}};

    int res=s.minRemoval(v);
    cout<<res<<endl;
    cout<<"Second Approach=>"<<"\n";

    cout<<s.minRemoval2(v)<<"\n";
}