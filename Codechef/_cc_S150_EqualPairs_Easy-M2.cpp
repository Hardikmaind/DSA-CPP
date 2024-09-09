#include <bits/stdc++.h>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        int arraySize;
        cin >> arraySize;
        
        vector<int> array(arraySize);
        unordered_map<int, int> frequencyMap;
        int zeroCount = 0;

        for (int i = 0; i < arraySize; i++) {          
            cin >> array[i];
            if (array[i] == 0) {         //here in this loop i have taken the zero count. those elements which are zero are note added into the map
                zeroCount++;
            } else {
                frequencyMap[array[i]]++;       //added only those element which are note zero
            }
        }

        if (zeroCount == arraySize) {           //if all elements are zero then print the pairs directly with formula nC2
            // Special case: all zeros
            cout << (zeroCount * (zeroCount - 1)) / 2 << endl;
            continue;
        }

        int mostFrequentElementCount = 0;                           
        int totalPairs = 0;

        // Compute pairs for elements and track the most frequent element count
        for (const auto& entry : frequencyMap) {               
            int count = entry.second;
            if (count > mostFrequentElementCount) {     
                mostFrequentElementCount = count;       //here i have calculated the the most frequent element count
            }
            // Add pairs for this element
            totalPairs += (count * (count - 1)) / 2;         //here in this i have calulated the pairs for the elements which are not zero
        }

        // Add pairs by replacing zeros with the most frequent element
        totalPairs -= (mostFrequentElementCount * (mostFrequentElementCount - 1)) / 2;                //subtracted the pairs of most frequent element. since we will be also converting the zero into  the most freq element
        mostFrequentElementCount += zeroCount;              //added the zero count to the most frequent element count
        totalPairs += (mostFrequentElementCount * (mostFrequentElementCount - 1)) / 2;          //and then calculated the pairs for the most frequent element. since we will be also converting the zero into  the most freq element

        cout << totalPairs << endl;
    }
}
