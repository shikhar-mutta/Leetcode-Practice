// Link: https://leetcode.com/problems/partition-array-into-two-equal-product-subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int>* numsP;
    long long target_;

    bool dfs(int idx, long long product, int count) {
        int nn = n;
        vector<int>& nums = *numsP;
        if (product == target_ && count > 0 && count < nn) return true;
        if (idx == nn || product > target_) return false;
        if (dfs(idx + 1, product * nums[idx], count + 1)) return true;
        if (dfs(idx + 1, product, count)) return true;
        return false;
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
        n = nums.size();
        numsP = &nums;
        target_ = target;

        __int128 total = 1;
        for (int x : nums) total *= x;
        __int128 targetSq = (__int128)target * (__int128)target;
        if (total != targetSq) return false;

        return dfs(0, 1, 0);
    }
};
