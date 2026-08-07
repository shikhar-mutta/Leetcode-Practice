// Link: https://leetcode.com/problems/factorial-trailing-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: count factors of 5 in n! (factors of 2 are always more abundant) — sum n/5 + n/25 + n/125 + ...
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) {
            n /= 5;
            count += n;
        }
        return count;
    }
};
