// Link: https://leetcode.com/problems/minimum-array-changes-to-make-differences-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(k + 2, 0);
        int pairs = n / 2;
        diff[0] += 2 * pairs;
        for (int i = 0; i < pairs; i++) {
            int a = nums[i], b = nums[n - 1 - i];
            int lo = min(a, b), hi = max(a, b);
            int R = max(hi, k - lo);
            diff[0] -= 1;
            diff[R + 1] += 1;
            int d0 = hi - lo;
            diff[d0] -= 1;
            diff[d0 + 1] += 1;
        }
        int best = INT_MAX, cur = 0;
        for (int d = 0; d <= k; d++) {
            cur += diff[d];
            best = min(best, cur);
        }
        return best;
    }
};
