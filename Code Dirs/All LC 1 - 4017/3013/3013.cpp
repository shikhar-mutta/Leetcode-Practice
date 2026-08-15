// Link: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    multiset<long long> small, large;
    long long sumSmall = 0;
    int target; // desired size of `small`

    void rebalance() {
        while ((int)small.size() < target && !large.empty()) {
            auto it = large.begin();
            small.insert(*it);
            sumSmall += *it;
            large.erase(it);
        }
        while ((int)small.size() > target) {
            auto it = prev(small.end());
            large.insert(*it);
            sumSmall -= *it;
            small.erase(it);
        }
        // ensure small holds the smallest `target` elements overall
        while (!small.empty() && !large.empty() && *prev(small.end()) > *large.begin()) {
            long long a = *prev(small.end());
            long long b = *large.begin();
            small.erase(prev(small.end()));
            sumSmall -= a;
            large.erase(large.begin());
            small.insert(b);
            sumSmall += b;
            large.insert(a);
        }
    }

    void addVal(long long v) {
        large.insert(v);
        rebalance();
    }

    void removeVal(long long v) {
        auto it = small.find(v);
        if (it != small.end()) {
            sumSmall -= v;
            small.erase(it);
        } else {
            it = large.find(v);
            large.erase(it);
        }
        rebalance();
    }

    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int need = k - 2;
        target = need;

        // pool for L = 1: indices [2, min(1+dist, n-1)]
        int poolHi = min(1 + dist, n - 1);
        for (int i = 2; i <= poolHi; i++) addVal(nums[i]);

        long long best = LLONG_MAX;

        for (int L = 1; L <= n - 1; L++) {
            int poolSize = (int)(small.size() + large.size());
            if (poolSize >= need) {
                best = min(best, (long long)nums[L] + sumSmall);
            }
            // transition to L+1
            int nextL = L + 1;
            if (nextL > n - 1) break;
            if (nextL <= poolHi) removeVal(nums[nextL]);
            int newRight = nextL + dist;
            if (newRight <= n - 1 && newRight > poolHi) {
                addVal(nums[newRight]);
                poolHi = newRight;
            }
        }
        return nums[0] + best;
    }
};
