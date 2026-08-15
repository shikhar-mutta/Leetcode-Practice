// Link: https://leetcode.com/problems/minimum-swaps-to-avoid-forbidden-values/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
//  Approach: The problem can be solved using a greedy approach. We can keep track of the current value and the number of swaps needed to avoid forbidden values. We can iterate through the nums and forbidden arrays and check if the current value is equal to the forbidden value. If it is, we can increment the count of swaps needed and update the current value to the next value in the nums array. We can also keep track of the number of times the current value is equal to the forbidden value and return the maximum of the count of swaps needed and the number of times the current value is equal to the forbidden value divided by 2 (since we can swap two values at a time).
class Solution
{
public:
    int minSwaps(vector<int> &nums, vector<int> &forbidden)
    {
        int N = size(nums), cnt = 0, d = 0, act = 0;
        for (int i = 0; i < N; ++i)
        {
            d += (((unsigned)((act ^ nums[i]) - 1) & 0x80000000u) >> 30) - 1;
            if (d < 0)
                act = nums[i], d = 1;
        }
        for (int i = 0; i < N; ++i)
        {
            d += (((unsigned)((act ^ forbidden[i]) - 1) & 0x80000000u) >> 30) -
                 1;
            if (d < 0)
                act = forbidden[i], d = 1;
        }
        for (int i = 0; i < N; ++i)
            cnt += (((unsigned)(act ^ nums[i]) - 1) >> 31) +
                   (((unsigned)(act ^ forbidden[i]) - 1) >> 31);
        if (cnt > N)
            return -1;

        cnt = 0;
        d = 0;
        for (int i = 0; i < N; ++i)
        {
            if (nums[i] == forbidden[i])
            {
                ++cnt;
                d +=
                    (((unsigned)((act ^ nums[i]) - 1) & 0x80000000u) >> 30) - 1;
                if (d < 0)
                    act = nums[i], d = 1;
            }
        }

        d = 0;
        for (int i = 0; i < N; ++i)
            if (nums[i] == act && act == forbidden[i])
                ++d;
        return max(d, (cnt + 1) / 2);
    }
};