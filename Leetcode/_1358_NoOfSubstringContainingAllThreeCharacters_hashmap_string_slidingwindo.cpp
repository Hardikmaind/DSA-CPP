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
}