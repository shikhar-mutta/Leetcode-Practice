// Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(n)
// Approach: Use dynamic programming to find the maximum dot product of two subsequences. We can use a 1D dp array where dp[j] represents the maximum dot product of the first i elements of nums1 and the first j elements of nums2. We iterate through each element of nums1 and nums2 and update the dp array accordingly. Finally, we return dp[n] which represents the maximum dot product of the two subsequences.
class Solution
{
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        if (m < n)
        {
            return maxDotProduct(nums2, nums1);
        }

        vector<long> dp(n + 1, INT_MIN);

        for (int i = 0; i < m; i++)
        {
            long prev = 0;
            for (int j = 0; j < n; j++)
            {
                long tmp = dp[j + 1];
                dp[j + 1] =
                    max(prev + (long)nums1[i] * nums2[j],
                        max((long)nums1[i] * nums2[j], max(dp[j], dp[j + 1])));
                prev = tmp;
            }
        }

        return (int)dp[n];
    }
};