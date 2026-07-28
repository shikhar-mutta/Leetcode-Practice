// Link: https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((m+n) log(m*n))  SC: O(1)
// Approach: binary search on the answer value x; count how many table
// entries are <= x in O(m) by summing min(x/i, n) over rows i, then
// find the smallest x whose count >= k.
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        long long lo = 1, hi = (long long)m * n;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long count = 0;
            for (int i = 1; i <= m; i++) count += min((long long)n, mid / i);
            if (count >= k) hi = mid;
            else lo = mid + 1;
        }
        return (int)lo;
    }
};
