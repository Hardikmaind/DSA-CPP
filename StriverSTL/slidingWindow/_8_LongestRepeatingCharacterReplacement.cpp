#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
//! "AABABBA"
    int longestRepeatingCharacterReplacement(string &s,int k)
    {
        int r = 0;
        int l = 0;
        int maxlen = 0;
        int n = s.size();
        int maxfreq = 0;
        int map[26]={0};
        while (r < n)
        {
            map[s[r]-'A']++;
            maxfreq=max(maxfreq,map[s[r]-'A']);
            if((r-l+1) - maxfreq <=k){                          //! (r-l+1) is the window size and in that window we can only change atmost k , and also it is good if we change the least frequent element. so we subtract (window-maxfreq)     and our this should be less than k to obtain the valid condition
                maxlen=max(maxlen,r-l+1);
            }else{
                map[s[l]-'A']--;
                
                l++;
            }
            r++;
        }
        return maxlen;
    }

    //! below is the brute force solution. tc is O(n^2)
    int longestRepeatingCharacterReplacement2(string &s,int k)
    {

        int maxlen=0;
        int changes=0;
        for(int i=0;i<s.size();i++){
            int map[26]={0};
            int maxfreq=0;
        for(int j=i;j<s.size();j++){
            map[s[j]-'A']++;
            maxfreq = max(maxfreq, map[s[j] - 'A']);
            changes=(j-i+1)-maxfreq;;
            if(changes<=k){
                maxlen=max(maxlen,j-i+1);
            }else{
                break;
            }
        }
       }
       return maxlen;
    }
};
int main()
{
    Solution s;
    int k=2;
    string str="AABABBA";
    cout << s.longestRepeatingCharacterReplacement2(str,k)<<endl;
    cout << s.longestRepeatingCharacterReplacement(str,k)<<endl;
    return 0;
}