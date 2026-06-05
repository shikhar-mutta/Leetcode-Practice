// Link: https://leetcode.com/problems/minimum-operations-to-collect-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Use Bitset to keep track of the unique numbers from 1 to k.
    // TC: O(n), SC: O(k)
    int minOperations(vector<int> &nums, int k)
    {
        bitset<51> bs;
        int count = 0, n = nums.size();
        for (int i = n - 1; i >= 0; i--)
        {
            count++;
            // num <= k, then set the bit at index num
            if (nums[i] <= k)
                bs.set(nums[i]);
            // if all bits from 1 to k are set, then return the count
            if ((int)bs.count() == k)
                return count;
        }
        return count;
    }
};
