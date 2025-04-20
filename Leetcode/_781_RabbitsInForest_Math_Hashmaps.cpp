#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            
            int count=0;
            unordered_map<int,int>map;
    
            for(int x:answers){
                map[x]++;
            }
            for(auto x:map){
                int groupSize = x.first + 1;
                int rabbits = x.second;
                count += ((rabbits + groupSize - 1) / groupSize) * groupSize;
            }
            return count;
    
        }
    };


    int main(){
        Solution s;
        vector<int>answers={1,1,2};
        cout<<s.numRabbits(answers);
        return 0;
    }