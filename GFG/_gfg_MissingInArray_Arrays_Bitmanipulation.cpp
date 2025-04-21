#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
      int missingNum(vector<int>& arr) {
          // code here
          int n = arr.size() + 1;
          long long sum = 1LL * n * (n + 1) / 2;
          for (int x : arr) {
              sum -= x;
          }
          return static_cast<int>(sum);     //! here static cast means that we are converting the sum to int. static cast is used to convert a value of one type to another type. and it is diff from dynamic cast like static_cast<int>(sum/2); because static_cast is used to convert the value to the type of the variable.
      }
      
  
  };

class Solution2 {
    public:
      
      
      int missingNum(vector<int>& arr) {
          int n = arr.size() + 1;
          int xor1 = 0, xor2 = 0;
      
          for (int i = 1; i <= n; i++) {
              xor1 ^= i;
          }
          for (int num : arr) {
              xor2 ^= num;
          }
      
          return xor1 ^ xor2;
      }
      
      
  
  };

  

  int main(){
    Solution obj;
    Solution2 obj2;
    vector<int>vec={1,2,3,5};
    cout<<obj.missingNum(vec);
    cout<<endl;
    cout<<obj2.missingNum(vec);
    return 0;
  }