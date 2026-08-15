// Link: https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sideSum(long long peak, long long count) {
        if (peak >= count) {
            return (peak + peak - count + 1) * count / 2;
        } else {
            return (peak + 1) * peak / 2 + (count - peak);
        }
    }

    int maxValue(int n, int index, int maxSum) {
        long long left = index, right = n - 1 - index;
        int lo = 1, hi = maxSum;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            long long total = mid + sideSum(mid - 1, left) + sideSum(mid - 1, right);
            if (total <= maxSum) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
