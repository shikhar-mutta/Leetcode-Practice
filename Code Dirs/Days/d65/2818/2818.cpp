// Link: https://leetcode.com/problems/apply-operations-to-maximize-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log(maxVal) + N log N), SC: O(N)
// Approach: compute each number's distinct-prime-factor count (its "prime score"). Using a
// monotonic stack, find for each index the range where it's the maximum prime score (strict on
// one side, non-strict on the other, to avoid double counting ties); that range size is how many
// subarrays would pick it as the operand. Sort indices by value descending, greedily spend the
// k operations on the highest-value elements first (fast power for the exponent).
class Solution {
public:
    const long long MOD = 1e9+7;

    long long power(long long b, long long e) {
        long long r = 1; b %= MOD;
        while (e > 0) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
        return r;
    }

    int maximumScore(vector<int>& nums, int k_) {
        long long k = k_;
        int n = nums.size();
        vector<int> primeScore(n, 0);
        for (int i = 0; i < n; i++) {
            int x = nums[i], cnt = 0;
            for (int p = 2; (long long)p * p <= x; p++) {
                if (x % p == 0) { cnt++; while (x % p == 0) x /= p; }
            }
            if (x > 1) cnt++;
            primeScore[i] = cnt;
        }

        vector<int> left(n), right(n);
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && primeScore[stk.back()] < primeScore[i]) stk.pop_back();
            left[i] = stk.empty() ? -1 : stk.back();
            stk.push_back(i);
        }
        stk.clear();
        for (int i = n-1; i >= 0; i--) {
            while (!stk.empty() && primeScore[stk.back()] <= primeScore[i]) stk.pop_back();
            right[i] = stk.empty() ? n : stk.back();
            stk.push_back(i);
        }

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) { return nums[a] > nums[b]; });

        long long ans = 1;
        for (int i : order) {
            if (k <= 0) break;
            long long count = (long long)(i - left[i]) * (right[i] - i);
            long long use = min(count, k);
            ans = ans * power(nums[i], use) % MOD;
            k -= use;
        }
        return (int)ans;
    }
};
