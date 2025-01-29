#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
   double power(double b, int e) {
        // code here
        double result = 1.0;
        long exp = e; 

        if (exp < 0) {
            exp = -exp;  
            b = 1.0 / b;  
        }

        while (exp > 0) {
            if (exp % 2 == 1) {  
                result *= b;
            }
            b *= b;
            exp /= 2; 
        }

        return result;
    }
};

int main(){
    Solution s;
    cout<<s.power(2, 3)<<endl;
    
}