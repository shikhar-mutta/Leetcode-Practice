// Link: https://leetcode.com/problems/plates-between-candles/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m), SC: O(n)
//   Approach:
//   1. We can use prefix sum to count the number of plates between candles.
//  2. We can use two arrays to store the index of the nearest candle to the left and right of each index.
//  3. For each query, we can find the nearest candle to the right of the left index and the nearest candle to the left of the right index. If both candles exist and the left candle is to the left of the right candle, we can calculate the number of plates between the two candles using the prefix sum array. Otherwise, we return 0.
//  4. We can return the result for each query in a vector.
class Solution
{
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<int> pre(n + 1, 0), left(n), right(n);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + (s[i] == '*');
        int last = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '|')
                last = i;
            left[i] = last;
        }
        last = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '|')
                last = i;
            right[i] = last;
        }
        vector<int> ans;
        for (auto &q : queries)
        {
            int l = right[q[0]];
            int r = left[q[1]];
            if (l == -1 || r == -1 || l >= r)
                ans.push_back(0);
            else
                ans.push_back(pre[r] - pre[l]);
        }
        return ans;
    }
};
