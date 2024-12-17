#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Step 1: Count the frequency of each character
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Use a max heap (priority_queue) to keep track of characters
        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({'a' + i, freq[i]});
            }
        }

        string result = "";
        while (!pq.empty()) {
            // Fetch the most frequent (largest lexicographical) character
            auto [ch1, freq1] = pq.top();
            pq.pop();

            int useCount = min(repeatLimit, freq1);  // Use it up to repeatLimit times
            result.append(useCount, ch1);
            freq1 -= useCount;

            if (freq1 > 0) {  // Still some remaining characters
                if (pq.empty()) break;  // No other character to break the sequence

                // Fetch the second-largest character to break the repetition
                auto [ch2, freq2] = pq.top();
                pq.pop();

                result += ch2;  // Add one occurrence of the second character
                freq2--;

                // Push both characters back into the heap if they still have remaining frequency
                if (freq2 > 0) pq.push({ch2, freq2});
                pq.push({ch1, freq1});
            }
        }

        return result;
    }


    //! Method 2: Using a hashmap to store the frequency of each character
     string repeatLimitedString2(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string result;
        int currentCharIndex = 25;  // Start from the largest character
        while (currentCharIndex >= 0) {
            if (freq[currentCharIndex] == 0) {
                currentCharIndex--;
                continue;
            }

            int use = min(freq[currentCharIndex], repeatLimit);
            result.append(use, 'a' + currentCharIndex);
            freq[currentCharIndex] -= use;

            if (freq[currentCharIndex] >
                0) {  // Need to add a smaller character
                int smallerCharIndex = currentCharIndex - 1;
                while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0) {
                    smallerCharIndex--;
                }
                if (smallerCharIndex < 0) {
                    break;
                }
                result.push_back('a' + smallerCharIndex);
                freq[smallerCharIndex]--;
            }
        }

        return result;
    }
};
int main(){
    Solution s;
    string str = "cczazcc";
    int k = 3;
    cout << s.repeatLimitedString(str, k);
    cout<<endl;
    string str2 = "cczazcc";
    int k2 = 3;
    cout << s.repeatLimitedString2(str, k);
    return 0;

}