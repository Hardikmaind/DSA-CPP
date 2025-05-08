#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int findMissing(vector<int> &arr) {
          // code here
         int n = arr.size();
    
          // If exactly one element is missing, then we can find
          // difference of arithmetic progression using following
          // formula.
          int diff = (arr[1] - arr[0] == arr[n-1] - arr[n-2]) ? arr[1] - arr[0] : 
                ((arr[1] - arr[0] == (arr[n-1] - arr[0])/n) ? arr[1] - arr[0] : 
                 arr[n-1] - arr[n-2]);
          
          if(diff == 0)
              return arr[0];
          
            int lo = 0, hi = n - 1;
        
          while (lo <= hi) {     
                int mid = (lo + hi) / 2;
            
              // if mid == (nth position of element in AP)-1
              // the missing element will exist in right half 
              if ((arr[mid] - arr[0]) / diff == mid)
                  lo = mid + 1;
                
                // the missing element will exist in left half
              else
                  hi = mid - 1;
          }
        
          // after breaking out of binary search loop the missing element
            // will exist between high and low
          return arr[hi] + diff;
      }
  };

  int main(){
    Solution obj;  
    vector<int> arr = {2, 4, 6, 8, 10, 14};
    int missingElement = obj.findMissing(arr);
    cout << "Missing element: " << missingElement << endl;
    return 0;
  }