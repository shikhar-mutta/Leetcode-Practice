// Link: https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int movesToMakeZigzag(vector<int> &nums)
    {
        int n = nums.size();
        int cost[2] = {0, 0}; // cost[0]: even indices are valleys, cost[1]: odd

        for (int i = 0; i < n; i++)
        {
            int left = (i > 0) ? nums[i - 1] : INT_MAX;
            int right = (i < n - 1) ? nums[i + 1] : INT_MAX;
            int need = nums[i] - min(left, right) + 1;
            cost[i % 2] += max(0, need);
        }
        return min(cost[0], cost[1]);
    }
};