// Link: https://leetcode.com/problems/count-commas-in-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(1)
// Approach: for each number, commas inserted = (digitCount-1)/3 (0 for
// fewer than 4 digits). Sum across 1..n directly since n<=1e5.
class Solution {
public:
    int countCommas(int n) {
        int total = 0;
        for (int x = 1; x <= n; x++) {
            int digits = to_string(x).size();
            total += (digits - 1) / 3;
        }
        return total;
    }
};
