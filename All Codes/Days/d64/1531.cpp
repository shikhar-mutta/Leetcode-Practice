// Link: https://leetcode.com/problems/string-compression-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * k) SC: O(n * k)
// Approach: We can use dynamic programming to solve this problem. We can define a dp array where dp[i][k] represents the minimum length of the compressed string for the substring s[i:] with k deletions allowed. We can iterate through the string and for each character, we can either delete it or keep it. If we keep it, we can count how many same characters are there and calculate the length of the compressed string accordingly. Finally, we can return dp[0][k] as the answer.
class Solution
{
public:
    int dp[101][101];
    const int INF = 1e9;

    int solve(string &s, int idx, int k)
    {
        if (k < 0)
            return INF;

        if (idx >= s.size() || s.size() - idx <= k)
            return 0;

        if (dp[idx][k] != -1)
            return dp[idx][k];

        // Option 1: Delete current character
        int ans = solve(s, idx + 1, k - 1);

        // Option 2: Keep current character
        int same = 0;
        int removed = 0;

        for (int j = idx; j < s.size(); j++)
        {
            if (s[j] == s[idx])
            {
                same++;

                int len;
                if (same == 1)
                    len = 1;
                else if (same < 10)
                    len = 2;
                else if (same < 100)
                    len = 3;
                else
                    len = 4;

                ans = min(ans, len + solve(s, j + 1, k - removed));
            }
            else
            {
                removed++;
                if (removed > k)
                    break;
            }
        }

        return dp[idx][k] = ans;
    }

    int getLengthOfOptimalCompression(string s, int k)
    {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, k);
    }
};