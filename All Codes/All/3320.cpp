// Link: https://leetcode.com/problems/count-the-number-of-winning-sequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(n)
//  Approach: We can use dynamic programming to solve this problem. We can create a 3D array dp where dp[i][j][k] represents the number of winning sequences of length i that end with the j-th character and have a difference of k between the number of 'F' and 'W' characters. We can initialize dp[1][0][1] = dp[1][1][0] = dp[1][2][-1] = 1, and for each character in the input string, we can iterate through the possible values of j and k and update dp[i][j][k] based on the previous values of dp[i-1]. Finally, we can return the sum of dp[n][j][k] for all valid values of j and k.
class Solution
{
    static const int R = (int)1e9 + 7;
    int dp[2][3][2005];

public:
    int countWinningSequences(string s)
    {
        int n = s.size();
        int t = (s[0] == 'F') ? 0 : ((s[0] == 'W') ? 1 : 2);
        dp[1][t][0 + n + 1] = dp[1][(t + 1) % 3][1 + n + 1] = dp[1][(t + 2) % 3][-1 + n + 1] = 1;
        int d = 1;
        for (int i = 1; i < n; ++i)
        {
            d = 1 - d;
            for (int j = 0; j <= 2 * n + 3; ++j)
                dp[d][0][j] = dp[d][1][j] = dp[d][2][j] = 0;
            t = (s[i] == 'F') ? 0 : ((s[i] == 'W') ? 1 : 2);
            for (int j = 1; j <= 2 * n + 1; ++j)
            {
                dp[d][t][j] = (dp[1 - d][(t + 1) % 3][j] + dp[1 - d][(t + 2) % 3][j]) % R;
                dp[d][(t + 1) % 3][j] = (dp[1 - d][t % 3][j - 1] + dp[1 - d][(t + 2) % 3][j - 1]) % R;
                dp[d][(t + 2) % 3][j] = (dp[1 - d][t % 3][j + 1] + dp[1 - d][(t + 1) % 3][j + 1]) % R;
            }
        }
        int ans = 0;
        for (int j = 1 + n + 1; j <= 2 * n + 1; ++j)
            ans = ((ans + dp[d][0][j]) % R + (dp[d][1][j] + dp[d][2][j]) % R) % R;
        return ans;
    }
};
