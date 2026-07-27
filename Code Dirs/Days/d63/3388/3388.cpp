// Link: https://leetcode.com/problems/count-beautiful-splits-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
//  Approach: use Z-algorithm to compute the longest common prefix of each suffix
//  with the first suffix. For each possible split, check if the conditions for a
//  beautiful split are met.
class Solution
{
public:
    int beautifulSplits(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;

        std::vector<int> z(n, 0);
        z[0] = n;
        for (int i = 1, l = 0, r = 0; i < n; i++)
        {
            if (i < r)
                z[i] = std::min(r - i, z[i - l]);
            while (i + z[i] < n && nums[z[i]] == nums[i + z[i]])
                z[i]++;
            if (i + z[i] > r)
            {
                l = i;
                r = i + z[i];
            }
        }

        int count = 0;
        for (int d = 1; d <= n - 2; d++)
        {
            int lcp_prev = 0;
            for (int k = n - 1 - d; k >= 1; k--)
            {
                int lcp_k = (nums[k] == nums[k + d]) ? lcp_prev + 1 : 0;
                lcp_prev = lcp_k;
                if ((d >= k && z[k] >= k) || lcp_k >= d)
                    count++;
            }
        }

        return count;
    }
};