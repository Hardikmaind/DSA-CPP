#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

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

        //! we never reduce the maxfreq because see this  contradictory explainatin=>.curr maxwindow(maxlen) with replacement is "5" and maxfreq is "3" image if there is a window in future with maxlength 6. so to be this window valid we need 6-maxfreq<=k. and for this if we had reduced the maxfreq it would be 2 so 6-2<=k would be false. since we have already the found the maxlen as 5. and to find longer maxlen we need window size more than 5 like  6,7,8 or 9 to be valid. and for this to be valid and had we reduced the maxfreq to 2 then 6-2<=k would be false. so we never reduce the maxfreq.so we only increase it in future if there is an element with more freq for example 4. so that 6-4<=k is true. 

        /*Let’s say maxfreq was 4 when the window was valid. Now you move the left pointer and reduce the count of the most frequent character.
        But you don’t update maxfreq.
        Now maybe the new true max frequency is 3, but your maxfreq still says 4.
        So now (r - l + 1 - maxfreq) might be greater than k, and you'll shrink the window.
        This is still safe:
        The window may become slightly smaller than the actual possible window, but you'll find the maximum length in a future iteration when a valid longer window appears.
        You never overestimate a valid window, so the result is always correct. */
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