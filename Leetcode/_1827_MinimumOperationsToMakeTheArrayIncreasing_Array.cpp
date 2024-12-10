#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& arr) {
        long long int count=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]>=arr[i]){
                count+=arr[i-1]-arr[i]+1;
                arr[i]=arr[i-1]+1;
            }
        }
        return count;

        
    }
};

int main(){
    Solution obj;
    vector<int> arr = {1,1,1};
    cout<<obj.minOperations(arr);
    return 0;
}