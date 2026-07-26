// Link: https://leetcode.com/problems/k-items-with-the-maximum-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: greedily take +1 items first (max sum gain), then 0 items (free,
// no effect but consumes k with no cost), and only take -1 items once forced to.
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ones = min(k, numOnes); // take as many +1 as possible
        k -= ones;
        int zeros = min(k, numZeros); // then 0 items (no effect on sum)
        k -= zeros;
        int negOnes = min(k, numNegOnes); // forced to take -1 items last
        return ones - negOnes;
    }
};
