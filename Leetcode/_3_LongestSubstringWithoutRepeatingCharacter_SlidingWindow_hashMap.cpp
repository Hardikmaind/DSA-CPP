#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
     int lengthOfLongestSubstring(string &s)
    {
        int set[255] = {0};
        int l = 0, r = 0, len = 0, maxlen = 0;
        while (r < s.size())
        {
            while (set[s[r]] == 1)
            {
                set[s[l]] = 0;
                l++;
            }
            len = r - l + 1;
            set[s[r]] = 1;
            maxlen = max(len, maxlen);
            r++;
        }
        return maxlen;
    }
    //this is a brute force solution 
    int longestSubstring1(string &s){
        int set[255]={0};

        int len=0,maxlen=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(set[s[j]]==1) break;
                len=j-i+1;
                maxlen=max(maxlen,len);
                set[s[j]]=1;
            }
        }
        return maxlen;
        
    }
};

int main()
{
    Solution s;
    string str = "abcabcbb";

    cout << s.lengthOfLongestSubstring(str) << endl;
}