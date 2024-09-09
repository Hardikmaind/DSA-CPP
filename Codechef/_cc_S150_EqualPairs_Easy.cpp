#include <bits/stdc++.h>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        unordered_map<int, int> frequencyMap;
        int arraySize;
        cin >> arraySize;
        vector<int> array(arraySize);
        int zeroCount = 0;

        for (int i = 0; i < arraySize; i++) {
            cin >> array[i];
            if (array[i] == 0) {            //in the map ..elements which is 0 is not getting stored
                zeroCount++;            
            } else {
                frequencyMap[array[i]]++;
            }
        }

        int maxFrequency = -1;
        int mostFrequentElement;                                    //here we aare calculating the max freq key. which means most frequent element. which is stored in the Hashmap
        for (const auto& entry : frequencyMap) {
            if (entry.second > maxFrequency) {
                maxFrequency = entry.second;
                mostFrequentElement = entry.first;
            }
        }

        int totalPairs = 0;
        int mostFrequentElementCount = 0;

        for (const auto& entry : frequencyMap) {
            if (entry.first == mostFrequentElement) {
                mostFrequentElementCount = entry.second;                //here we are calculating the count of the most frequent element.
            } else {
                totalPairs += (entry.second * (entry.second - 1)) / 2;          //here we are calculating the pairs of the elements which are not the most frequent element. Also  no pairs are possible for any element if its frequency is less than 2 therefore the formula will add noting to the totalPairs.
            }
        }

        totalPairs += ((mostFrequentElementCount + zeroCount) * (mostFrequentElementCount + zeroCount - 1)) / 2;        //now since we have to replace the zeros with the most frequent element. Therefore we are calculating the pairs of the most frequent element and the zeros. by the formula of nC2.

        if (zeroCount == arraySize) {           //if all the elements are zero then the pairs will be nC2
            cout << zeroCount * (zeroCount - 1) / 2 << endl;
        } else {
            cout << totalPairs << endl;     //else we will print the total pairs.
        }
    }
}

// test cases

// 3
// 5
// 1 2 1 3 3
// 5
// 1 1 2 0 0
// 3
// 0 0 0


// THIS BELOW CODE IS MORE OPTIMISED...SINCE 


// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     int testCases;
//     cin >> testCases;
    
//     while (testCases--) {
//         int arraySize;
//         cin >> arraySize;
        
//         vector<int> array(arraySize);
//         unordered_map<int, int> frequencyMap;
//         int zeroCount = 0;

//         for (int i = 0; i < arraySize; i++) {
//             cin >> array[i];
//             if (array[i] == 0) {
//                 zeroCount++;
//             } else {
//                 frequencyMap[array[i]]++;
//             }
//         }

//         if (zeroCount == arraySize) {
//             // Special case: all zeros
//             cout << (zeroCount * (zeroCount - 1)) / 2 << endl;
//             continue;
//         }

//         int mostFrequentElementCount = 0;
//         int totalPairs = 0;

//         // Compute pairs for elements and track the most frequent element count
//         for (const auto& entry : frequencyMap) {
//             int count = entry.second;
//             if (count > mostFrequentElementCount) {
//                 mostFrequentElementCount = count;
//             }
//             // Add pairs for this element
//             totalPairs += (count * (count - 1)) / 2;
//         }

//         // Add pairs by replacing zeros with the most frequent element
//         totalPairs -= (mostFrequentElementCount * (mostFrequentElementCount - 1)) / 2;
//         mostFrequentElementCount += zeroCount;
//         totalPairs += (mostFrequentElementCount * (mostFrequentElementCount - 1)) / 2;

//         cout << totalPairs << endl;
//     }
// }
