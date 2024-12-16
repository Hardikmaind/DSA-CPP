#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//? Approach 1: Using Pointers
 //! Time complexity: O(k*n) where n is the size of the input vector
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        while (k > 0) {
            auto min_it = std::min_element(nums.begin(), nums.end());           //min element returns the pointer to the min_element

            *min_it *= multiplier;

            k--;
        }

        return nums;
    }
    
    //! THIS IS APPIROACH-2 WITH THE HELP OF THE PRIORITY QUEUE. TC: O(nlogn)
      vector<int> getFinalState2(vector<int>& nums, int k, int multiplier) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;        //min heap
        int i=0;
        for(auto &x:nums){
            minHeap.push({x,i});
            i++;
        }
        while(k>0){
            auto pair=minHeap.top();
            int newnum=pair.first*multiplier;
            minHeap.pop();
            minHeap.push({newnum,pair.second});
            k--;
        }
         i=nums.size()-1;
        while(i>=0){
            auto pair=minHeap.top();
            nums[pair.second]=pair.first;
            minHeap.pop();
            i--;
        }

        return nums;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,1,3,5,6};
    int k = 5;
    int multiplier = 2;
    vector<int> res = s.getFinalState(nums, k, multiplier);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout<<endl;
    vector<int> nums2 = {2,1,3,5,6};
    int k2 = 5;
    int multiplier2 = 2;
    vector<int> res2 = s.getFinalState2(nums2, k2, multiplier2);
    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i] << " ";
    }
}


/*To compare \( O(n \log n) \) vs \( O(k \cdot n) \), we need to consider the relationship between \( k \) and \( \log n \). Here's the breakdown:

1. **When \( k \) is constant**:  
   - \( O(k \cdot n) \) simplifies to \( O(n) \) because constant factors are ignored in Big-O notation.
   - In this case, \( O(n) \) (or \( O(k \cdot n) \)) is better than \( O(n \log n) \) as \( n \log n \) grows faster for large \( n \).

2. **When \( k = \log n \)**:  
   - \( O(k \cdot n) = O(n \cdot \log n) \), which is equivalent to \( O(n \log n) \).  
   - Both have the same time complexity.

3. **When \( k > \log n \)**:  
   - \( O(k \cdot n) \) grows faster than \( O(n \log n) \), so \( O(n \log n) \) is better in this case.

4. **When \( k < \log n \)**:  
   - \( O(k \cdot n) \) grows slower than \( O(n \log n) \), so \( O(k \cdot n) \) is better in this case.

### Practical Considerations:
- For most sorting algorithms (e.g., merge sort, quicksort), the time complexity is \( O(n \log n) \).  
- \( O(k \cdot n) \) may appear in scenarios like searching in \( k \)-limited buckets or performing limited passes over data.

Ultimately, the better complexity depends on the relationship between \( k \) and \( \log n \) in your specific problem context.*/