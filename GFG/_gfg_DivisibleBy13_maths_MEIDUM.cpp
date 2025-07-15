#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int rem =0;
        for(char x : s){
            rem = (rem*10+(x-'0'))%13;
        }
        
        return rem==0;
    }
};

int main(){
    Solution ob;
    vector<string> test_cases = {"169", "26", "39", "1001", "1234567890123"};
    
    for ( auto& s : test_cases) {
        cout << s << ": " << (ob.divby13(s) ? "Divisible by 13" : "Not Divisible by 13") << endl;
    }
    
    return 0;
}