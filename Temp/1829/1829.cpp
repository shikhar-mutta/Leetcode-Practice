// Link: https://leetcode.com/problems/maximum-xor-for-each-query/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mask = (1 << maximumBit) - 1;
        int xorAll = 0;
        for (int x : nums) xorAll ^= x;

        vector<int> res;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            res.push_back(xorAll ^ mask);
            xorAll ^= nums[i];
        }
        return res;
    }
};
