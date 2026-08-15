// Link: https://leetcode.com/problems/minimum-operations-to-make-array-equal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
//  Approach:
//    1. We will use the formula n*n/4 to calculate the minimum number of operations required to make the array equal.
//    2. We will return the result.
class Solution
{
public:
    int minOperations(int n) { return n * n / 4; }
};
