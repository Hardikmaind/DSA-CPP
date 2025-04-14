#include <bits/stdc++.h>
using namespace std;



class Solution {
    public:
        int findClosest(int x, int y, int z) {
            if (abs(z - y) == abs(z - x)) {
                return 0;
            } else if (abs(z - x) == std::min(abs(z - y), abs(z - x))) {
                return 1;
            } else{
                return 2;
            }
            
        }
    };

    
    int main(){
        Solution obj;
        cout<<obj.findClosest(2,7,4)<<endl;
        return 0;
    }