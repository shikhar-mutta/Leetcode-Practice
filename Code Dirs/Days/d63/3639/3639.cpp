// Link: https://leetcode.com/problems/minimum-time-to-activate-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: maintain left and right pointers for each position, and update the count of valid substrings as stars are added.
class Solution
{
public:
    int minTime(string s, vector<int> &order, int k)
    {
        int n = s.length();
        vector<int> left(n), right(n);
        for (int i = 0; i < n; ++i)
        {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        long long cnt = (long long)n * (n + 1) / 2;
        if (cnt < k)
        {
            return -1;
        }
        for (int t = n - 1; t >= 0; --t)
        {
            int i = order[t], l = left[i], r = right[i];
            cnt -= 1LL * (i - l) * (r - i);
            if (cnt < k)
            {
                return t;
            }
            if (l >= 0)
            {
                right[l] = r;
            }
            if (r < n)
            {
                left[r] = l;
            }
        }
        return -1;
    }
};