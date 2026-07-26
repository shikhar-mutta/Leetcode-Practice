// Link: https://leetcode.com/problems/minimum-size-subarray-in-infinite-array/description/
/*
Approach: Since array repeats infinitely, calculate total_sum of array. Using sliding window
          with prefix sum map: iterate through extended array (enough copies), track cumulative
          sums in map. For each position, check if (current_sum - target) exists in map.
          Number of complete cycles + remaining subarray length gives answer.
TC: O(n) - Single pass through array with HashMap operations O(1)
SC: O(n) - HashMap stores at most n prefix sums
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSizeSubarray(vector<int> &nums, int target)
    {
        long long total_sum = 0;
        for (int num : nums)
        {
            total_sum += num;
        }

        if (target % total_sum == 0)
        {
            // Check if we can achieve target using complete cycles
            long long sum = 0;
            for (int num : nums)
            {
                sum += num;
                if (sum == target)
                    return nums.size();
            }
            return -1;
        }

        int n = nums.size();
        int result = INT_MAX;
        long long current_sum = 0;
        unordered_map<long long, int> sum_map;
        sum_map[0] = -1;

        // We need at most 2 cycles of the array to find the answer
        for (int i = 0; i < 2 * n; i++)
        {
            current_sum += nums[i % n];

            // Find if there's a previous sum such that current_sum - previous_sum = target
            if (sum_map.find(current_sum - target) != sum_map.end())
            {
                int len = i - sum_map[current_sum - target];
                result = min(result, len);
            }

            sum_map[current_sum] = i;
        }

        return result == INT_MAX ? -1 : result;
    }
};
