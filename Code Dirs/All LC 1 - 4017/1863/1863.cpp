// Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int orAll = 0;
        for (int x : nums) orAll |= x;
        return orAll << (nums.size() - 1);
    }
};
