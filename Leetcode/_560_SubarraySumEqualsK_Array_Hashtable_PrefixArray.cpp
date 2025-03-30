#include<bits/stdc++.h>
using namespace std;

int subArraySum(vector<int>&arr,int k){
    unordered_map<int,int> map;
    int sum=0;
    int count=0;
    map[0]=1;
    for(int x:arr){
        sum+=x;
        if(map.count(sum-k)>0){
            count+=map[sum-k];
        }
        map[sum]++;
    }
    return count;
}

int main(){
    vector<int> arr = {1, 2, 3};
    int k = 3;
    cout << subArraySum(arr, k) << endl;             // Output: 2
    vector<int>arr2={1, 1, 1};
    cout << subArraySum(arr2, 2) << endl;  // Output: 2
    
}