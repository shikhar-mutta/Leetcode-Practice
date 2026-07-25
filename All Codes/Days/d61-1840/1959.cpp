// Link: https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * k) where n is the size of nums and k is the number of resizing operations
// SC: O(n * k) where n is the size of nums and k is the number of resizing operations
//  Approach: DP
// 1. Create a 2D dp array of size (n+1) x (k+1) where n is the size of nums and k is the number of resizing operations. Initialize all values to a large number (1e9).
// 2. Calculate the sum of all elements in nums and store it in a variable sum.
// 3. Set dp[0][k] = 0 for all k from 0 to t
// 4. For each i from 1 to n, calculate the maximum value of nums[0] to nums[i-1] and set dp[i][0] = maxi * i
class Solution
{
public:
    int dp[205][205];

    int minSpaceWastedKResizing(vector<int> &nums, int t)
    {
        int n = nums.size();
        // memset(dp,1e9,sizeof(dp));

        for (int i = 0; i <= n; i++)
        {
            for (int k = 0; k <= t; k++)
            {
                dp[i][k] = 1e9;
            }
        }

        int sum = 0;
        for (auto num : nums)
            sum += num;

        for (int k = 0; k <= t; k++)
            dp[0][k] = 0;

        int maxi = 0;
        for (int i = 1; i <= n; i++)
        {
            maxi = max(maxi, nums[i - 1]);
            dp[i][0] = maxi * i;
        }

        for (int i = 1; i <= n; i++)
        {
            maxi = 0;
            for (int j = i; j > 0; j--)
            {
                maxi = max(maxi, nums[j - 1]);
                for (int k = 1; k <= t; k++)
                {
                    dp[i][k] =
                        min(dp[i][k], dp[j - 1][k - 1] + (i - j + 1) * maxi);
                }
            }
        }

        return dp[n][t] - sum;
    }
};