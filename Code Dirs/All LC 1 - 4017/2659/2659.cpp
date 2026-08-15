// Link: https://leetcode.com/problems/make-array-empty/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> bit;
    int n;
    void update(int i, int delta) {
        for (++i; i <= n; i += i & (-i)) bit[i] += delta;
    }
    int query(int i) {
        int s = 0;
        for (++i; i > 0; i -= i & (-i)) s += bit[i];
        return s;
    }
    int rangeSum(int l, int r) {
        if (l > r) return 0;
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }

public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        n = nums.size();
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++) update(i, 1);

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) { return nums[a] < nums[b]; });

        long long ans = 0;
        int prev = n - 1;
        for (int i = 0; i < n; i++) {
            int cur = order[i];
            int between;
            if (cur > prev) between = rangeSum(prev + 1, cur - 1);
            else between = rangeSum(prev + 1, n - 1) + rangeSum(0, cur - 1);
            ans += between + 1;
            update(cur, -1);
            prev = cur;
        }
        return ans;
    }
};
