// Link: https://leetcode.com/problems/maximum-balanced-subsequence-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> keys(n);
        for (int i = 0; i < n; i++) keys[i] = (long long)nums[i] - i;
        vector<long long> sortedKeys(keys);
        sort(sortedKeys.begin(), sortedKeys.end());
        sortedKeys.erase(unique(sortedKeys.begin(), sortedKeys.end()), sortedKeys.end());
        int sz = sortedKeys.size();

        vector<long long> bit(sz + 1, LLONG_MIN);
        auto update = [&](int i, long long val) {
            for (i++; i <= sz; i += i & (-i)) bit[i] = max(bit[i], val);
        };
        auto query = [&](int i) {
            long long res = LLONG_MIN;
            for (i++; i > 0; i -= i & (-i)) res = max(res, bit[i]);
            return res;
        };

        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            int pos = lower_bound(sortedKeys.begin(), sortedKeys.end(), keys[i]) - sortedKeys.begin();
            long long best = query(pos);
            long long dp = nums[i] + max(0LL, best == LLONG_MIN ? 0LL : best);
            ans = max(ans, dp);
            update(pos, dp);
        }
        return ans;
    }
};
