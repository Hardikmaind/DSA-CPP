#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap;
        for(auto &x:gifts){

            maxHeap.push(x);
        }
        for(int i=0;i<k;i++){

            long long  x=maxHeap.top();
            maxHeap.pop();
            maxHeap.push(ceil((int)sqrt(x)));
        }

        long long  sum=0;
        while(!maxHeap.empty()){
            sum+=maxHeap.top();
            maxHeap.pop();

        }
        return sum;
        
    }

    //! THIS IS APPRAOCH 2 OF THE SAME PROBLEM BY PRIORIT QUEUE WITH DIFFERENT SYNTAX
      long long pickGifts2(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end());
        for (int i=0, x=INT_MAX; i<k && x>1; i++){
            pop_heap(gifts.begin(), gifts.end());
            x=gifts.back();
            gifts.back()=sqrt(gifts.back());
            push_heap(gifts.begin(), gifts.end());
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};


int main(){
    vector<int> gifts={25,64,9,4,100};
    Solution s;
    int k=4;
    cout<<s.pickGifts(gifts,k);
    cout<<s.pickGifts2(gifts,k);
    return 0;
}