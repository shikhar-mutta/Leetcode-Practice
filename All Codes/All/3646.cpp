// Link: https://leetcode.com/problems/next-special-palindrome-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1), SC: O(1)
// Approach:
//  1. Precompute all special palindromes up to a certain length (in this case, 16 digits) and store them in a sorted array.
//  2. For each query, use binary search to find the smallest special palindrome that is greater than the given number n.
//  3. Return that special palindrome as the answer.
const int MAX_LEN = 16;
const auto &precompute = []()
{
    const auto &f = [](int mask)
    {
        string result, mid;
        for (int i = 0; i < 9; ++i)
        {
            if ((mask & (1 << i)) == 0)
            {
                continue;
            }
            if ((i + 1) % 2)
            {
                if (!empty(mid))
                {
                    return tuple(result, mid, false);
                }
                mid = to_string(i + 1);
            }
            for (int _ = 0; _ < (i + 1) / 2; ++_)
            {
                result.push_back('0' + (i + 1));
            }
        }
        return tuple(result, mid, true);
    };

    vector<int64_t> result;
    for (int mask = 1; mask < (1 << 9); ++mask)
    {
        auto [left, mid, ok] = f(mask);
        if (!ok)
        {
            continue;
        }
        do
        {
            string right = left;
            reverse(begin(right), end(right));
            string p = left;
            p += mid;
            p += right;
            if (size(p) > MAX_LEN)
            {
                break;
            }
            result.emplace_back(stoll(p));
        } while (next_permutation(begin(left), end(left)));
    }
    sort(begin(result), end(result));
    return result;
};

const auto &PALINDROMES = precompute();
class Solution
{
public:
    long long specialPalindrome(long long n)
    {
        return *upper_bound(begin(PALINDROMES), end(PALINDROMES), n);
    }
};
