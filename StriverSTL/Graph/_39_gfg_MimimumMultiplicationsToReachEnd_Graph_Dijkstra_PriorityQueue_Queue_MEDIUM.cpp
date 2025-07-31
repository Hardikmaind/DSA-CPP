#include <bits\stdc++.h>
using namespace std;


// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
         if (start == end) return 0;

         //! we can also use the normal queue since the steps are increasing by 1 only. but if used priority queue , we need to take care to sort the item via steps,then products
        //* in normal queue we can use like queue<pair<prod,steps>>q; since we are going iteratively multiplying to all the elements of an array

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,start});     // {steps, value}
        vector<int>steps(100000,1e9);
        const int mod=100000;
        steps[start] = 0;

        while(!pq.empty()){
            auto it=pq.top();
            int step=it.first;
            int prod=it.second;

            pq.pop();
            for(auto &x:arr){
                int product=(prod*x)%mod;
                
                
                if(step+1<steps[product]){
                    steps[product]=step+1;
                    if (product == end) {
                        return step + 1;
                    }
                    pq.push({step+1,product});
                    
                }
                
            }
        }
        return -1;
        
        
    }
};


class Solution2 {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        const int mod = 100000;

        // Edge case: start == end
        if (start == end) return 0;

        // Priority queue sorted by steps
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, start});     // {steps, value}

        vector<int> steps(mod, 1e9);
        steps[start] = 0;

        while (!pq.empty()) {
            auto [step, prod] = pq.top();
            pq.pop();

            for (int x : arr) {
                int product = (prod * x) % mod;

                if (step + 1 < steps[product]) {
                    steps[product] = step + 1;

                    if (product == end) {
                        return step + 1;
                    }

                    pq.push({step + 1, product});  // correct order
                }
            }
        }

        return -1;
    }
};


int main(){
    Solution s1;
    vector<int>arr={2,5,7};
    int start=3,end=30;
    auto res=s1.minimumMultiplications(arr,start,end);
    cout<<res<<endl;
    return 0;
}