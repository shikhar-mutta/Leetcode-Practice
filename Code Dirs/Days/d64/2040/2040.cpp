// Link: https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((n+m) log(range))  SC: O(1)
// Approach: binary search on the answer value x. countLE(x) counts pairs
// with product <= x, split into cases by sign of nums1's elements using
// two-pointer / binary-search sweeps against nums2 (sorted). Find smallest x
// with countLE(x) >= k.
class Solution {
    vector<int> a, b;
    int n, m;

    long long countLE(long long x) {
        long long cnt = 0;
        for (int v : a) {
            if (v == 0) {
                if (x >= 0) cnt += m;
            } else if (v > 0) {
                // v>0: count b[j] with v*b[j] <= x, via binary search (b ascending)
                int lo2 = 0, hi2 = m;
                while (lo2 < hi2) {
                    int mid = (lo2 + hi2) / 2;
                    if ((long long)v * b[mid] <= x) lo2 = mid + 1;
                    else hi2 = mid;
                }
                cnt += lo2;
            } else {
                // v<0: v*b[j]<=x <=> b[j] >= x/v (division flips, careful with floor toward -inf issues; use direct compare)
                int lo2 = 0, hi2 = m;
                while (lo2 < hi2) {
                    int mid = (lo2 + hi2) / 2;
                    if ((long long)v * b[mid] <= x) hi2 = mid;
                    else lo2 = mid + 1;
                }
                cnt += (m - lo2);
            }
        }
        return cnt;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        a = nums1; b = nums2;
        n = a.size(); m = b.size();
        long long lo = -10000000000LL, hi = 10000000000LL;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
