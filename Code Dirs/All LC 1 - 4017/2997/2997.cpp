// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for (int v : nums) x ^= v;
        return __builtin_popcount(x ^ k);
    }
};
