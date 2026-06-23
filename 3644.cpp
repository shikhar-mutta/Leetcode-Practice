// Link: https://leetcode.com/problems/maximum-k-to-sort-a-permutation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int sortPermutation(vector<int> &nums)
    // Each misplaced value v must be swapped, and any swap forces K to be a
    // submask of v. So the largest valid K is the AND of all misplaced values. 
    {
        int ans = -1; // all ones, identity for AND
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i] != i)
                ans &= nums[i];
        return ans == -1 ? 0 : ans; // already sorted -> 0
    }
};
