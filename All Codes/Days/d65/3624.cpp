// Link: https://leetcode.com/problems/number-of-integers-with-popcount-depth-equal-to-k-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int depthOf(long long x) {
        int d = 0;
        while (x != 1) {
            x = __builtin_popcountll(x);
            d++;
        }
        return d;
    }

    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n = nums.size();
        vector<vector<long long>> fen(6, vector<long long>(n + 1, 0));

        auto update = [&](int k, int i, long long delta) {
            for (i++; i <= n; i += i & (-i)) fen[k][i] += delta;
        };
        auto query = [&](int k, int i) {
            long long s = 0;
            for (; i > 0; i -= i & (-i)) s += fen[k][i];
            return s;
        };
        auto rangeQuery = [&](int k, int l, int r) {
            return query(k, r + 1) - query(k, l);
        };

        vector<int> curDepth(n);
        for (int i = 0; i < n; i++) {
            curDepth[i] = depthOf(nums[i]);
            update(curDepth[i], i, 1);
        }

        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int l = q[1], r = q[2], k = q[3];
                ans.push_back((int)rangeQuery(k, l, r));
            } else {
                int idx = q[1];
                long long val = q[2];
                update(curDepth[idx], idx, -1);
                curDepth[idx] = depthOf(val);
                update(curDepth[idx], idx, 1);
            }
        }

        return ans;
    }
};
