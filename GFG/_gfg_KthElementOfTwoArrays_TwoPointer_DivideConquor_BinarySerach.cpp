#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:


  //! this is by the Divide and Conquor method. tc is O(log(min(n,m))) and sc is O(n)
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int p1=0,p2=0;
        vector <int>res;
        while(p1<a.size() && p2<b.size()){
            if(a[p1]<=b[p2]){
                res.push_back(a[p1]);
                
                p1++;
            }else{
                res.push_back(b[p2]);
                
                p2++;
            }
        }
        while(p1<a.size()){
            res.push_back(a[p1]);
            
            p1++;
        }
        while(p2<b.size()){
            res.push_back(b[p2]);
            
            p2++;
        }
        return res[k-1];
        
    }

//! this is by the TWO POINTER METHOD. tc is O(n) and sc is O(1)
    int kthElement2(vector<int>& a, vector<int>& b, int k) {
        int p1 = 0, p2 = 0;

        while (p1 < a.size() && p2 < b.size()) {
            if (p1 + p2 == k - 1) {
                return (a[p1] <= b[p2]) ? a[p1] : b[p2];
            }

            if (a[p1] <= b[p2]) {
                p1++;
            } else {
                p2++;
            }
        }

        // If one array is exhausted
        while (p1 < a.size()) {
            if (p1 + p2 == k - 1) {
                return a[p1];
            }
            p1++;
        }
        while (p2 < b.size()) {
            if (p1 + p2 == k - 1) {
                return b[p2];
            }
            p2++;
        }

        return -1; // Should not reach here
    }

//! this is by the Binary Search method. tc is O(log(min(n,m))) and sc is O(1)
    
int kthElement3( vector<int>& a,  vector<int>& b, int k) {
    // Ensure `a` is the smaller array
    //! THIS IS LIKE RECURSION BUT NOT RECURSION AND BELOW IS BASE CASE. BUT BELOW BASE CASE IS HITTING FIRST. SO NO code  BELOW base case GETS EXECUTED. ALSO IT IS NOT A PROPER RECURSION BECUASE APART FROM BASE CASE, BELOW (below base case) THERE  IS NO FUNCTION CALL TO ITSELF.
    if (a.size() > b.size()) {
        return kthElement3(b, a, k);
    }

    int n = a.size();
    int m = b.size();
    int low = max(0, k - m), high = min(k, n);

    while (low <= high) {
        int i = (low + high) / 2; // Elements from `a`
        int j = k - i;           // Elements from `b`

        // Boundary values
        int aLeft = (i > 0) ? a[i - 1] : INT_MIN;
        int aRight = (i < n) ? a[i] : INT_MAX;
        int bLeft = (j > 0) ? b[j - 1] : INT_MIN;
        int bRight = (j < m) ? b[j] : INT_MAX;

        // Check if partition is valid
        if (aLeft <= bRight && bLeft <= aRight) {
            return max(aLeft, bLeft); // Found the k-th element
        } else if (aLeft > bRight) {
            high = i - 1; // Move left in `a`
        } else {
            low = i + 1; // Move right in `a`
        }
    }

    return -1; // This case won't occur if inputs are valid
}
};
int main(){
    Solution s;
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    cout<<s.kthElement(a,b,k);
    cout<<endl;
    cout<<s.kthElement2(a,b,k);
    cout<<endl;
    cout<<s.kthElement3(a,b,k);
    cout<<endl;
}