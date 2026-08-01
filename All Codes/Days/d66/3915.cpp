// Link: https://leetcode.com/problems/maximum-sum-of-alternating-subsequence-with-distance-at-least-k/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: choose indices with consecutive gaps >= k whose values zigzag
// (alternate increase/decrease), maximizing the plain sum of chosen values.
// dp_inc[i]/dp_dec[i] = best sum of a valid zigzag ending at i where the
// last step was an increase/decrease. Transitions only look at indices
// j<=i-k with a smaller/larger value respectively, so maintain two Fenwick
// trees over coordinate-compressed values storing running maxima of
// dp_dec/dp_inc; before processing i, lazily insert index i-k (making all
// eligible j available), then query a prefix-max over the appropriate
// value range (below nums[i] for dp_inc, above for dp_dec via a reversed-
// rank tree) in O(log n).
class BIT {
    vector<long long> tree;
public:
    BIT(int n) : tree(n + 1, 0) {}
    void add(int i, long long val) {
        for (i++; i < (int)tree.size(); i += i & (-i)) tree[i] = max(tree[i], val);
    }
    long long query(int i) {
        long long res = 0;
        for (i++; i > 0; i -= i & (-i)) res = max(res, tree[i]);
        return res;
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sortedVals(nums);
        sort(sortedVals.begin(), sortedVals.end());
        sortedVals.erase(unique(sortedVals.begin(), sortedVals.end()), sortedVals.end());
        int m = sortedVals.size();
        auto rank = [&](int v) { return lower_bound(sortedVals.begin(), sortedVals.end(), v) - sortedVals.begin(); };

        BIT bit0(m), bit1(m); // bit0 stores dp_dec by rank, bit1 stores dp_inc by reversed rank
        vector<long long> dpInc(n, 0), dpDec(n, 0);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i - k >= 0) {
                int idx = rank(nums[i-k]);
                bit0.add(idx, dpDec[i-k]);
                bit1.add((m - 1) - idx, dpInc[i-k]);
            }
            int idx = rank(nums[i]);
            dpInc[i] = bit0.query(idx - 1) + nums[i];
            dpDec[i] = bit1.query(((m - 1) - idx) - 1) + nums[i];
            ans = max({ans, dpInc[i], dpDec[i]});
        }
        return ans;
    }
};
