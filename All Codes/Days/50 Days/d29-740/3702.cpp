// Link: https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int longestSubsequence(vector<int> &nums)
    {
        int n = nums.size(), total = 0;
        bool allZero = true;
        for (int x : nums)
        {
            total ^= x;
            if (x != 0)
                allZero = false;
        }
        // Whole array already works.
        if (total != 0)
            return n;
        // total == 0: if everything is 0, no subsequence can be non-zero.
        if (allZero)
            return 0;
        // Drop one non-zero element to break the zero XOR.
        return n - 1;
    }
};
