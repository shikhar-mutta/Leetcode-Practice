// Link: https://leetcode.com/problems/minimum-cost-to-split-into-ones/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
// Approach: the total cost telescopes to a split-order-independent
// invariant: summing a*b over every split, each pair of the final n
// ones ends up contributing exactly once across the whole process
// (classic result), giving total cost = C(n,2) = n*(n-1)/2 regardless
// of strategy.
class Solution {
public:
    int minCost(int n) {
        return n * (n - 1) / 2;
    }
};
