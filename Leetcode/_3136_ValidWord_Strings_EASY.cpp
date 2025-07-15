#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        bool has_vowel = false;
        bool has_consonant = false;
        for (auto c : word) {
            if (isalpha(c)) {
                c = tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            } else if (!isdigit(c)) {
                return false;
            }
        }
        return has_vowel && has_consonant;
    }
};


int main() {
    Solution solution;
    vector<string> words = {"hello", "world", "123", "aeiou", "bcd", "a1b2c3"};
    for (const auto& word : words) {
        cout << word << ": " << (solution.isValid(word) ? "Valid" : "Invalid") << endl;
    }
    return 0;
}