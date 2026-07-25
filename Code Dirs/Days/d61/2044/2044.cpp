// Link: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^n), SC: O(n)
// Approach:
// 1. We can use backtracking to generate all the subsets of the given array.
// 2. We can keep track of the maximum bitwise OR value and the count of subsets that have the maximum bitwise OR value.
// 3. We can use a helper function to perform the backtracking and calculate the bitwise OR value of each subset.
// 4. If the bitwise OR value of the current subset is equal to the maximum bitwise OR value, we increment the count.
// 5. If the bitwise OR value of the current subset is greater than the maximum bitwise OR value, we update the maximum bitwise OR value and reset the count to 1.
// 6. We repeat this process until we have generated all the subsets and return the count of subsets that have the maximum bitwise OR value.
class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int maxOR = 0;
        for (int num : nums)
        {
            maxOR |= num;
        }
        return backtrack(nums, maxOR, 0, 0);
    }

private:
    int backtrack(vector<int> &nums, int maxOR, int index, int currentOR)
    {
        if (index == nums.size())
        {
            return currentOR == maxOR ? 1 : 0;
        }

        if (currentOR == maxOR)
        {
            return 1 << (nums.size() - index);
        }

        return backtrack(nums, maxOR, index + 1, currentOR | nums[index]) +
               backtrack(nums, maxOR, index + 1, currentOR);
    }
};