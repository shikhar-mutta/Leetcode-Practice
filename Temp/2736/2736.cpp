// Link: https://leetcode.com/problems/maximum-sum-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        vector<int> pairIdx(n);
        iota(pairIdx.begin(), pairIdx.end(), 0);
        sort(pairIdx.begin(), pairIdx.end(), [&](int a, int b) { return nums1[a] > nums1[b]; });

        int q = queries.size();
        vector<int> qIdx(q);
        iota(qIdx.begin(), qIdx.end(), 0);
        sort(qIdx.begin(), qIdx.end(), [&](int a, int b) { return queries[a][0] > queries[b][0]; });

        // coordinate compress nums2 values (ascending)
        vector<int> sortedVals(nums2.begin(), nums2.end());
        sort(sortedVals.begin(), sortedVals.end());
        sortedVals.erase(unique(sortedVals.begin(), sortedVals.end()), sortedVals.end());
        int sz = sortedVals.size();
        auto compress = [&](int v) {
            return lower_bound(sortedVals.begin(), sortedVals.end(), v) - sortedVals.begin();
        };

        // Fenwick tree for suffix-max: tree indexed by (sz - 1 - compressedIdx) for prefix-max semantics
        vector<long long> tree(sz + 1, -1);
        auto update = [&](int pos, long long val) {
            for (++pos; pos <= sz; pos += pos & (-pos)) tree[pos] = max(tree[pos], val);
        };
        auto query = [&](int pos) -> long long {
            long long res = -1;
            for (++pos; pos > 0; pos -= pos & (-pos)) res = max(res, tree[pos]);
            return res;
        };

        vector<int> ans(q, -1);
        int p = 0;

        for (int qi : qIdx) {
            int x = queries[qi][0], y = queries[qi][1];
            while (p < n && nums1[pairIdx[p]] >= x) {
                int idx = pairIdx[p];
                long long sum = (long long)nums1[idx] + nums2[idx];
                int compIdx = compress(nums2[idx]);
                int revIdx = sz - 1 - compIdx; // reversed so suffix-max becomes prefix-max
                update(revIdx, sum);
                p++;
            }
            int yComp = lower_bound(sortedVals.begin(), sortedVals.end(), y) - sortedVals.begin();
            if (yComp < sz) {
                int revBound = sz - 1 - yComp; // query prefix [0..revBound] in reversed indexing
                long long res = query(revBound);
                if (res != -1) ans[qi] = (int)res;
            }
        }
        return ans;
    }
};
