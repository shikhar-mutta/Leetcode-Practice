// Link: https://leetcode.com/problems/split-array-with-same-average/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * maxVal)  SC: O(n * maxVal)
//  Approach: for each possible subset size k (1 to n/2), check if there exists a
//  subset of size k with sum = (totalSum * k) / n. Use backtracking to find such
//  a subset.
//  Note: The sumPossible function uses recursion to explore all combinations of
//  elements in the nums array to find a subset of size numReq that sums up to
//  the specified sum. It checks various conditions to prune the search space and
//  avoid unnecessary computations.
class Solution
{
    bool sumPossible(vector<int> &nums, int sum, int numReq, int idx = 0)
    {
        if (sum == 0 && numReq == 0)
        {
            return true;
        }
        if (idx >= nums.size() || sum < 0 || numReq <= 0 ||
            sum - numReq * nums[idx] > 0 || sum - numReq * nums.back() < 0)
        {
            return false;
        }
        for (int j = idx; j < nums.size(); ++j)
        {
            if (sumPossible(nums, sum - nums[j], numReq - 1, j + 1))
            {
                return true;
            }
        }
        return false;
    }

public:
    bool splitArraySameAverage(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.rbegin(), nums.rend());
        for (int split = 1; split * 2 <= n; split++)
        {
            if ((sum * split) % n != 0)
                continue;
            int reqSum = (sum * split) / n;
            cout << split << " " << reqSum << endl;
            if (sumPossible(nums, reqSum, split) == 1)
            {
                return true;
            }
        }
        return false;
    }
};