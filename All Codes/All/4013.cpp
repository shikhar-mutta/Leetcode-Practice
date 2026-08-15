// Link: https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<long long> prefE(n + 1, 0), prefO(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefE[i + 1] = prefE[i] + (nums[i] % 2 == 0 ? 1 : 0);
            prefO[i + 1] = prefO[i] + (nums[i] % 2 == 0 ? 0 : 1);
        }

        vector<long long> f(n + 1);
        for (int k = 0; k <= n; k++) f[k] = (long long)(a + b) * prefE[k] - (long long)a * k;

        vector<int> start(n + 1);
        start[0] = 0;
        for (int k = 1; k <= n; k++) {
            if (prefO[k] == prefO[k - 1]) start[k] = start[k - 1];
            else start[k] = k;
        }

        vector<long long> sortedF(f.begin(), f.end());
        sort(sortedF.begin(), sortedF.end());
        sortedF.erase(unique(sortedF.begin(), sortedF.end()), sortedF.end());
        int m = sortedF.size();
        auto rankOf = [&](long long v) -> int {
            return (int)(lower_bound(sortedF.begin(), sortedF.end(), v) - sortedF.begin()) + 1;
        };

        vector<int> bit(m + 2, 0);
        auto update = [&](int pos) {
            for (; pos <= m; pos += pos & (-pos)) bit[pos]++;
        };
        auto query = [&](int pos) -> long long {
            long long s = 0;
            for (; pos > 0; pos -= pos & (-pos)) s += bit[pos];
            return s;
        };

        long long ans = 0;
        int inserted = 0;
        for (int r = 1; r <= n; r++) {
            int target = start[r];
            while (inserted < target) {
                update(rankOf(f[inserted]));
                inserted++;
            }
            int rk = rankOf(f[r]);
            long long total = inserted;
            long long lessCount = (rk - 1 >= 1) ? query(rk - 1) : 0;
            ans += total - lessCount;
        }
        return ans;
    }
};
