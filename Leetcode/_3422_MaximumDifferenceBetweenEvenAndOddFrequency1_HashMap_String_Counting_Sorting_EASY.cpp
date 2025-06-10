#include <bits/stdc++.h>
using namespace std;    

//! tc is O(nlogn) due to sorting, where n is the number of unique characters in the string.and sc is O(n) for the frequency map.
class Solution {
public:
    int maxDifference(string s) {
         unordered_map<char,int>map;
        for(auto &x:s){
            map[x]++;
        }
        vector<int>arr;
        for(auto &x:map){
            arr.push_back(x.second);
        }
        sort(arr.begin(),arr.end());
        int maxodd=0;
        int mineven=0;
        for(auto &x:arr){
            if(x%2==0){
                mineven=x;
                break;
            }
        }
         for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]%2){
                maxodd=arr[i];
                break;
            }
        }
        return maxodd-mineven;
    }
};

//! tc is O(n), where n is the number of unique characters in the string. and sc is O(n) for the frequency map.
class Solution2 {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        bool foundOdd = false, foundEven = false;

        for (auto &[ch, count] : freq) {
            if (count % 2 == 1) {
                maxOdd = max(maxOdd, count);
                foundOdd = true;
            } else {
                minEven = min(minEven, count);
                foundEven = true;
            }
        }

        if (!foundOdd || !foundEven)
            return 0;  // or some appropriate handling if either doesn't exist

        return maxOdd - minEven;
    }
};


int main(){
    Solution sol;
    cout << sol.maxDifference("aaaaabbc") << endl; // Example usage
    Solution2 sol2;
    cout << sol2.maxDifference("aaaaabbc") << endl; // Example usage
    return 0;
}