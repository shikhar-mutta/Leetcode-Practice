// Link: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        for (int x : nums) maxOr |= x;
        int count = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            int orVal = 0;
            for (int i = 0; i < n; i++) if (mask & (1 << i)) orVal |= nums[i];
            if (orVal == maxOr) count++;
        }
        return count;
    }
};
