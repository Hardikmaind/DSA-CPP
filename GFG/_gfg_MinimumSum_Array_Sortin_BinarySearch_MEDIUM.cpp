#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
         // store in max heap max element first
       priority_queue<int> pq;
       for (auto it:arr){
           pq.push(it);
       }
       
       string ans="";
       int carry=0;
       
       // every time pop two elements and add them and push in string
       while(!pq.empty()){
           int value1=pq.top();
           pq.pop();
           int value2=0;
           if(!pq.empty()){
               value2=pq.top();
               pq.pop();
           }
           
           int sum=value1+value2+carry;
           ans.push_back((sum%10)+'0');
           carry=sum/10;
           
       }
       
       // if there is any carry add that to string
       if(carry>0){
           ans.push_back(carry+'0');
       }
       
       // if zeros at the end remove them
       while(ans[ans.size()-1]=='0'){
           ans.pop_back();
       }
       
       // reverse array
       int s=0,e=ans.size()-1;
       while(s<e){
           swap(ans[s++],ans[e--]);
       }
       
       return ans;
    }
};

int main(){
    Solution solution;
    vector<int> arr = {1, 2, 3, 4, 5}; // Example input
    string result = solution.minSum(arr);
    cout << "The minimum sum array is: " << result << endl;
    return 0;
}