// Link: https://leetcode.com/problems/split-array-with-equal-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
// Approach: fix middle cut j, for each valid i<j collect the common sum
// into a set, for each valid k>j check if its sum is in that set (two-set
// intersection technique for the classic 3-cut equal-sum split)
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 7) return false;
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        auto rangeSum = [&](int l, int r) { return prefix[r + 1] - prefix[l]; };

        for (int j = 3; j < n - 3; j++) {
            unordered_set<long long> sums;
            for (int i = 1; i < j - 1; i++) {
                if (rangeSum(0, i - 1) == rangeSum(i + 1, j - 1)) {
                    sums.insert(rangeSum(0, i - 1));
                }
            }
            for (int k = j + 2; k < n - 1; k++) {
                if (rangeSum(j + 1, k - 1) == rangeSum(k + 1, n - 1) && sums.count(rangeSum(j + 1, k - 1))) {
                    return true;
                }
            }
        }
        return false;
    }
};
