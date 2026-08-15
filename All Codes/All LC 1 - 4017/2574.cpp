// Link: https://leetcode.com/problems/left-and-right-sum-differences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftSum(n, 0), rightSum(n, 0), result(n, 0);

        for (int i = 1; i < n; ++i)
            leftSum[i] = leftSum[i - 1] + nums[i - 1];

        for (int i = n - 2; i >= 0; --i)
            rightSum[i] = rightSum[i + 1] + nums[i + 1];

        for (int i = 0; i < n; ++i)
            result[i] = abs(leftSum[i] - rightSum[i]);

        return result;
    }
};
