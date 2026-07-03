// Link: https://leetcode.com/problems/house-robber-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: DP, take = best ending with robbing current, skip = best without
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        // circle: either skip the first house or skip the last
        return max(robLine(nums, 0, n - 2), robLine(nums, 1, n - 1));
    }

private:
    // linear house-robber on nums[lo..hi]
    int robLine(vector<int> &nums, int lo, int hi)
    {
        int take = 0, skip = 0;
        for (int i = lo; i <= hi; i++)
        {
            int newTake = skip + nums[i];
            skip = max(skip, take);
            take = newTake;
        }
        return max(take, skip);
    }
};
