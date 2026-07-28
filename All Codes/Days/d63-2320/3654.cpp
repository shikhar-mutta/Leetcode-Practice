// Link: https://leetcode.com/problems/minimum-sum-after-divisible-sum-deletions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(k)
//  Approach: Use a map to track the minimum sum for each remainder class.
//  For each number, update the current remainder and calculate the potential new sum. Keep track of the minimum sum for each remainder class to ensure that we can always find the optimal solution.
//  Finally, return the minimum sum for the remainder class that is divisible by k.
class Solution
{
public:
    long long minArraySum(vector<int> &nums, int k)
    {
        unsigned long long remainder_map[k];
        for (int i = 0; i < k; ++i)
        {
            remainder_map[i] = std::numeric_limits<unsigned long long>::max();
        }

        remainder_map[0] = 0;

        long long res[nums.size()];
        int curr_reminder = 0;

        // First iteration manual to avoide looking back into buffer overrun
        curr_reminder += nums[0] % k;
        res[0] = curr_reminder == 0 ? 0 : nums[0];
        remainder_map[curr_reminder] = res[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            curr_reminder = (curr_reminder + nums[i]) % k;

            unsigned long long not_in_sequence_score = res[i - 1] + nums[i];

            // Searching for sequence that has the same reminder - meaning it can be shrinked with
            remainder_map[curr_reminder] = std::min(remainder_map[curr_reminder], not_in_sequence_score);
            res[i] = remainder_map[curr_reminder];
        }

        return res[nums.size() - 1];
    }
};