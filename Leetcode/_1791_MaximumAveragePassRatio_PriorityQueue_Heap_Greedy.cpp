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

/* 
!Why Distribute Students One-by-One:
Dynamic Gain Calculation: The gain in the ratio after adding one student is not constant. Each time you add a student, the ratio changes. For example, adding a student to a class with a higher pass-to-stren ratio might result in a smaller increase compared to adding a student to a class with a lower ratio.

Greedy Strategy: The goal is to always apply the next student to the class that will benefit the most (i.e., the class that has the highest gain in its pass-to-stren ratio). By using a priority queue (max-heap), you ensure that you’re always picking the class that gives you the highest gain for the next student.

!Why We Can't Add All Extra Students to the Top Class at Once:
If you were to add all extra students to the class at the top of the heap without considering the dynamic changes in the ratio, you might miss an opportunity to improve the ratio for other classes that could benefit more from receiving extra students. This would result in suboptimal distribution and a lower average ratio.

In summary, the loop ensures that the extra students are allocated in a way that maximizes the overall average ratio by always selecting the class that benefits the most from receiving an additional student at each step.*/
        // Assign extra students to maximize the gain greedily
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


    //! Approach 3: Heap + Greedy
     double maxAverageRatio3(vector<vector<int>>& classes, int extraStudents) {

        auto profit = [&](double pass, double total) {
            return (pass + 1)/(total + 1) - pass/total;
        };

        double total = 0;
        priority_queue<pair<double, array<int, 2>>> pq;
        for(int i = 0; i < classes.size(); i++) {
            total += (double)classes[i][0]/classes[i][1];
            pq.push({profit(classes[i][0], classes[i][1]), {classes[i][0], classes[i][1]}});
        }

        while(extraStudents--) {
            auto [pfit, arr] = pq.top(); pq.pop();
            total += pfit;
            pq.push({profit(arr[0]+1, arr[1]+1), {arr[0]+1, arr[1]+1}});
        }
        return total / classes.size();
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
   
   
    vector<vector<int>> classes3= {{1,2},{3,5},{2,2}};
    int extraStudents3 = 2;
    cout << s.maxAverageRatio3(classes3, extraStudents3) << endl;
    
    
    
    
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