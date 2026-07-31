// Link: https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * numCarpets)  SC: O(n * numCarpets)
// Approach: We can use dynamic programming to solve this problem. We can create a 2D array dp where dp[i][j] represents the minimum number of white tiles that can be left uncovered after covering the first i tiles with j carpets. We can iterate through the floor string and for each tile, we can either skip it or place a carpet on it. If we skip it, we add 1 to the count of white tiles if it is a white tile. If we place a carpet on it, we can cover the next carpetLen tiles and move to the next tile after that. Finally, we return dp[n][numCarpets] where n is the length of the floor string.
auto fast_io = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution
{
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
    {
        int n = floor.size();
        int dp[n + 1][numCarpets + 1];
        for (int j = 0; j <= numCarpets; j++)
        {
            dp[n][j] = 0;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= numCarpets; j++)
            {
                int cur = (floor[i] != '1') ? 0 : 1;
                int skip = cur + dp[i + 1][j];
                int place = 1e9;
                if (j > 0)
                {
                    int mini = (i + carpetLen <= n) ? (i + carpetLen) : n;
                    place = dp[mini][j - 1];
                }
                dp[i][j] = min(skip, place);
            }
        }
        return dp[0][numCarpets];
    }
};