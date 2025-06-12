#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> res;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=x){
                int absdif=abs(arr[i]-x);
                pq.push({absdif,-arr[i]});          // here minus sign because i want prefer the larger element
            }
        }
        while(k--){
            res.push_back(abs(pq.top().second));
            pq.pop();
        }
        return res;
       
    }
};

class Solution2 {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        vector<int> ans;
        priority_queue<pair<int, int> ,vector<pair<int, int>> , greater<pair<int, int>>>pq;
        for (int i=0; i<arr.size(); i++){
            if(x!= arr[i]){
                int ele= arr[i];
                int putele= abs(ele- x);
                pq.push(make_pair(putele, -arr[i]));
            }
            else{
                continue;
            }
        }
        
        while(k--){
            auto top= pq.top();
            pq.pop();
            int ele= top.second;
            ans.push_back(abs(ele));
             
        }
        return ans;
        
    }
};

int main(){
    Solution obj;
    int n=5, k=3, x=2;
    vector<int> arr = {1, 3, 4, 10, 12};
    vector<int> result = obj.printKClosest(arr, k, x);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;


    Solution2 obj2;
    vector<int> result2 = obj2.printKClosest(arr, k, x);
    for(int i=0; i<result2.size(); i++){
        cout << result2[i] << " ";
    }
    cout << endl;
    return 0;
}