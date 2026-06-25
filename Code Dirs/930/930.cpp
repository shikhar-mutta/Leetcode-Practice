// Link: https://leetcode.com/problems/binary-subarrays-with-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        // exactly(goal) = atMost(goal) - atMost(goal-1)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0; // can't have negative sum
        int left = 0, sum = 0, res = 0;
        for (int right = 0; right < (int)nums.size(); right++)
        {
            sum += nums[right];
            while (sum > goal)
                sum -= nums[left++];
            res += right - left + 1; // all subarrays ending at right
        }
        return res;
    }
};
