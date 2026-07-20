// Link: https://leetcode.com/problems/count-the-number-of-fair-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n)
    // SC: O(1)
    //   Approach:
    //   1. Sort the nums array in ascending order.
    //   2. Define a helper function countLE(x) that counts the number of pairs (i, j) such that nums[i] + nums[j] <= x. This function uses a two-pointer approach to efficiently count the pairs.
    //   3. The main function countFairPairs(lower, upper) calculates the number of fair pairs by calling countLE(upper) and countLE(lower - 1) and taking the difference. This gives the count of pairs whose sums fall within the range [lower, upper].
    //   4. Return the final count of fair pairs.
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        auto countLE = [&](long long x)
        {
            long long cnt = 0;
            int l = 0, r = (int)nums.size() - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] <= x)
                {
                    cnt += r - l;
                    l++;
                }
                else
                    r--;
            }
            return cnt;
        };
        return countLE(upper) - countLE(lower - 1);
    }
};
