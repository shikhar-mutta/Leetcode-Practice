// Link: https://leetcode.com/problems/count-substrings-that-differ-by-one-character/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N*M) where N is the length of string A and M is the length of string B.
    // SC: O(N*M) for storing the dp array.
    // Approach:
    //         1. Use dynamic programming to count the number of substrings that differ by one character.
    //         2. Initialize a 3D dp array of size (N+1) x (M+1) x 2 with all elements as 0.
    //         3. Iterate through the strings A and B in reverse order and for each character, check if they are equal or not. If they are equal, update the dp array accordingly. If they are not equal, update the dp array accordingly.
    //         4. If the dp value for the current characters is not -1, add the difference between the two dp values to the result.
    //         5. Return the result.
    int countSubstrings(string A, string B)
    {
        int N = A.size();
        int M = B.size();
        int dp[N + 1][M + 1][2];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++)
            dp[i][M][1] = -1;
        for (int j = 0; j < M; j++)
            dp[N][j][1] = -1;
        dp[N][M][1] = -1;

        int res = 0;
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = M - 1; j >= 0; j--)
            {
                for (int k = 0; k <= 1; k++)
                {
                    if (A[i] == B[j])
                    {
                        if (k == 0)
                        {
                            dp[i][j][0] = 1 + dp[i + 1][j + 1][0];
                        }
                        if (k == 1)
                        {
                            if (dp[i + 1][j + 1][1] == -1)
                                dp[i][j][1] = -1;
                            else
                                dp[i][j][1] = 1 + dp[i + 1][j + 1][1];
                        }
                    }
                    else
                    {
                        if (k == 0)
                            dp[i][j][0] = 0;
                        if (k == 1)
                            dp[i][j][1] = 1 + dp[i + 1][j + 1][0];
                    }
                }
                if (dp[i][j][1] != -1)
                {
                    res += max(0, dp[i][j][1] - dp[i][j][0]);
                }
            }
        }
        return res;
    }
};
