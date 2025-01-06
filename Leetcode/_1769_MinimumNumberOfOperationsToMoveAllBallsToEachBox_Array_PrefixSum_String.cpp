#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/solutions/6210124/minimum-number-of-operations-to-move-all-balls-to-each-box

class Solution {
public:
    // ! This is m1. tc is O(n^2) and sc is O(n)
    vector<int> minOperations(string boxes) {
        vector<int> answer(boxes.length());
        for (int currentBox = 0; currentBox < boxes.length(); currentBox++) {
            // If the current box contains a ball, calculate the number of moves
            // for every box.
            if (boxes[currentBox] == '1') {
                for (int newPosition = 0; newPosition < boxes.length();
                     newPosition++) {
                    answer[newPosition] += abs(newPosition - currentBox);
                }
            }
        }
        return answer;
    }
    // ! This is m2. tc is O(n) and sc is O(n)
     vector<int> minOperations2(string boxes) {
        int n = boxes.length();  
        if(n==1)return {0} ; 
        vector<int>suffix(n,0) ; 
        vector<int>prefix(n,0) ; 
        int cnt=0; 
        int temp=0 ;
        for(int i=n-1; i>=0; i--){
            temp+=cnt ; 
            suffix[i]=temp ; 
            if(boxes[i]=='1')cnt++ ; 
        }
        cnt=0; 
        temp=0; 
        for(int i=0; i<n; i++){
            temp+=cnt; 
            prefix[i]=temp ; 
            if(boxes[i]=='1')cnt++ ; 
        }
        vector<int>ans(n); 
        for(int i=0; i<n; i++){
            if(i==0)ans[i]=suffix[i] ;
            else if(i==n-1)ans[i]=prefix[i] ; 
            else{
                ans[i]=prefix[i]+suffix[i]; 
            } 
        }
        return ans; 
    }
};
int main(){
    Solution a;
    vector<int> res = a.minOperations("110");
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    vector<int> res2 = a.minOperations2("110");
    for (int i = 0; i < res2.size(); i++){
        cout << res2[i] << " ";
    }

    return 0;
}