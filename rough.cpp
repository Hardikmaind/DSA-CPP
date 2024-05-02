#include <bits/stdc++.h>
using namespace std;


vector<int> findmax(vector<int>v,int K){
   for(int left=0;left<v.size();left++){
       int right=left+K-1;
       if(right>=v.size()){
           break;
        }
       int max=INT_MIN;
       for(int i=left;i<=right;i++){
           if(v[i]>max){
               max=v[i];
           }
       }
       v[left]=max; 
   }
    vector<int>result(v.begin(),v.begin()+v.size()-K+1);
    return result;
}





vector<int> findMax2(vector<int>& v, int K) {
    deque<int> dq; // Deque to store indices of elements

    vector<int> result; // Vector to store maximum values

    for (int i = 0; i < v.size(); i++) {
        // Remove indices outside the current window from deque's front
        if (!dq.empty() && dq.front() < i - K + 1) {
            dq.pop_front();
        }

        // Remove elements smaller than v[i] from deque's back
        while (!dq.empty() && v[i] > v[dq.back()]) {
            dq.pop_back();
        }

        // Add current index to deque
        dq.push_back(i);

        // Add maximum value for the current window to result
        if (i >= K - 1) {
            result.push_back(v[dq.front()]);
        }
    }

    return result;
}

int main(){
   int N,K;
   K=3;
    N=6;
    vector<int>v={1,3,-1,-3,5,3};
   
    vector<int>result=findmax(v,K);
    for(int x:result){
        cout<<x<<" ";
    }
    cout<<endl;





    vector<int>result2=findMax2(v,K);
    for(int x:result2){
        cout<<x<<" ";
    }
}


