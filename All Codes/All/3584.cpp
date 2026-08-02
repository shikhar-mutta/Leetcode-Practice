// Link: https://leetcode.com/problems/maximum-product-of-first-and-last-elements-of-a-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: Use a sliding window to maintain the maximum and minimum values in the current window. For each position, calculate the maximum product of the first and last elements of a subsequence of length m.
class Solution
{
public:
    long long maximumProduct(vector<int> &A, int m)
    {
        long long ma = A[0], mi = A[0], res = 1LL * A[0] * A[m - 1];
        for (int i = m; i < A.size(); ++i)
        {
            ma = fmax(ma, A[i - m + 1]);
            mi = fmin(mi, A[i - m + 1]);
            res = max({res, mi * A[i], ma * A[i]});
        }
        return res;
    }
};