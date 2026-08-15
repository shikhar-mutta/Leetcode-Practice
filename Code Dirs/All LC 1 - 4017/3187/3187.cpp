// Link: https://leetcode.com/problems/peaks-in-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bit;
    int n;
    void update(int i, int delta) {
        for (i++; i <= n; i += i & (-i)) bit[i] += delta;
    }
    int query(int i) { // sum [0,i]
        if (i < 0) return 0;
        int s = 0;
        for (i++; i > 0; i -= i & (-i)) s += bit[i];
        return s;
    }
    int rangeQuery(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        bit.assign(n + 1, 0);
        vector<bool> isPeak(n, false);
        auto checkPeak = [&](int i) {
            return i >= 1 && i <= n - 2 && nums[i] > nums[i-1] && nums[i] > nums[i+1];
        };
        for (int i = 1; i <= n - 2; i++) {
            if (checkPeak(i)) { isPeak[i] = true; update(i, 1); }
        }

        vector<int> res;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int l = q[1], r = q[2];
                int lo = max(l + 1, 1), hi = min(r - 1, n - 2);
                res.push_back(rangeQuery(lo, hi));
            } else {
                int idx = q[1], val = q[2];
                nums[idx] = val;
                for (int i = idx - 1; i <= idx + 1; i++) {
                    if (i < 1 || i > n - 2) continue;
                    bool nowPeak = checkPeak(i);
                    if (nowPeak != isPeak[i]) {
                        update(i, nowPeak ? 1 : -1);
                        isPeak[i] = nowPeak;
                    }
                }
            }
        }
        return res;
    }
};
