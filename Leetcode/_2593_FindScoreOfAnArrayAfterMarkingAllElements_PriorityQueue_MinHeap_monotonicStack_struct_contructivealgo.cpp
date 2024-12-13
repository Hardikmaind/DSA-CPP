
#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    // Custom struct
    struct Ele {
        int a; // Value from nums
        int i; // Index in nums
        int l; // Left index
        int r; // Right index

        // Constructor for convenience
        //!This is a **member initializer list** in C++ used in a constructor. It allows you to directly initialize member variables of a class or struct when an object is created. This approach is often more efficient than assigning values inside the constructor body, especially for complex types or constants
        Ele(int a, int i, int l, int r) : a(a), i(i), l(l), r(r) {}
    };
    // Custom comparator for priority queue (min-heap based on value `a`)
    struct CompareEle {
        bool operator()(const Ele& t1, const Ele& t2) {
            if (t1.a == t2.a) {
                return t1.i > t2.i; // If values are equal, prioritize smaller index
            }
            return t1.a > t2.a; // Smaller value has higher priority
        }
    };
    long long findScore(vector<int>& nums) {
        priority_queue<Ele, vector<Ele>, CompareEle> pq;

        unordered_set<int> visited;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(Ele(nums[i], i, i == 0 ? -1 : i - 1, i == nums.size() - 1 ? -1 : i + 1));
        }
        long long sum = 0;
        while (!pq.empty()) {
            Ele obj = pq.top();
            pq.pop();
            if (visited.count(obj.i) == 0) {
                sum += obj.a;
                visited.insert(obj.i);
                if (obj.l != -1) visited.insert(obj.l);
                if (obj.r != -1) visited.insert(obj.r);
                }
        }
        return sum;
    }
};
int main(){
    Solution s;
    vector<int> nums = {2,1,3,4,5,2};
    cout << s.findScore(nums) << endl;
    return 0;

}




/*This is a **member initializer list** in C++ used in a constructor. It allows you to directly initialize member variables of a class or struct when an object is created. This approach is often more efficient than assigning values inside the constructor body, especially for complex types or constants.

### Explanation
The syntax:

```cpp
Ele(int a, int i, int l, int r) : a(a), i(i), l(l), r(r) {}
```

### Breakdown
1. **`Ele(int a, int i, int l, int r)`**
   - This is the constructor for the `Ele` struct. It takes four parameters: `a`, `i`, `l`, and `r`.

2. **`: a(a), i(i), l(l), r(r)`**
   - This is the member initializer list. Each member of the struct (`a`, `i`, `l`, `r`) is directly initialized with the corresponding parameter passed to the constructor.

3. **`{}`**
   - This is the body of the constructor. In this case, it is empty because all initialization happens in the initializer list.

### Advantages of Member Initializer Lists
1. **Efficiency:**
   - When using an initializer list, the member variables are initialized in place rather than being default-constructed and then assigned new values in the constructor body. For example:
     ```cpp
     // Less efficient
     Ele(int a, int i, int l, int r) {
         this->a = a;
         this->i = i;
         this->l = l;
         this->r = r;
     }
     ```
     The above code may perform redundant initialization, depending on the types.

2. **Support for `const` and `reference` Members:**
   - If the struct or class contains `const` or reference members, they **must** be initialized in the initializer list because they cannot be assigned values later.

3. **Clarity:**
   - It clearly shows the initialization of each member, making the code easier to understand.

### Example with Explanation

```cpp
struct Ele {
    int a; // Value
    int i; // Index
    int l; // Left neighbor
    int r; // Right neighbor

    // Constructor with member initializer list
    Ele(int a, int i, int l, int r) : a(a), i(i), l(l), r(r) {}
};

int main() {
    Ele e(10, 1, -1, 2); // Creates an Ele object with a=10, i=1, l=-1, r=2
    return 0;
}
```

- In this example, when `Ele e(10, 1, -1, 2)` is executed:
  - The member variables `a`, `i`, `l`, and `r` are directly initialized with the values `10`, `1`, `-1`, and `2` respectively. */