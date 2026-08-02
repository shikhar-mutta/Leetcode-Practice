// Link: https://leetcode.com/problems/last-remaining-integer-after-alternating-deletion-operations/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log n)  SC: O(log n)
// Approach: track only the 1-indexed position (within the current-size
// array) of the eventual survivor, recursing on array size instead of
// simulating. A left-delete round keeps positions 1,3,5,...; the kept
// position j maps back to original 2j-1. A right-delete round keeps
// elements counted 1,3,5,... from the right (in original left-right
// order); kept position j maps back to original n-2m+2j (m=ceil(size/2)).
// Recurse until size 1, alternating direction starting with a left-delete.
class Solution
{
    long long g(long long n, bool left)
    {
        if (n == 1)
            return 1;
        long long m = (n + 1) / 2;
        if (left)
            return 2 * g(m, false) - 1;
        return n - 2 * m + 2 * g(m, true);
    }

public:
    long long lastInteger(long long n)
    {
        return g(n, true);
    }
};
