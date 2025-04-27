#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      /*You are required to complete below function */
      string multiplyStrings(string& s1, string& s2) {
          // Your code here
           bool isNegative = false;
          if (s1[0] == '-') {
              isNegative = !isNegative;
              s1 = s1.substr(1);
          }
          if (s2[0] == '-') {
              isNegative = !isNegative;
              s2 = s2.substr(1);
          }
          
          // Remove leading zeros
          while (s1.size() > 1 && s1[0] == '0') s1.erase(0, 1);
          while (s2.size() > 1 && s2[0] == '0') s2.erase(0, 1);
      
          if (s1 == "0" || s2 == "0")
              return "0";
      
          int n = s1.size(), m = s2.size();
          vector<int> result(n + m, 0);
      
          // Multiply each digit
          for (int i = n - 1; i >= 0; --i) {
              for (int j = m - 1; j >= 0; --j) {
                  int mul = (s1[i] - '0') * (s2[j] - '0');
                  int sum = mul + result[i + j + 1];
      
                  result[i + j + 1] = sum % 10;
                  result[i + j] += sum / 10;
              }
          }
      
          // Build result string
          string ans = "";
          int i = 0;
          while (i < result.size() && result[i] == 0) i++; // Skip leading zeros
      
          for (; i < result.size(); ++i)
              ans.push_back(result[i] + '0');
      
          if (isNegative)
              ans = "-" + ans;
              
          return ans;
      }
  };


  int main(){
    Solution obj;
    string s1 = "-123456";
    string s2 = "987654";

    cout << obj.multiplyStrings(s1, s2) << endl; 
    return 0;
  }