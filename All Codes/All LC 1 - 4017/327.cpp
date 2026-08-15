// Link: https://leetcode.com/problems/count-of-range-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: merge sort over prefix sums; while merging [l,mid] and [mid+1,r],
// for each left-half prefix count how many right-half prefixes fall in
// [prefix+lower, prefix+upper]
class Solution {
    int count(vector<long long>& prefix, int l, int r, int lower, int upper) {
        if (l >= r) return 0;
        int mid = (l + r) / 2;
        int cnt = count(prefix, l, mid, lower, upper) + count(prefix, mid + 1, r, lower, upper);

        int lo = mid + 1, hi = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (lo <= r && prefix[lo] - prefix[i] < lower) lo++;
            while (hi <= r && prefix[hi] - prefix[i] <= upper) hi++;
            cnt += hi - lo;
        }

        inplace_merge(prefix.begin() + l, prefix.begin() + mid + 1, prefix.begin() + r + 1);
        return cnt;
    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        return count(prefix, 0, n, lower, upper);
    }
};
