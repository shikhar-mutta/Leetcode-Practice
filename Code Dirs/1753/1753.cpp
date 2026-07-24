// Link: https://leetcode.com/problems/maximum-score-from-removing-stones/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1), SC: O(1)
//  Approach:
//    1. We can calculate the total number of stones and the maximum number of stones in any pile.
//    2. The maximum score we can achieve is the minimum of the total number of stones minus the maximum number of stones in any pile and half of the total number of stones.
//    3. This is because we can only remove stones from two different piles at a time, so the maximum score is limited by the number of stones in the largest pile and the total number of stones.
// Note: We need to take the minimum of the two values to ensure that we do not exceed the maximum score possible.
class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        int s = a + b + c, m = max({a, b, c});
        return min(s - m, s / 2);
    }
};