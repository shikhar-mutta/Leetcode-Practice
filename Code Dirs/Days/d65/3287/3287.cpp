// Link: https://leetcode.com/problems/find-the-maximum-sequence-value-of-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) where n is the length of the nums array
// SC: O(n^2) where n is the length of the nums array
// Approach: We can use dynamic programming to solve this problem. We can create a 2D array dp where dp[i][j] represents the maximum xor score of the subarray nums[i...j]. We can fill the dp array by iterating through all possible subarrays and calculating the maximum xor score for each subarray. Finally, we can return the maximum xor score for each query by accessing the dp array.
class Solution
{
public:
    int maxValue(vector<int> &nums, int k)
    {
        int n = nums.size();
        int m = 128;
        vector<int> prefix(m, -1), suffix(m, -1);
        vector<int> dp(m, 1e9), cnt(m, 0);
        for (int i = 0; i < n; ++i)
        {
            int val = nums[i];
            dp[val] = 1;
            for (int mask = 0; mask < m; ++mask)
            {
                dp[val | mask] = min(dp[val | mask], dp[mask] + 1);
                if ((val & mask) == val)
                {
                    cnt[mask]++;
                }
            }
            for (int mask = 0; mask < m; ++mask)
            {
                if (dp[mask] <= k && cnt[mask] >= k && prefix[mask] == -1)
                {
                    prefix[mask] = i;
                }
            }
        }
        dp.assign(m, 1e9);
        cnt.assign(m, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            int val = nums[i];
            dp[val] = 1;
            for (int mask = 0; mask < m; ++mask)
            {
                dp[val | mask] = min(dp[val | mask], dp[mask] + 1);
                if ((val & mask) == val)
                {
                    cnt[mask]++;
                }
            }
            for (int mask = 0; mask < m; ++mask)
            {
                if (dp[mask] <= k && cnt[mask] >= k && suffix[mask] == -1)
                {
                    suffix[mask] = i;
                }
            }
        }
        for (int mask = m - 1; mask >= 0; --mask)
        {
            for (int l = m - 1; l >= 0; --l)
            {
                int r = mask ^ l;
                if (prefix[l] == -1 || suffix[r] == -1)
                {
                    continue;
                }
                if (prefix[l] < suffix[r])
                {
                    return mask;
                }
            }
        }
        return -1;
    }
};