// Link: https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int evenNumberBitwiseORs(vector<int> &nums)
    {
        int res = 0;
        for (auto it : nums)
            if (it % 2 == 0)
                res |= it;
        return res;
    }
};
