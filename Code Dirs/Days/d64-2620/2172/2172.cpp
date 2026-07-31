// Link: https://leetcode.com/problems/maximum-and-sum-of-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 3^m)  SC: O(3^m)
//  Approach: We can use dynamic programming to solve this problem. We can represent the state of the slots using a base-3 number, where each digit represents the number of elements in that slot. We can then iterate through the elements of the array and for each element, we can try to place it in each of the slots and update the state accordingly. We can use a dp array to store the maximum AND sum for each state. Finally, we can return the maximum AND sum for the state where all elements have been placed in the slots.
class Solution
{
public:
    int maximumANDSum(vector<int> &nums, int numSlots)
    {
        int n = nums.size();
        vector<int> pow3(numSlots + 1);
        pow3[0] = 1;
        for (int i = 1; i <= numSlots; i++)
            pow3[i] = pow3[i - 1] * 3;
        int total = pow3[numSlots];
        vector<int> dp(total, -1);
        dp[0] = 0;
        int best = 0;
        for (int mask = 0; mask < total; mask++)
        {
            if (dp[mask] < 0)
                continue;
            int filled = 0, m = mask;
            for (int s = 0; s < numSlots; s++)
            {
                filled += m % 3;
                m /= 3;
            }
            if (filled >= n)
            {
                best = max(best, dp[mask]);
                continue;
            }
            int val = nums[filled];
            int m2 = mask;
            for (int s = 0; s < numSlots; s++)
            {
                int digit = (mask / pow3[s]) % 3;
                if (digit < 2)
                {
                    int nmask = mask + pow3[s];
                    int cand = dp[mask] + (val & (s + 1));
                    if (cand > dp[nmask])
                        dp[nmask] = cand;
                }
            }
        }
        for (int mask = 0; mask < total; mask++)
            best = max(best, dp[mask]);
        return best;
    }
};
