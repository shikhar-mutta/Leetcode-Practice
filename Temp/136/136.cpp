// Link: https://leetcode.com/problems/single-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: XOR all numbers together; paired duplicates cancel out, leaving the single number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int x : nums) res ^= x;
        return res;
    }
};
