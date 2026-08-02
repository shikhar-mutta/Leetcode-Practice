// Link: https://leetcode.com/problems/minimum-steps-to-convert-string-with-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2): We have two nested loops, one for the left index and one for the right index, which gives us a time complexity of O(n^2).
// SC: O(n^2): We are using a 2D vector to store the cost of converting substrings, which takes up O(n^2) space.
// Approach: We can use dynamic programming to solve this problem. We can create a 2D vector to store the cost of converting substrings of word1 to substrings of word2. We can then iterate through all possible substrings and calculate the cost of converting them using the given operations. Finally, we can use another vector to store the minimum number of operations needed to convert the entire string.
class Solution
{
public:
    int minOperations(string word1, string word2)
    {
        int n = word1.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        auto add = [&](int a, int b, int cnt[26][26], int &res) -> void
        {
            if (a == b)
                return;

            if (cnt[b][a] > 0)
            {
                --cnt[b][a];
            }
            else
            {
                ++cnt[a][b];
                ++res;
            }
        };

        for (int l = 0; l < n; ++l)
        {
            int cnt[26][26] = {};
            int res = 0;

            for (int r = l; r < n; ++r)
            {
                int a = word1[r] - 'a';
                int b = word2[r] - 'a';

                add(a, b, cnt, res);
                cost[l][r] = res;
            }
        }

        for (int c = 0; c < n; ++c)
        {
            int cnt[26][26] = {};
            int res = 0;

            for (int l = c, r = c; l >= 0 && r < n; --l, ++r)
            {
                if (l == r)
                {
                    int a = word1[l] - 'a';
                    int b = word2[l] - 'a';
                    add(a, b, cnt, res);
                }
                else
                {
                    int a1 = word1[r] - 'a';
                    int b1 = word2[l] - 'a';
                    add(a1, b1, cnt, res);

                    int a2 = word1[l] - 'a';
                    int b2 = word2[r] - 'a';
                    add(a2, b2, cnt, res);
                }

                cost[l][r] = min(cost[l][r], res + 1);
            }
        }

        for (int c = 0; c + 1 < n; ++c)
        {
            int cnt[26][26] = {};
            int res = 0;

            for (int l = c, r = c + 1; l >= 0 && r < n; --l, ++r)
            {
                int a1 = word1[r] - 'a';
                int b1 = word2[l] - 'a';
                add(a1, b1, cnt, res);

                int a2 = word1[l] - 'a';
                int b2 = word2[r] - 'a';
                add(a2, b2, cnt, res);

                cost[l][r] = min(cost[l][r], res + 1);
            }
        }

        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                dp[i] = min(dp[i], dp[j] + cost[j][i - 1]);
            }
        }

        return dp[n];
    }
};
