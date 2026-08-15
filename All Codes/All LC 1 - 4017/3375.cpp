// Link: https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int minOperations(vector<int> &nums, int k)
    {
        bitset<101> b;
        for (int x : nums)
        {
            if (x < k)
                return -1;
            if (x > k)
                b.set(x);
        }
        return b.count();
    }
};
