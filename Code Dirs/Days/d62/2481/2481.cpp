// Link: https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: n=1 needs no cuts. If n is even, each cut can be a diameter
// through the center, splitting the circle into 2 slices per cut, so
// n/2 cuts suffice. If n is odd, no cut can pass through the center
// (that would always produce an even split), so each cut only adds one
// slice, needing n cuts.
class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) return 0;
        return (n % 2 == 0) ? n / 2 : n;
    }
};
