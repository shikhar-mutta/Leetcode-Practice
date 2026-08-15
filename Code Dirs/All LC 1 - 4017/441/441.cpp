// Link: https://leetcode.com/problems/arranging-coins/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: binary search the largest k such that k*(k+1)/2 <= n
class Solution {
public:
    int arrangeCoins(int n) {
        long long lo = 0, hi = n;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (mid * (mid + 1) / 2 <= n) lo = mid;
            else hi = mid - 1;
        }
        return (int)lo;
    }
};
