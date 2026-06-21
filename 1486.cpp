// Link: https://leetcode.com/problems/xor-operation-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int xorOperation(int n, int start)
    {
        int res = 0;
        for (int i = 0; i < n; ++i)
            res ^= start + 2 * i;
        return res;
    }
};
