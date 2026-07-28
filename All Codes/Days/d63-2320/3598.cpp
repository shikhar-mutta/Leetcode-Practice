// Link: https://leetcode.com/problems/longest-common-prefix-between-adjacent-strings-after-removals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) SC: O(n)
// Approach: For each pair of adjacent strings, find the longest common prefix. Keep track of the maximum length of the longest common prefix found so far and the second maximum length. For each string, check if it is part of the pair that has the maximum length. If it is, use the second maximum length for that string; otherwise, use the maximum length.
class Solution
{
public:
    int match(string &a, string &b)
    {
        int n = min(a.size(), b.size());
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                return i;
        }

        return n;
    }

    vector<int> longestCommonPrefix(vector<string> &words)
    {
        int n = words.size();
        vector<int> ans(n);

        int firstpos = -1;
        int fMax = 0;
        int sMax = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int x = match(words[i], words[i + 1]);
            if (x >= fMax)
            {
                firstpos = i;
                sMax = fMax;
                fMax = x;
            }
            else if (x > sMax)
                sMax = x;
        }

        for (int i = 0; i < n; i++)
        {
            int len = 0;

            if (i - 1 >= 0 && i + 1 < n)
            {
                len = match(words[i - 1], words[i + 1]);
            }

            if (i == firstpos || i == firstpos + 1)
            {
                ans[i] = max(len, sMax);
            }
            else
            {
                ans[i] = max(len, fMax);
            }
        }

        return ans;
    }
};