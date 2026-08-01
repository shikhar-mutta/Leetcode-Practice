// Link: https://leetcode.com/problems/count-binary-palindromic-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(n)), SC: O(1)
// Approach:
//  1. Count the number of binary palindromes with lengths less than the length of n.
//  2. For binary palindromes with the same length as n, generate the first half of the palindrome and check if it is less than or equal to n. If it is, increment the count.
//  3. Return the total count of binary palindromes less than or equal to n.
class Solution
{
public:
    long long countBinaryPalindromes(long long n)
    {
        if (n == 0)
            return 1;

        auto makePalindrome = [&](long long half, int len) -> long long
        {
            long long res = half;
            long long x = (len & 1) ? (half >> 1) : half;
            while (x)
            {
                res = (res << 1) | (x & 1);
                x >>= 1;
            }
            return res;
        };

        int maxLen = 0;
        {
            long long t = n;
            while (t)
            {
                maxLen++;
                t >>= 1;
            }
        }

        long long ans = 1; // number 0

        for (int len = 1; len < maxLen; len++)
        {
            int halfBits = (len + 1) / 2;
            ans += 1LL << (halfBits - 1);
        }

        int halfBits = (maxLen + 1) / 2;
        long long prefix = n >> (maxLen / 2);

        long long first = 1LL << (halfBits - 1);
        if (prefix >= first)
            ans += prefix - first;

        long long pal = makePalindrome(prefix, maxLen);
        if (pal <= n)
            ans++;

        return ans;
    }
};
