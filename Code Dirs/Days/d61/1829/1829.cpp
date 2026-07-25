// Link: https://leetcode.com/problems/maximum-xor-for-each-query/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//    Approach:
//      1. We can use a variable to keep track of the xor of all the elements in the array.
//      2. We can iterate through the array from the end to the beginning and for each element, we can calculate the maximum xor by xoring the current xor with the mask of the maximum bit.
//      3. We can then update the current xor by xoring it with the current element and continue the process until we have processed all the elements in the array.
//      4. Finally, we can return the result array containing the maximum xor for each query.
class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int xorop = 0;
        for (int x : nums)
            xorop ^= x;
        int n = nums.size();
        vector<int> ans;
        int mask = (1 << maximumBit) - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans.push_back(xorop ^ mask);
            xorop ^= nums[i];
        }
        return ans;
    }
};