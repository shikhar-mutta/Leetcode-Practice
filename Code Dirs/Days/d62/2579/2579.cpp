// Link: https://leetcode.com/problems/count-total-number-of-colored-cells/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: closed-form centered-square-numbers formula. Colored cells after n
// minutes form a diamond whose count is 1 + 4*(1+2+...+(n-1)) = 2n^2 - 2n + 1.
class Solution {
public:
    long long coloredCells(int n) { return 2LL * n * n - 2LL * n + 1; }
};
