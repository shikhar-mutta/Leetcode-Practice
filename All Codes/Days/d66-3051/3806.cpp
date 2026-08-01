// Link: https://leetcode.com/problems/maximum-bitwise-and-after-increment-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n + 32 * n)  SC: O(1)
//  Approach: We can use a greedy approach to solve this problem. We can start from the highest bit and try to set it to 1. If we can set it to 1, we will do it and move to the next bit. If we cannot set it to 1, we will move to the next bit without changing the current bit. We will repeat this process until we reach the lowest bit. The final answer will be the maximum AND value we can get after performing the operations. We will also keep track of the number of operations we have performed and the number of elements we have used to set the bits. If we have used more than m elements or performed more than k operations, we will stop and return the current answer.
class Solution
{
public:
    int maximumAND(vector<int> &nums, int k, int m)
    {
        int n = size(nums);
        sort(begin(nums), end(nums), greater{});
        int bit = 1 << bit_width<unsigned>(max(nums[0], k));
        int len = n, ans = 0;
        while (bit)
        {
            int i = 0;
            while (i < len && nums[i] & bit)
                nums[i] &= ~bit, ++i;
            int j = i, ops = 0;
            while (j < m && ops <= k)
                ops += bit - nums[j], ++j;
            if (ops <= k)
            {
                ans |= bit, k -= ops, len = j;
                fill(begin(nums) + i, begin(nums) + len, 0);
            }
            else
            {
                inplace_merge(begin(nums), begin(nums) + i, begin(nums) + len,
                              greater{});
            }
            bit >>= 1;
        }
        return ans;
    }
};
