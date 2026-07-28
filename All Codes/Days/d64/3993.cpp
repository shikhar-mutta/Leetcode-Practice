// Link: https://leetcode.com/problems/maximum-value-of-an-alternating-sequence/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(1)  SC: O(1)
// Approach: to maximize, always go up first by the full m, and take
// every subsequent down-step by the minimal valid amount (1), so each
// up/down pair nets (m-1). With k = ceil((n-1)/2) up-steps, the maximum
// value achieved right after the last up-step is s + k*m - (k-1).
class Solution
{
public:
    long long maximumValue(int n, int s, int m)
    {
        if (n == 1)
            return s;
        long long k = (long long)n / 2;
        return s + k * (long long)m - (k - 1);
    }
};
