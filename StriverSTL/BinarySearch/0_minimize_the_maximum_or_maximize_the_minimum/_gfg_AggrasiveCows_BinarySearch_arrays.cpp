#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    static bool checkValid(int &mid,vector<int>&stalls,int &k){
        int  lastplaced=stalls[0];
        int cowplaced=1;
        for(int i=0;i<stalls.size();i++){
            if(stalls[i]-lastplaced>=mid){
                lastplaced=stalls[i];
                cowplaced++;
                
                if(cowplaced>=k)return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());          //need to sort the stalls to apply binary search
        // Write your code here
        int l=1;        //here 1 because minimum distance between two stalls can be 1
        int r=stalls.back()-stalls[0];      //here stalls.back()-stalls[0] because maximum distance between two stalls can be the distance between maxelement and minelement
        int res=0;      //this will store the maximum distance between two stalls which is valid.intially it is 0. i.e minimum distance between two stalls. and we need to find the maximum distance between two stalls which is valid
        while(l<=r){
            int mid=l+(r-l)/2;
            if(checkValid(mid,stalls,k)){
           //   res=max(mid,res);     // this is also valid, but this is unnecessary since array is sorted and we are binary seraching and l=mid+1..so here basically we are going towards the larger mid only. therefore no need to do the max operation.
                res=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return res;
        
    }
};


int main(){
    Solution obj;
    vector<int> stalls={1,2,4,8,9};
    int k=3;
    cout<<obj.aggressiveCows(stalls,k);
    cout<<endl;
    vector<int> stalls2={6,7,9,11,13,15};
    int k2=4;
    cout<<obj.aggressiveCows(stalls2,k2);
}