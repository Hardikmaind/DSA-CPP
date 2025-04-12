#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        string LongestSubStringWithAtmostKDistinctCharacters(string &s,int k){
            int l=0,r=0,n=s.size();
            unordered_map<char,int>map;
            string str="";
            int maxlen=0;
            int maxStart=0;
            while(r<n){
                map[s[r]]++;
                while(map.size()>k){
                    map[s[l]]--;
                    if(map[s[l]]==0){
                        map.erase(s[l]);
                    }

                    l++;
                }
                if((r-l+1)>maxlen){
                    maxlen=r-l+1;
                    maxStart=l;
                }
                r++;

            }
            cout<<maxlen<<endl;
            return s.substr(maxStart,maxlen);
        }
        int lengthOfLongestSubStringWithAtmostKDistinctCharacters(string &s,int k){
            int l=0,r=0,n=s.size();
            unordered_map<char,int>map;
            string str="";
            int maxlen=0;
            while(r<n){
                map[s[r]]++;
                while(map.size()>k){
                    map[s[l]]--;
                    if(map[s[l]]==0){
                        map.erase(s[l]);
                    }

                    l++;
                }
                maxlen=max(maxlen,r-l+1);                 
                
                r++;

            }
            
            return maxlen;
        }
};

int main(){
    Solution s;
    string str="aaabbccd";
    int k=2;
    // ! Longest substring with atmost k distinct characters
    cout<<s.LongestSubStringWithAtmostKDistinctCharacters(str,k)<<endl;

    // ! Length of longest substring with atmost k distinct characters
    cout<<"Length of longest substring with atmost k distinct characters := ";
    cout<<s.lengthOfLongestSubStringWithAtmostKDistinctCharacters(str,k)<<endl;
    return 0;
}