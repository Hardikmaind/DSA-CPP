#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/count-good-numbers/solutions/6581822/count-good-numbers



class Solution {
    private:
        static constexpr int mod = 1000000007;
    
    public:
        //! tc is O(logn) and sc is O(1)
        int countGoodNumbers(long long n) {
            // use fast exponentiation to calculate x^y % mod
            auto quickmul = [](int x, long long y) -> int {
                int ret = 1, mul = x;
                while (y > 0) {
                    if (y % 2 == 1) {
                        ret = (long long)ret * mul % mod;
                    }
                    mul = (long long)mul * mul % mod;
                    y /= 2;
                }
                return ret;
            };
    
            return (long long)quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
        }
    };

    int main(){
        Solution s;
        cout<<s.countGoodNumbers(50)<<endl;
        cout<<s.countGoodNumbers(100)<<endl;
        return 0;
    }