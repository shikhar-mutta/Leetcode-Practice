// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) – single pass to XOR all elements
// SC: O(1) – one variable x
// Approach: XOR all elements to get the current total x. Each operation flips
// exactly one bit in one element, flipping that bit in the total XOR. So the
// minimum operations = number of bit positions where x and k differ =
// popcount(x ^ k).
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int x = 0;
        for (int n : nums)
            x ^= n;
        return __builtin_popcount(x ^ k);
    }
};