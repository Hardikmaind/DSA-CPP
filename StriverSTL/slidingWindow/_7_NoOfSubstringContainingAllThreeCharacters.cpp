#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //! this is the bruteforce solution
    int noOfSubstrinsContainingAllThreeCharacters(string &s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int map[3] = {0};
            for (int j = i; j < s.size(); j++)
            {
                map[s[j] - 'a'] = 1;
                if ((map[0] + map[1] + map[2]) == 3)
                {
                    count++;
                }
            }
        }
        return count;
    }

    //! this below code is also the brute force but it is more optmised. because of the below opitmization step
    int noOfSubstrinsContainingAllThreeCharacters2(string &s)
    {
        int count = 0;
        int n = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            int map[3] = {0};
            for (int j = i; j < s.size(); j++)
            {
                map[s[j] - 'a'] = 1;
                if ((map[0] + map[1] + map[2]) == 3)
                {
                    count = count + n - j; //! this is the more optimization step. here if the map are fulled, then further substring are also the valid, therefore we are directly adding the further substrings into the count.
                    break;
                }
            }
        }
        return count;
    }

    //! this below code uses the sliding window , and is more optimised compared to the above code
    int noOfSubstrinsContainingAllThreeCharacters3(string &s)
    {
        int count=0,l=0,r=0,n=s.size();
        int map[3] = {0};
        while(r<n){
            map[s[r]-'a']++;
            while(map[0] && map[1] && map[2]){
                count+=n-r;
                map[s[l]-'a']--;
                l++;
            }
                r++;
        }
        return count;
    }
    int noOfSubstrinsContainingAllThreeCharacters4(string s) {
        vector<int> count(3, 0);
        int l = 0, r = 0, n = s.size(), subs = 0;
        while (r < n) {
            count[s[r] - 'a'] += 1;
            while (count[0] >= 1 && count[1] >= 1 && count[2] >= 1) {
                subs += (n - r);
                count[s[l] - 'a'] -= 1;
                l++;
            }

            r++;
        }

        return subs;
    }
};
class Solution2{
    public:

    //tc is O(n) and sc is O(1) //! THIS IS EXPLAINED BY STRIVER
        int numberOfSubstrings(string s) {
            int len = s.length();
            // Track last position of a, b, c
            vector<int> lastPos = {-1, -1, -1};
            int total = 0;
    
            for (int pos = 0; pos < len; pos++) {
                // Update last position of current character
                lastPos[s[pos] - 'a'] = pos;
    
                // Add count of valid substrings ending at current position
                // If any character is missing, min will be -1
                // Else min gives leftmost required character position
                total += 1 + min({lastPos[0], lastPos[1], lastPos[2]});
            }
            // printarr(lastPos);
    
            return total;
        }
        void printarr(vector<int> arr){
            cout<<"this is the last position of a,b,c : ";
            for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    };
int main()
{
    Solution s;
    string str = "bbacba";
    //!brute force tc is O(n^3) sc is O(1)
    cout << s.noOfSubstrinsContainingAllThreeCharacters(str)<<endl;
    //! tc is O(n^2) sc is O(1)
    cout << s.noOfSubstrinsContainingAllThreeCharacters2(str)<<endl;

    //! tc is O(n) and sc is O(1). sliding window approach
    cout << s.noOfSubstrinsContainingAllThreeCharacters3(str)<<endl;

    //! tc is O(n) and sc is O(1)..sliding window approach
    cout << s.noOfSubstrinsContainingAllThreeCharacters4(str)<<endl;



    Solution2 s2;
    string str2="abcab";
 
    // ! Approach 2: Last Position Tracking
    cout<<s2.numberOfSubstrings(str2)<<endl;
}




/*Approach 2: Last Position Tracking
Intuition
Instead of thinking in terms of a sliding window, we can take a different perspective: for each position in the string, how many valid substrings end at this position? The key observation is that a substring is valid if it contains at least one occurrence of each required character (a, b, and c). However, instead of tracking exact counts, we only care about where the most recent occurrence of each character is.

Let's use the string "abcab" as an example. When we reach position 4 (the last 'b'), we need to include at least one 'a' and one 'c' to form valid substrings ending at this 'b'. Looking backward, we find the last 'a' at position 3 and the last 'c' at position 2. To create a valid substring, we must include everything from the leftmost required character up to our current position.

This reveals an important pattern. At every position, we determine the leftmost occurrence among the last seen positions of 'a', 'b', and 'c'. The number of valid substrings ending at this position is simply the number of possible starting points, which range from the beginning of the string up to this leftmost position.

In our "abcab" example, at position 4:

The last 'a' appears at position 3.
The last 'b' is at our current position 4.
The last 'c' appears at position 2.
Since 'c' appears leftmost at position 2, any substring starting at positions 0, 1, or 2 and ending at position 4 will be valid. This gives us three valid substrings at this position!

This leads to a simple counting method: at each position, we add 1 plus the minimum of the last positions of 'a', 'b', and 'c'. We add 1 because if the minimum position is k, we can start our substring at any position from 0 to k, giving us k+1 possible starting points.

To handle cases where a character hasn't appeared yet, we initialize its last position as -1. When calculating the minimum of the last positions, finding a -1 tells us we don't have all the required characters yet, so we won't count any substrings at that position.

For a more comprehensive understanding of the sliding window technique, check out the Sliding Window Explore Card 🔗. This resource provides an in-depth look at the sliding window approach, explaining its key concepts and applications with a variety of problems to solidify understanding of the pattern.

Algorithm
Initialize variables:
len to store the length of the input string.
total to store the count of valid substrings.
Create an integer array lastPos of size 3 with all values set to -1 to track the most recent positions of characters a, b, and c.
For each position pos from 0 to len:
Update the last position of the current character in the lastPos array.
Find the minimum position among the last positions of a, b, and c.
If all characters are present, the minimum gives the leftmost required character position.
Add 1 plus this minimum position to the total count (accounting for 0-based indexing).
Return the total count of valid substrings.
The slideshow below demonstrates the algorithm in action:

Current

Implementation

class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        // Track last position of a, b, c
        vector<int> lastPos = {-1, -1, -1};
        int total = 0;

        for (int pos = 0; pos < len; pos++) {
            // Update last position of current character
            lastPos[s[pos] - 'a'] = pos;

            // Add count of valid substrings ending at current position
            // If any character is missing, min will be -1
            // Else min gives leftmost required character position
            total += 1 + min({lastPos[0], lastPos[1], lastPos[2]});
        }

        return total;
    }
};

Complexity Analysis
Let n be the length of the input string s.

Time complexity: O(n)

The algorithm processes each character in the string exactly once using a single loop that runs n times. Each iteration performs a constant amount of work, including updating the lastPos array and computing the minimum of three values. Thus, the overall time complexity remains linear, i.e., O(n).

Space complexity: O(1)

The algorithm maintains a fixed-size array lastPos of length 3 to track the last seen positions of characters a, b, and c. Since this array does not grow with the input size, the space usage is constant, i.e., O(1). */