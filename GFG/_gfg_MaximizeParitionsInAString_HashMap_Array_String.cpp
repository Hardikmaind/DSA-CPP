#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
        int maxPartitions(string &s){
            unordered_map<char,int>lastindex;
            int i=0;
            for(char x:s){
                lastindex[x]=i;
                i++;
            }
            i=0;
            int partitions=0,maxIndex=0;
            
            for(auto x:s){
                maxIndex=max(maxIndex,lastindex[x]);
                if(maxIndex==i){
                    partitions++;
                }
                i++;
            }
            return partitions;


        }

};
int main(){
    Solution obj;
    string s = "ababcbacadefegdehijhklij";
    cout << obj.maxPartitions(s) << endl; // Output: 4
    return 0;

}