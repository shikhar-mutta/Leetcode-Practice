// Link: https://leetcode.com/problems/longest-alternating-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC:O(n^2) SC: O(1)
    int alternatingSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = -1; // Initialize ans to -1 to handle the case when no valid subarray is found
        for (int i = 0; i < n - 1; i++)
            if (nums[i + 1] - nums[i] == 1)
            {
                int j = i + 1; // j % 2 != i % 2 imp cond.
                while (j < n - 1 && nums[j + 1] - nums[j] == (j % 2 != i % 2 ? -1 : 1))
                    j++;
                ans = max(ans, j - i + 1);
            }
        return ans;
    }
};
