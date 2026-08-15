// Link: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(3^N) where N is the length of the string s
// SC: O(1)
// Approach:
//  1. We will use bitmasking to generate all possible subsequences of the string
//  2. For each subsequence, we will check if it is a palindrome and store its length in a dp table
//  3. We will then iterate through all pairs of disjoint subsequences and calculate the product of their lengths if both are palindromes
//  4. Finally, we will return the maximum product found
class Solution
{
public:
    int palSize(string &s, int mask)
    {
        int p1 = 0, p2 = s.size() - 1, res = 0;

        while (p1 <= p2)
        {
            if ((mask & (1 << p1)) == 0)
                ++p1;
            else if ((mask & (1 << p2)) == 0)
                --p2;
            else if (s[p1] != s[p2])
                return 0; // Not a palindrome
            else
                res +=
                    1 + (p1++ != p2--); // Add 1 if center element, 2 otherwise
        }

        return res;
    }

    int maxProduct(string s)
    {
        int dp[4096] = {}, res = 0;
        int mask = (1 << s.size()) - 1;

        // Step 1: Precompute palindrome sizes for all possible bitmasks
        for (int m = 1; m <= mask; ++m)
        {
            dp[m] = palSize(s, m);
        }

        // Step 2: Enumerate pairs of disjoint submasks
        for (int m1 = mask; m1; --m1)
        {
            // Pruning: skip if m1 cannot beat the current max product even with
            // all remaining characters
            if (dp[m1] * (int)(s.size() - dp[m1]) > res)
            {

                // m2 iterates ONLY through the submasks of the inverted
                // complement of m1
                for (int m2 = mask ^ m1; m2; m2 = (m2 - 1) & (mask ^ m1))
                {
                    res = max(res, dp[m1] * dp[m2]);
                }
            }
        }

        return res;
    }
};