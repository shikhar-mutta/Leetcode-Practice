// Link: https://leetcode.com/problems/find-the-count-of-monotonic-pairs-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of nums
// SC: O(n) where n is the length of nums
// Approach: We can use dynamic programming to keep track of the number of monotonic pairs that can be formed with the first i elements of nums. We can use a dp array where dp[i] represents the number of monotonic pairs that can be formed with the first i elements of nums. We can initialize dp[0] = 1 since there is only one way to form a monotonic pair with the first element. For each subsequent element, we can update dp[i] based on the previous elements. If nums[i] is greater than or equal to nums[i-1], we can add dp[i-1] to dp[i] since we can form a monotonic pair with the previous element. If nums[i] is less than nums[i-1], we can add dp[i-1] to dp[i] since we can form a monotonic pair with the previous element. Finally, we can return dp[n-1] as the result.
class Solution
{
    static constexpr int mod = 1'000'000'007;

public:
    int countOfPairs(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(1 + *max_element(nums.begin(), nums.end()));
        iota(dp.begin(), dp.begin() + nums[0] + 1, 1);

        for (int i = 1; i < n; ++i)
        {
            if (nums[i - 1] < nums[i])
                for (int j = nums[i]; j >= 0; --j)
                {
                    int k = j + nums[i - 1] - nums[i];
                    dp[j] = k < 0 ? 0 : dp[k];
                }
            partial_sum(dp.begin(), dp.begin() + nums[i] + 1, dp.begin(),
                        [](int a, int b)
                        {
                            int res = a + b;
                            return res < mod ? res : res - mod;
                        });
        }

        return dp[nums[n - 1]];
    }
};