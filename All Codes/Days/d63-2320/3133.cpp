// Link: https://leetcode.com/problems/minimum-array-end/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n), SC: O(1)
// Approach: Bits already set in x are fixed for every array element. The
// remaining n-1 "free" bit slots (positions where x has a 0) must encode
// the value n-1 in binary across those slots, in order, to minimize the
// final (largest) element while satisfying the AND-with-x constraint.
class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        long long m = n - 1;
        long long bit = 1;

        while (m > 0) {
            if (!(result & bit)) {
                if (m & 1) {
                    result |= bit;
                }
                m >>= 1;
            }
            bit <<= 1;
        }

        return result;
    }
};
