// Link: https://leetcode.com/problems/guess-number-higher-or-lower/description/

#include <bits/stdc++.h>
using namespace std;

int guess(int num);

// TC: O(log n)  SC: O(1)
// Approach: binary search using the guess() oracle
class Solution {
public:
    int guessNumber(int n) {
        long long lo = 1, hi = n;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            int g = guess(mid);
            if (g == 0) return mid;
            if (g < 0) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};
