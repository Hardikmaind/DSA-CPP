#include <bits/stdc++.h>
using namespace std;
//use max heap instead of the min heap because 


class Solution {
public:
//! Approach 1: Priority Queue + Greedy

    struct Classes {
        int pass;
        int stren;
        double gain;
        Classes(int p, int s) : pass(p), stren(s) {
            gain = calculateGain(p, s);
        }

        static double calculateGain(int pass, int stren) {
            return double(pass + 1) / (stren + 1) - double(pass) / stren;
        }

        bool operator<(const Classes& other) const {            //this is operator overloading for priority queue to compare the objects and make a max heap
            return gain < other.gain; // Max-Heap
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Classes> pq;

        // Populate the priority queue with initial classes
        for (auto& arr : classes) {
            pq.emplace(arr[0], arr[1]);
        }

        // Assign extra students to maximize the gain
        while (extraStudents > 0) {
            Classes topClass = pq.top();
            pq.pop();

            // Add one student and recalculate the gain
            topClass.pass++;
            topClass.stren++;
            topClass.gain = Classes::calculateGain(topClass.pass, topClass.stren);

            pq.push(topClass);
            extraStudents--;
        }

        // Calculate the final average ratio
        double maxAvg = 0;
        while (!pq.empty()) {
            Classes topClass = pq.top();
            pq.pop();
            maxAvg += double(topClass.pass) / topClass.stren;
        }

        return maxAvg / classes.size();
    }

    //! Approach 2: Heap + Greedy



/*In C++, you cannot directly use a standalone function (or a static method in this case) as the comparator for a std::priority_queue because the comparator must be a callable object, such as a function object (functor), lambda function, or function pointer. Here's why:

Why Compare Struct is Needed
Priority Queue Requirements:

The comparator for std::priority_queue must be a callable type that can be invoked as bool operator()(const T& a, const T& b) where T is the type stored in the priority queue.
std::priority_queue requires the comparator as a type, not as an instance. This is why functors (like the Compare struct) or lambdas are typically used.
Can't Pass operator Directly:

The syntax you proposed:
cpp
Copy code
priority_queue<pair<int, int>, vector<pair<int, int>>, operator>
is invalid because operator() cannot be used as a type. It's a specific overload of a callable type and does not define a general callable type that can be passed as a template argument.
Why Struct Works:

A struct like Compare is a functor, which defines an operator() method. This makes it a callable type, and its type can be passed as a comparator to std::priority_queue.
Alternatives to the Compare Struct
*/

     struct Compare {
        bool operator()(const pair<int, int>& c1, const pair<int, int>& c2) {
            double gain1 = double(c1.first + 1) / (c1.second + 1) - double(c1.first) / c1.second;
            double gain2 = double(c2.first + 1) / (c2.second + 1) - double(c2.first) / c2.second;
            return gain1 < gain2; // Max-Heap: prioritize larger gain
        }
    };

    double maxAverageRatio2(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        // Populate the priority queue
        for (auto& cls : classes) {
            pq.push({cls[0], cls[1]});
        }

        // Apply extra students greedily
        while (extraStudents > 0) {
            auto [pass, stren] = pq.top();
            pq.pop();
            pq.push({pass + 1, stren + 1});
            extraStudents--;
        }

        // Calculate the final average ratio
        double maxAvg = 0;
        while (!pq.empty()) {
            auto [pass, stren] = pq.top();
            pq.pop();
            maxAvg += double(pass) / stren;
        }

        return maxAvg / classes.size();
    }
};

int main(){
    Solution s;
    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    int extraStudents = 2;
    cout << s.maxAverageRatio(classes, extraStudents) << endl;
    
    vector<vector<int>> classes2 = {{1,2},{3,5},{2,2}};
    int extraStudents2 = 2;
    cout << s.maxAverageRatio2(classes2, extraStudents2) << endl;
    
    
    
    
    return 0;

}





//? THIS IS THE OLD CODE THAT I WROTE. IT DOESNT GIVE PRECISION TO 5 DECIMAL PLACES. SO, IT FAILS FOR SOME TEST CASES. HERE I HAVE GIVE PRIORITY TO WHOSE RATIO IS LESS
/*class Solution {
public:
    struct Classes{
        int pass;
        int stren;
        double ratio;
        int i;
        Classes(int p, int s, double r, int i): pass(p), stren(s), ratio(r), i(i) {}
    };
    
    static bool compareRatio(const Classes& c1, const Classes& c2) {
        return c1.ratio > c2.ratio;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Classes, vector<Classes>, decltype(&compareRatio)> pq(compareRatio);
        
        // Populate the priority queue
        int i = 0;
        for (auto &arr : classes) {
            pq.push(Classes{arr[0], arr[1], double(arr[0]) / ((arr[1]* 1e5) / 1e5), i});
            i++;
        }

        // Apply extra students greedily
        while (extraStudents > 0) {
            Classes topClass = pq.top();
            pq.pop();
            topClass.pass++;
            topClass.stren++;
            topClass.ratio = double(topClass.pass) / topClass.stren;
            pq.push(topClass);
            extraStudents--;
        }

        // Calculate the final average ratio
        double maxAvg = 0;
        while (!pq.empty()) {
            Classes topClass = pq.top();
            pq.pop();
            maxAvg += topClass.ratio;
        }

       return round(maxAvg / classes.size() * 1e5) / 1e5;
    }
};



Case 1
Case 2
Input
classes =
[[2,4],[3,9],[4,5],[2,10]]
extraStudents =
4
Output
0.52115
Expected
0.53485
 */