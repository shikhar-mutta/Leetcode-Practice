// Link: https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countLE(vector<int>& nums1, vector<int>& nums2, long long x) {
        long long total = 0;
        int m = nums2.size();
        for (int a : nums1) {
            if (a == 0) {
                if (0 <= x) total += m;
            } else if (a > 0) {
                // find count of b with a*b <= x -> largest index with a*b<=x, count=idx+1
                int lo = 0, hi = m; // first index where a*b > x
                while (lo < hi) {
                    int mid = (lo + hi) / 2;
                    if ((long long)a * nums2[mid] <= x) lo = mid + 1;
                    else hi = mid;
                }
                total += lo;
            } else {
                // a < 0: product decreasing in b; find first index where a*b <= x
                int lo = 0, hi = m;
                while (lo < hi) {
                    int mid = (lo + hi) / 2;
                    if ((long long)a * nums2[mid] > x) lo = mid + 1;
                    else hi = mid;
                }
                total += (m - lo);
            }
        }
        return total;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long lo = -10000000000LL, hi = 10000000000LL;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(nums1, nums2, mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
