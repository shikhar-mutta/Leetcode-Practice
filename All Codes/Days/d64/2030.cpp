// Link: https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: monotonic increasing stack building the lexicographically
//  smallest subsequence of length k. Pop a larger top char only if enough
//  characters remain afterward to fill the stack to length k, and popping
//  wouldn't drop the letter count below the required repetition.
class Solution
{
public:
    string &smallestSubsequence(string &s, int k, char letter, int repetition)
    {
        const int n{static_cast<int>(s.length())};
        int skp{
            static_cast<int>(count(s.begin(), s.end(), letter) - repetition)};
        int ptr{0};
        for (int i{0}; i < n; ++i)
        {
            const char c{s[i]};
            while (ptr && s[ptr - 1] > c && k - ptr + 1 <= n - i &&
                   (s[ptr - 1] != letter || skp))
            {
                if (s[ptr - 1] == letter)
                {
                    --skp;
                    ++repetition;
                }
                --ptr;
            }
            if (ptr < k && (c == letter || k - ptr - 1 >= repetition))
            {
                if (c == letter)
                    --repetition;
                s[ptr++] = c;
            }
            else if (c == letter)
                --skp;
        }
        s.resize(k);
        return s;
    }
};
