// Link: https://leetcode.com/problems/find-xor-beauty-of-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: XORing (nums[i] | nums[j]) & nums[k] over every ordered
// triple (i, j, k) simplifies, by symmetry (each term where i != j
// cancels out in pairs across the full triple sum), down to just the
// XOR of all elements in nums.
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int res = 0;
        for (int x : nums)
            res ^= x;
        return res;
    }
};
