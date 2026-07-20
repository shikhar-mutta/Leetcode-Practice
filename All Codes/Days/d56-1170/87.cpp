// Link: https://leetcode.com/problems/scramble-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^4) - The recursive function explores all possible partitions of the strings, leading to a time complexity of O(n^4) in the worst case. The memoization helps reduce redundant calculations, but the overall complexity remains high due to the nested loops and recursive calls.
// SC: O(n^3) - The memoization table stores results for all possible combinations of starting indices and lengths, leading to a space complexity of O(n^3). Additionally, the prefix frequency arrays require O(n) space each, but this is dominated by the memoization table.
// Approach:
// 1. We define a recursive function solve that takes two strings s1 and s2, along with their starting indices i and j, and the length of the substring len. This function checks if the substring of s1 starting at index i and the substring of s2 starting at index j with length len are scramble strings.
// 2. We use memoization to store the results of previously computed subproblems in a 3D array memo. If the result for a particular combination of i, j, and len has already been computed, we return the stored result to avoid redundant calculations.
// 3. We also use prefix frequency arrays pref1 and pref2 to quickly check if the characters in the substrings of s1 and s2 are anagrams of each other. If the character counts do not match, we can immediately return false for that combination.
// 4. The solve function checks for base cases, such as when the length of the substring is 1 or when the substrings are identical. It then explores all possible partitions of the substrings and recursively checks if they are scramble strings, considering both the non-swap and swap cases. The heuristic of checking the first character helps optimize the search by prioritizing the non-swap case when the first characters match.

class Solution
{
private:
    int8_t memo[31][31][31];
    int pref1[31][26];
    int pref2[31][26];

    inline bool solve(const string &s1, const string &s2,
                      int i, int j, int len)
    {

        int8_t &res = memo[i][j][len];
        if (res != -1)
            return res;

        if (len == 1)
            return res = (s1[i] == s2[j]);

        // Fast equality check
        bool same = true;
        for (int k = 0; k < len; ++k)
        {
            if (s1[i + k] != s2[j + k])
            {
                same = false;
                break;
            }
        }
        if (same)
            return res = 1;

        // Fast anagram pruning using prefix frequency
        for (int c = 0; c < 26; ++c)
        {
            if (pref1[i + len][c] - pref1[i][c] !=
                pref2[j + len][c] - pref2[j][c])
                return res = 0;
        }

        for (int k = 1; k < len; ++k)
        {

            // Heuristic:
            // jika karakter pertama sama, kemungkinan besar non-swap
            if (s1[i] == s2[j])
            {

                if (solve(s1, s2, i, j, k) &&
                    solve(s1, s2, i + k, j + k, len - k))
                    return res = 1;

                if (solve(s1, s2, i, j + len - k, k) &&
                    solve(s1, s2, i + k, j, len - k))
                    return res = 1;
            }
            else
            {

                if (solve(s1, s2, i, j + len - k, k) &&
                    solve(s1, s2, i + k, j, len - k))
                    return res = 1;

                if (solve(s1, s2, i, j, k) &&
                    solve(s1, s2, i + k, j + k, len - k))
                    return res = 1;
            }
        }

        return res = 0;
    }

public:
    bool isScramble(string s1, string s2)
    {

        int n = s1.size();
        if (n != (int)s2.size())
            return false;

        memset(memo, -1, sizeof(memo));

        memset(pref1, 0, sizeof(pref1));
        memset(pref2, 0, sizeof(pref2));

        for (int i = 0; i < n; ++i)
        {
            memcpy(pref1[i + 1], pref1[i], sizeof(pref1[i]));
            memcpy(pref2[i + 1], pref2[i], sizeof(pref2[i]));

            pref1[i + 1][s1[i] - 'a']++;
            pref2[i + 1][s2[i] - 'a']++;
        }

        return solve(s1, s2, 0, 0, n);
    }
};