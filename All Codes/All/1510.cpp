// Link: https://leetcode.com/problems/stone-game-iv/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(n*sqrt(n)) SC: O(n)
// Approach: We can use dynamic programming to solve this problem. We can create a dp array where dp[i] represents whether the first player can win with i stones. We can iterate through the dp array and for each i, we can check if there is any square number j such that dp[i - j*j] is false. If there is, we can set dp[i] to true. Finally, we can return dp[n].    
class Solution
{
public:
    static const int N = 100002;
    static vector<int> dp;
    bool winnerSquareGame(int n) { return dp[n]; }
};
vector<int> Solution::dp = []()
{
    vector<int> dp(Solution::N, 0);
    for (int i = 1; i < Solution::N; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (dp[i - j * j] == 0)
            {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp;
}();