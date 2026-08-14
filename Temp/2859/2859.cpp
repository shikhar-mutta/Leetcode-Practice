// Link: https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++)
            if (__builtin_popcount(i) == k) sum += nums[i];
        return sum;
    }
};
