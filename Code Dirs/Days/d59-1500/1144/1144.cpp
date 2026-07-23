// Link: https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the array
    // SC: O(1)
    // Approach:
    //   1. We can make the array zigzag in two ways:
    //      a. Make all even indexed elements greater than their adjacent odd indexed elements.
    //      b. Make all odd indexed elements greater than their adjacent even indexed elements.
    //   2. For each element, we calculate the number of moves required to make it less than its adjacent elements. If the element is already less than its adjacent elements, no moves are required. Otherwise, we calculate the difference and add 1 to it to make it less than its adjacent elements.
    //   3. We keep track of the total moves required for both scenarios and return the minimum of the two.
    //   4. Finally, we return the minimum of the two total moves.
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