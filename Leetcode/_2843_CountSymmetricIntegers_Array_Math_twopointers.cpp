#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {

        int cnt = 0;

        for (int i = low; i <= high; i++)
        {
            string s = to_string(i);
            int n = s.size();

            if (n % 2 == 0)
            {
                int j = 0;
                int val1 = 0, val2 = 0;

                while (j < (n / 2))
                {
                    val1 += s[j] - '0';
                    val2 += s[n - j - 1] - '0';
                    j++;
                }

                if (val1 == val2)
                    cnt++;
            }
        }

        return cnt;
    }
};

class Solution2
{
public:
    bool checksum2(int no)
    {
        vector<int> arr;
        while (no > 0)
        {
            arr.push_back(no % 10);
            no = no / 10;
        }
        int n = arr.size();
        int lsum = 0, rsum = 0;

        for (int i = 0; i < n / 2; ++i)
        {
            rsum += arr[i];         // last half (reversed order)
            lsum += arr[n - 1 - i]; // first half
        }
        return lsum == rsum;
    }

    int countSymmetricIntegers2(int low, int high)
    {
        int count = 0;
        for (int i = low; i <= high; i++)
        {
            int digitCount = (i == 0) ? 1 : (int)log10(i) + 1;
            if (digitCount % 2 == 0)
            {
                if (checksum2(i))
                {
                    count++;
                }
            }
        }
        return count;
    }

    bool checksum(int no)
    {
        vector<int> arr;
        while (no > 0)
        {
            arr.push_back(no % 10);
            no /= 10;
        }
        int n = arr.size();
        int lsum = 0, rsum = 0;

        for (int i = 0; i < n / 2; ++i)
        {
            rsum += arr[i];
            lsum += arr[n - 1 - i];
        }
        return lsum == rsum;
    }
    int countSymmetricIntegers(int low, int high)
    {
        int count = 0;
        for (int i = low; i <= high; ++i)
        {
            int digitCount = (i == 0) ? 1 : (int)log10(i) + 1;
            if (digitCount % 2 == 0)
            {
                if (checksum(i))
                {
                    count++;
                }
            }
        }
        return count;
    }
};
int main(){
    Solution2 s2;
    Solution s;
    cout<<s.countSymmetricIntegers(1,100)<<endl;
    cout<<s2.countSymmetricIntegers2(1,100)<<endl;
}