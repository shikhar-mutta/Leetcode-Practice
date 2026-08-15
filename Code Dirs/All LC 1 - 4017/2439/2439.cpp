// Link: https://leetcode.com/problems/minimize-maximum-of-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long prefixSum = 0;
        long long best = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            prefixSum += nums[i];
            long long need = (prefixSum + i) / (i + 1);
            best = max(best, need);
        }
        return (int)best;
    }
};
