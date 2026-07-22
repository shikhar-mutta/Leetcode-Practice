// Link: https://leetcode.com/problems/predict-the-winner/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2)
    // SC: O(n^2)
    //  Approach:
    //  1. We use dynamic programming to solve this problem. We create a 2D vector dp where dp[i][j] represents the maximum score difference the current player can achieve over the other player when considering the subarray nums[i] to nums[j].
    //  2. We initialize the diagonal of the dp array with the values of nums since when there is only one number left, the current player takes that number and the score difference is simply that number.
    //  3. We then fill the dp array for subarrays of length 2 to n. For each subarray nums[i] to nums[j], the current player can choose either nums[i] or nums[j]. If the current player chooses nums[i], the score difference will be nums[i] - dp[i + 1][j] (the score difference after the other player plays optimally on the remaining subarray). If the current player chooses nums[j], the score difference will be nums[j] - dp[i][j - 1]. We take the maximum of these two options to fill dp[i][j].
    //  4. Finally, we check if dp[0][n - 1] is greater than or equal to 0. If it is, it means the first player can win or tie the game, so we return true. Otherwise, we return false.
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j],
                               nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};