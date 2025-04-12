#include <iostream>
#include <array>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    int countGoodIntegers(int n, int k)
    {
        int data[9][10] = {
            {9, 9, 243, 252, 10935, 10944, 617463, 617472, 41457015, 41457024},
            {4, 4, 108, 172, 7400, 9064, 509248, 563392, 37728000, 39718144},
            {3, 3, 69, 84, 3573, 3744, 206217, 207840, 13726509, 13831104},
            {2, 2, 54, 98, 4208, 6992, 393948, 494818, 33175696, 37326452},
            {1, 1, 27, 52, 2231, 3256, 182335, 237112, 15814071, 19284856},
            {1, 1, 30, 58, 2468, 3109, 170176, 188945, 12476696, 13249798},
            {1, 1, 33, 76, 2665, 3044, 377610, 506388, 36789447, 40242031},
            {1, 1, 27, 52, 2231, 5221, 292692, 460048, 30771543, 35755906},
            {1, 1, 23, 28, 1191, 1248, 68739, 69280, 4623119, 4610368}};
        return data[k - 1][n - 1];
    }
    long long countGoodIntegers2(int n, int k)
    {
        unordered_set<string> dict;
        int base = pow(10, (n - 1) / 2);
        int skip = n & 1;
        /* Enumerate the number of palindrome numbers of n digits */
        for (int i = base; i < base * 10; i++)
        {
            string s = to_string(i);
            s += string(s.rbegin() + skip, s.rend());
            long long palindromicInteger = stoll(s);
            /* If the current palindrome number is a k-palindromic integer */
            if (palindromicInteger % k == 0)
            {
                sort(s.begin(), s.end());
                dict.emplace(s);
            }
        }
        vector<long long> factorial(n + 1, 1);
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            factorial[i] = factorial[i - 1] * i;
        }
        for (const string &s : dict)
        {
            vector<int> cnt(10);
            for (char c : s)
            {
                cnt[c - '0']++;
            }
            /* Calculate permutations and combinations */
            long long tot = (n - cnt[0]) * factorial[n - 1];
            for (int x : cnt)
            {
                tot /= factorial[x];
            }
            ans += tot;
        }
        return ans;
    }
};

template <size_t N>
constexpr auto make_fact()
{
    array<long long, N> fact{};
    fact[0] = 1;
    for (size_t i = 1; i < N; ++i)
        fact[i] = i * fact[i - 1];
    return fact;
}

constexpr auto fact = make_fact<11>();

long long make_perm_index(int n, int k, const array<int, 10> &digit_counts)
{
    long long perm_index = n | (k << 4);
    for (int i = 0; i < 10; ++i)
        perm_index |= static_cast<long long>(digit_counts[i]) << (4 * (i + 2));
    return perm_index;
}

void count_palindrome_perms(
    string &prefix,
    array<array<long long, 10>, 11> &solutions,
    unordered_set<long long> &seen_perms)
{
    if (prefix.empty())
    {
        for (char i = '1'; i <= '9'; ++i)
        {
            prefix.push_back(i);
            count_palindrome_perms(prefix, solutions, seen_perms);
            prefix.pop_back();
        }
    }
    else
    {
        for (int suffix_trim = 0; suffix_trim <= 1; ++suffix_trim)
        {
            string suffix = prefix.substr(0, prefix.size() - suffix_trim);
            reverse(suffix.begin(), suffix.end());
            string palindrome = prefix + suffix;

            array<int, 10> digit_counts{};
            for (char ch : palindrome)
                digit_counts[ch - '0']++;

            int n = palindrome.size();
            long long num_perms = fact[n];
            for (int count : digit_counts)
                if (count > 1)
                    num_perms /= fact[count];

            if (digit_counts[0])
                num_perms -= (num_perms * digit_counts[0] / n);

            long long palindrome_val = stoll(palindrome);
            for (int k = 1; k <= 9; ++k)
            {
                long long perm_index = make_perm_index(n, k, digit_counts);
                if (palindrome_val % k == 0 && seen_perms.find(perm_index) == seen_perms.end())
                {
                    solutions[n][k] += num_perms;
                    seen_perms.insert(perm_index);
                }
            }
        }

        if (prefix.size() < 5)
        {
            for (char i = '0'; i <= '9'; ++i)
            {
                prefix.push_back(i);
                count_palindrome_perms(prefix, solutions, seen_perms);
                prefix.pop_back();
            }
        }
    }
}

const array<array<long long, 10>, 11> solve_for_all()
{
    array<array<long long, 10>, 11> solutions{};
    unordered_set<long long> seen_perms;
    string prefix;
    count_palindrome_perms(prefix, solutions, seen_perms);
    return solutions;
}

const array<array<long long, 10>, 11> solutions = solve_for_all();

class Solution2
{
public:
    long long countGoodIntegers(int n, int k)
    {
        return solutions[n][k];
    }
};

int main()
{
    Solution obj1;
    Solution2 obj2;

    cout << "Precomputed: " << obj1.countGoodIntegers(10, 2) << '\n';
    cout << "Generated:   " << obj2.countGoodIntegers(10, 2) << '\n';
    cout << "Generated:   " << obj2.countGoodIntegers(10, 2) << '\n';

    return 0;
}
