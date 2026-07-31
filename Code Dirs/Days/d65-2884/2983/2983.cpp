// Link: https://leetcode.com/problems/palindrome-rearrangement-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N + Q), SC: O(N) where N = length of string s and Q = number of queries
//  Approach: Precompute the frequency of each character in the left and right halves of the string
//  and also precompute the number of characters that are equal in both halves. For each query, check the conditions for the specified regions to determine if a palindrome can be formed.
class Solution
{
    inline bool subset_match(const vector<array<int, 26>> &T_sub,
                             const vector<array<int, 26>> &T_sup, int start_sub,
                             int end_sub, int start_sup, int end_sup)
    {

        int subset_width = end_sub - start_sub + 1;
        int subset_count = 0;

        for (int i = 0; i < 26; i++)
        {

            int diff_sub = T_sub[end_sub][i] - T_sub[start_sub - 1][i];
            int diff_sup = T_sup[end_sup][i] - T_sup[start_sup - 1][i];

            int fix_above_sub =
                T_sub[end_sup][i] - T_sub[end_sub][i]; // (end_sub + 1) - 1
            int fix_below_sub =
                T_sub[start_sub - 1][i] - T_sub[start_sup - 1][i];

            diff_sup -= fix_below_sub;
            diff_sup -= fix_above_sub;

            // if (diff_sup < fix_below_sub || (diff_sup - fix_below_sub) <
            // fix_above_sub) {
            //     return false;
            // }
            if (diff_sup < 0)
            {
                return false;
            }

            if (diff_sup != diff_sub)
            {
                return false;
            }
            else
            {
                subset_count += diff_sub; // diff_sup
            }

            if (subset_count > subset_width)
            {
                return false;
            }
        }
        return true;
    }

    inline bool overlap_match(const vector<array<int, 26>> &T_low,
                              const vector<array<int, 26>> &T_high,
                              int start_low, int end_low, int start_high,
                              int end_high)
    {

        int overlap_width = end_low - start_high + 1;
        int overlap_count = 0;

        for (int i = 0; i < 26; i++)
        {

            int diff_low = T_low[end_low][i] - T_low[start_low - 1][i];
            int diff_high = T_high[end_high][i] - T_high[start_high - 1][i];

            int fix_above_low =
                T_low[end_high][i] - T_low[end_low][i]; // (end_low + 1) - 1
            int fix_below_high =
                T_high[start_high - 1][i] - T_high[start_low - 1][i];

            int overlap_low = diff_low - fix_below_high;
            int overlap_high = diff_high - fix_above_low;

            // if (diff_low < fix_below_high || diff_high < fix_above_low) {
            //     return false;
            // }
            if (overlap_low < 0 || overlap_high < 0)
            {
                return false;
            }

            if (overlap_low != overlap_high)
            {
                return false;
            }
            else
            {
                overlap_count += overlap_low; // overlap_high
            }

            if (overlap_count > overlap_width)
            {
                return false;
            }
        }
        return true;
    }

    inline bool freq_same(const vector<array<int, 26>> &Tl,
                          const vector<array<int, 26>> &Tr, int start,
                          int end)
    {

        for (int i = 0; i < 26; i++)
        {
            int diff_l = Tl[end][i] - Tl[start - 1][i];
            int diff_r = Tr[end][i] - Tr[start - 1][i];

            if (diff_l != diff_r)
            {
                return false;
            }
        }
        return true;
    }

    inline bool exactly_same(const vector<int> &equality, int start, int end)
    {

        if (start > end)
        {
            return true;
        }
        return (equality[end] - equality[start - 1]) ==
               (end - start + 1); // end - (start - 1)
    }

public:
    vector<bool> canMakePalindromeQueries(string s,
                                          vector<vector<int>> &queries)
    {
        int n = s.size();
        int q = queries.size();
        int n_half = n >> 1;

        vector<array<int, 26>> Tl(n_half + 1, array<int, 26>{});
        vector<array<int, 26>> Tr(n_half + 1, array<int, 26>{});
        vector<int> equality(n_half + 1, 0);

        for (int i = 1; i <= n_half; i++)
        {

            Tl[i] = Tl[i - 1];
            Tl[i][s[i - 1] - 'a']++;
        }

        for (int i = 1, c = n; i <= n_half; i++, c--)
        {

            Tr[i] = Tr[i - 1];
            Tr[i][s[c - 1] - 'a']++;
        }
        for (int i = 1; i <= n_half; i++)
        {
            equality[i] = equality[i - 1] + (s[i - 1] == s[n - i]);
        }

        // 4 indexes
        // a, b, c, d
        // find all regions
        vector<bool> answer(q, true);

        for (int i = 0; i < q; i++)
        {
            int a = queries[i][0] + 1;
            int b = queries[i][1] + 1;
            int d = n - queries[i][2]; // Tr is reverse, so are 'c' & 'd'
            int c = n - queries[i][3];

            if (c > b)
            {

                if (!exactly_same(equality, d + 1, n_half) ||
                    !exactly_same(equality, b + 1, c - 1) ||
                    !exactly_same(equality, 1, a - 1) ||
                    !freq_same(Tl, Tr, c, d) || !freq_same(Tl, Tr, a, b))
                {
                    answer[i] = false;
                }
            }
            else if (a > d)
            {

                if (!exactly_same(equality, b + 1, n_half) ||
                    !exactly_same(equality, d + 1, a - 1) ||
                    !exactly_same(equality, 1, c - 1) ||
                    !freq_same(Tl, Tr, a, b) || !freq_same(Tl, Tr, c, d))
                {
                    answer[i] = false;
                }
            }
            else if (d >= b && c >= a)
            {

                if (!exactly_same(equality, d + 1, n_half) ||
                    !exactly_same(equality, 1, a - 1) ||
                    !overlap_match(Tl, Tr, a, b, c, d))
                {
                    answer[i] = false;
                }
            }
            else if (b >= d && a >= c)
            {

                if (!exactly_same(equality, b + 1, n_half) ||
                    !exactly_same(equality, 1, c - 1) ||
                    !overlap_match(Tr, Tl, c, d, a, b))
                {
                    answer[i] = false;
                }
            }
            else if (d >= b && c <= a)
            {

                if (!exactly_same(equality, d + 1, n_half) ||
                    !exactly_same(equality, 1, c - 1) ||
                    !subset_match(Tl, Tr, a, b, c, d))
                {
                    answer[i] = false;
                }
            }
            else if (b >= d && a <= c)
            {

                if (!exactly_same(equality, b + 1, n_half) ||
                    !exactly_same(equality, 1, a - 1) ||
                    !subset_match(Tr, Tl, c, d, a, b))
                {
                    answer[i] = false;
                }
            }
        }

        return answer;
    }
};
