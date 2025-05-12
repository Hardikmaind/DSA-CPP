#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkEven(int n){
        if(n%2){
            return false;
        }
        return true;
    }
    bool check(int n,unordered_set<int>&set){
        if(n<100 || n>999){
            return false;
        }
        if( !checkEven(n%10)){
           return false; 
        }
        while(n>0){
            int rem=n%10;
            if(!set.count(rem)){
                return false;
            }
            n/=10;
        }
        return true;

    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>res;
        unordered_set<int>set;
        for(auto x:digits){
            set.insert(x);
        }


        for(int i=100;i<1000;i++){
            if(check(i,set)){
                res.push_back(i);
            }
        }



        sort(res.begin(),res.end());
        return res;

    }
};

//! RECURSION AND BACKTRACKING. TC IS O(10^3) AND SC IS O(1)
class Solution2 {
public:
    void solve(int cur,int k,vector<int> &freq,vector<int> &res){
        if(k==0){
            if(cur%2==0)
                res.push_back(cur);
            return;
        }
        cur=cur*10;
        for(int i=0;i<=9;i++){
            if(cur==0 && i==0)
                continue;
            if(freq[i]>0){
                freq[i]--;
                solve(cur+i,k-1,freq,res);
                freq[i]++;
            }
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
       vector<int> res;
       vector<int> freq(10,0);
       for(auto d:digits)
        freq[d]++; 
        solve(0,3,freq,res);
        return res;
    }
};


//! USING HASHMAP. TC IS o(n) AND SC IS O(N) for storing the frequency of digits
class Solution3 {
public:
    bool isValid(int num, unordered_map<int, int>& freq) {
        unordered_map<int, int> used;
        int original = num;

        // Extract digits and count them
        for (int i = 0; i < 3; ++i) {
            int digit = num % 10;
            used[digit]++;
            num /= 10;
        }

        // Check if each digit used is available in freq
        for (auto& [digit, count] : used) {
            if (freq[digit] < count) {
                return false;
            }
        }

        return true;
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
        unordered_map<int, int> freq;

        // Count digit frequencies
        for (int d : digits) {
            freq[d]++;
        }

        // Check all 3-digit even numbers
        for (int num = 100; num <= 999; ++num) {
            if (num % 2 == 0 && isValid(num, freq)) {
                res.push_back(num);
            }
        }

        return res;
    }
};

//! TC is O(n^3) and sc is O(1)
class Solution4 {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;

        int n = digits.size();
        // Try all combinations of 3 digits
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    if(i == j || j == k || i == k) continue; // all indices must be different
                    int a = digits[i], b = digits[j], c = digits[k];
                    if(a == 0) continue; // leading zero not allowed
                    if(c % 2 != 0) continue; // last digit must be even
                    int num = a * 100 + b * 10 + c;
                    res.push_back(num);
                }
            }
        }

        // remove duplicates and sort
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> digits = {2, 1, 3, 0};
    vector<int> result = sol.findEvenNumbers(digits);
    
    cout << "Even numbers: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}   