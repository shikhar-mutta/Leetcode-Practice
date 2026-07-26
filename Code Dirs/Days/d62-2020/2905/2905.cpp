// Link: https://leetcode.com/problems/find-indices-with-index-and-value-difference-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: scan j from indexDifference to n-1 and maintain the indices of
// minimum and maximum nums values among all valid i <= j-indexDifference.
// If nums[j] differs enough from either extreme, that pair satisfies both
// conditions; otherwise no valid pair exists.
class Solution
{
public:
    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
    {
        int n = nums.size();
        int minIdx = 0;
        int maxIdx = 0;

        for (int j = indexDifference; j < n; ++j)
        {
            int candidate = j - indexDifference;

            if (nums[candidate] < nums[minIdx])
            {
                minIdx = candidate;
            }
            if (nums[candidate] > nums[maxIdx])
            {
                maxIdx = candidate;
            }

            if (abs(nums[j] - nums[minIdx]) >= valueDifference)
            {
                return {minIdx, j};
            }
            if (abs(nums[j] - nums[maxIdx]) >= valueDifference)
            {
                return {maxIdx, j};
            }
        }

        return {-1, -1};
    }
};
