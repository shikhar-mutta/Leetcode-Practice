// Link: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + 26) = O(n) – one pass to collect runs, O(26) to compute answer
// SC: O(26 * 3) = O(1) – fixed top-3 array per character
// Approach: For character c, a special substring of length L occurs in a run
// of length k exactly (k - L + 1) times. Track the top-3 run lengths per
// character. For the longest L with ≥ 3 total occurrences, three cases:
//   1) v[0]-2 : longest run alone gives ≥ 3 occurrences  (v[0]-L+1 >= 3)
//   2) min(v[0]-1, v[1]) : top-2 runs together give ≥ 3  (2 + 1)
//   3) v[2]   : each of top-3 runs gives ≥ 1 occurrence
// Answer = max over all chars of max(v[2], min(v[0]-1,v[1]), v[0]-2).
// Note: return -1 if ans == 0 (no valid substring found).
class Solution
{
public:
    int maximumLength(string s)
    {
        vector<array<int, 3>> top(26, {-1, -1, -1});
        int ans = -1;
        for (int start = 0; start < s.size();)
        {
            int end = start;
            while (end < s.size() && s[start] == s[end])
                end++;
            auto &a = top[s[start] - 'a'];
            int len = end - start;
            if (a[0] < len)
            {
                a[2] = a[1];
                a[1] = a[0];
                a[0] = len;
            }
            else if (a[1] < len)
            {
                a[2] = a[1];
                a[1] = len;
            }
            else if (a[2] < len)
            {
                a[2] = len;
            }
            start = end;
        }
        for (auto &v : top)
        {
            ans = max({ans, v[2], min(v[0] - 1, v[1]), v[0] - 2});
        }
        return ans ? ans : -1;
    }
};
