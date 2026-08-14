// Link: https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        vector<int> ones;
        for (int i = 0; i < (int)nums.size(); i++) if (nums[i] == 1) ones.push_back(i);
        if (ones.empty()) return 0;

        long long result = 1;
        for (int i = 1; i < (int)ones.size(); i++) {
            result = result * (ones[i] - ones[i-1]) % MOD;
        }
        return (int)result;
    }
};
