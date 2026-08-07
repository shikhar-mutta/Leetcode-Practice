// Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(32n)  SC: O(n)
// Approach: build the answer bit by bit from MSB; at each step, assume the
// bit can be set and check via a prefix hash set whether some pair achieves it
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXor = 0, mask = 0;
        for (int bit = 31; bit >= 0; bit--) {
            mask |= (1 << bit);
            unordered_set<int> prefixes;
            for (int x : nums) prefixes.insert(x & mask);

            int candidate = maxXor | (1 << bit);
            for (int p : prefixes) {
                if (prefixes.count(candidate ^ p)) {
                    maxXor = candidate;
                    break;
                }
            }
        }
        return maxXor;
    }
};
