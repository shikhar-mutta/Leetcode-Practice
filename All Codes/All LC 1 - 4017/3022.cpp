// Link: https://leetcode.com/problems/minimize-or-of-remaining-elements-using-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(max(nums))). SC: O(1).
// Approach: Bit Manipulation
// 1. We will iterate through the bits from the most significant bit to the least significant bit.
// 2. For each bit, we will check if we can make all the numbers have that bit set to 1 by performing the operations.
// 3. If we can make all the numbers have that bit set to 1, we will update the mask to include that bit. Otherwise, we will add that bit to the result.
// 4. Finally, we will return the result.
class Solution
{
public:
    int minOrAfterOperations(vector<int> &nums, int k)
    {
        int res = 0, mask = 0;

        for (int i = 29; i >= 0; i--)
        {
            int next = mask | 1 << i;
            int sum = 0, cur = next;

            for (auto &c : nums)
            {
                cur &= c;
                sum += !cur;
                if (!cur)
                    cur = next;
            }

            if (nums.size() - sum <= k)
                mask = next;
            else
                res |= 1 << i;
        }

        return res;
    }
};