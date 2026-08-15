// Link: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct BIT {
        int n;
        vector<long long> b1, b2;
        BIT(int n) : n(n), b1(n + 2, 0), b2(n + 2, 0) {}
        void upd(vector<long long>& b, int i, long long delta) {
            for (; i <= n; i += i & (-i)) b[i] += delta;
        }
        void rangeUpdate(int l, int r, long long val) {
            upd(b1, l, val);
            upd(b1, r + 1, -val);
            upd(b2, l, val * (l - 1));
            upd(b2, r + 1, -val * r);
        }
        long long q(vector<long long>& b, int i) {
            long long s = 0;
            for (; i > 0; i -= i & (-i)) s += b[i];
            return s;
        }
        long long prefixSum(int x) {
            return q(b1, x) * x - q(b2, x);
        }
        long long rangeSum(int l, int r) {
            if (l > r) return 0;
            return prefixSum(r) - prefixSum(l - 1);
        }
    };

    int sumCounts(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        BIT bit(n);
        unordered_map<int, int> lastPos;
        long long total = 0, ans = 0;
        for (int r = 0; r < n; r++) {
            int last = lastPos.count(nums[r]) ? lastPos[nums[r]] : -1;
            lastPos[nums[r]] = r;
            int lo = last + 2, hi = r + 1; // 1-indexed range [last+1, r] -> [last+2, r+1]
            long long rangeSum = bit.rangeSum(lo, hi);
            long long cnt = hi - lo + 1;
            total = (total + 2 * (rangeSum % MOD) + cnt) % MOD;
            bit.rangeUpdate(lo, hi, 1);
            ans = (ans + total) % MOD;
        }
        return (int)ans;
    }
};
