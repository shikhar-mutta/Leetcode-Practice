// Link: https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k), SC: O(1)
//   Approach:
//   1. We can keep track of the best element we can get by removing some elements and keeping one exposed, or by removing exactly k elements and exposing the element at index k.
//   2. We can return the maximum of these two options as the answer.
class Solution
{
public:
    int maximumTop(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k == 0)
            return nums.empty() ? -1 : nums[0];
        if (n == 1)
            return (k % 2 == 1) ? -1 : nums[0];

        // best among first k-1 elements (can remove some, keep one exposed)
        int best = -1;
        for (int i = 0; i < min(k - 1, n); ++i)
            best = max(best, nums[i]);

        // or remove exactly k, exposing element at index k
        if (k < n)
            best = max(best, nums[k]);

        return best;
    }
};
