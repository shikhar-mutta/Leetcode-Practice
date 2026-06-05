// Link: https://leetcode.com/problems/semi-ordered-permutation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n). SC: O(1).
    int semiOrderedPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int pos1 = -1, posn = -1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 1)
                pos1 = i;
            else if (nums[i] == n)
                posn = i;
        }
        return pos1 + (n - 1 - posn) - (pos1 > posn ? 1 : 0);
    }
};
