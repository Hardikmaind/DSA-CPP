#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int compress(vector<char>& arr) {
            int n = arr.size();
            int write = 0; // write pointer
            int read = 0;  // read pointer
            while (read < n) {
                char curr = arr[read];
                int count = 0;
                // Count occurrences of the current character
                while (read < n && arr[read] == curr) {
                    read++;
                    count++;
                }
                // Write the character
                arr[write++] = curr;
                // If count > 1, write digits of the count
                if (count > 1) {
                    string cntStr = to_string(count);
                    for (char c : cntStr) {             //since group more than 10 can be represented by more than one digit, so this is why we are splitting the string into digits
                        arr[write++] = c;
                    }
                }
            }
            printArray(arr);
            return write;
        }
        void printArray(vector<char>& arr) {
            for (char c : arr) {
                cout << c<<" ";
            }
            cout << endl;
        }
    };


    

    int main(){
        Solution s;
        vector<char> arr={'a','a','b','b','c','c','c'};
        cout<<s.compress(arr)<<endl;
    }