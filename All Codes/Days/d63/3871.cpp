// Link: https://leetcode.com/problems/count-commas-in-range-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(1)
// Approach: group numbers by digit count d; every number with d digits
// contributes the same (d-1)/3 commas. For each d, count how many
// d-digit numbers are <= n (using __int128 to avoid overflow near
// 10^19) and accumulate commasPerNumber * count.
class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        __int128 low = 1;
        for (int d = 1; d <= 19; d++) {
            if (low > n) break;
            __int128 high = low * 10 - 1;
            __int128 count = (high <= n) ? (high - low + 1) : ((__int128)n - low + 1);
            int commasPer = (d - 1) / 3;
            total += (long long)count * commasPer;
            low *= 10;
        }
        return total;
    }
};
