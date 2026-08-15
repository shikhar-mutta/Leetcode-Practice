// Link: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m log(m*n)) SC: O(1)
// Approach: binary search on the value v; count how many table entries are <= v (sum over rows of min(v/row, n)); find smallest v where count >= k.
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m*n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long count = 0;
            for (int i = 1; i <= m; i++) count += min(mid / i, n);
            if (count >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
