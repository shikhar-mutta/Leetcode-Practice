// Link: https://leetcode.com/problems/check-if-it-is-a-good-array/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log(maxVal))  SC: O(1)
// Approach: by Bezout's identity, some integer linear combination of
// the numbers equals 1 iff gcd(nums) == 1. So just fold gcd across the
// array and check if it reaches 1.
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for (int x : nums) g = gcd(g, x);
        return g == 1;
    }
};
