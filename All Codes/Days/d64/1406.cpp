// Link: https://leetcode.com/problems/stone-game-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: Dynamic Programming
// We can use a 1D array to store the maximum score difference that the current player can achieve over the other player starting from index i. The current player can choose to take 1, 2, or 3 stones, and we can calculate the score difference for each choice and take the maximum of them. The base case is when there are no stones left, in which case the score difference is 0. Finally, we check the score difference at index 0 to determine the winner.
class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int> dp(3, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int t1 = stoneValue[i] - dp[(i + 1) % 3];
            int t2 = INT_MIN;
            if (i + 1 < n)
                t2 = stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) % 3];
            int t3 = INT_MIN;
            if (i + 2 < n)
                t3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] -
                     dp[(i + 3) % 3];
            dp[i % 3] = max({t1, t2, t3});
        }
        int ans = dp[0];
        if (ans > 0)
            return "Alice";
        else if (ans < 0)
            return "Bob";
        else
            return "Tie";
    }
};