// Link: https://leetcode.com/problems/concatenated-divisibility/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;
    vector<int> nums_;
    int n, k_;
    vector<int> mult; // 10^digits(nums[i]) % k

    bool canComplete(int mask, int r) {
        if (mask == (1 << n) - 1) return r == 0;
        int& m = memo[mask][r];
        if (m != -1) return m;
        m = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            int newR = (int)(((long long)r * mult[i] + nums_[i]) % k_);
            if (canComplete(mask | (1 << i), newR)) { m = 1; break; }
        }
        return m;
    }

    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        n = nums.size();
        k_ = k;
        nums_ = nums;
        mult.resize(n);
        for (int i = 0; i < n; i++) {
            int p = 1;
            int x = nums[i];
            while (x > 0) { p = (p * 10) % k; x /= 10; }
            mult[i] = p;
        }
        memo.assign(1 << n, vector<int>(k, -1));

        if (!canComplete(0, 0)) return {};

        vector<int> order;
        int mask = 0, r = 0;
        for (int step = 0; step < n; step++) {
            vector<int> candidates;
            for (int i = 0; i < n; i++) if (!(mask & (1 << i))) candidates.push_back(i);
            sort(candidates.begin(), candidates.end(), [&](int a, int b) { return nums[a] < nums[b]; });
            for (int i : candidates) {
                int newR = (int)(((long long)r * mult[i] + nums[i]) % k);
                if (canComplete(mask | (1 << i), newR)) {
                    order.push_back(nums[i]);
                    mask |= (1 << i);
                    r = newR;
                    break;
                }
            }
        }
        return order;
    }
};
