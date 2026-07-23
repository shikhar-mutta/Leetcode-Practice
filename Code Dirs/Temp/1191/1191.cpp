// Link: https://leetcode.com/problems/k-concatenation-maximum-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static const int MOD = 1e9 + 7;

    // max subarray sum over a plain array (allows empty → min 0)
    long long kadane(const vector<int> &a)
    {
        long long best = 0, cur = 0;
        for (int x : a)
        {
            cur = max(0LL, cur + x);
            best = max(best, cur);
        }
        return best;
    }

public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        long long total = 0;
        for (int x : arr)
            total += x;

        if (k == 1)
            return kadane(arr) % MOD;

        // best over two copies: covers any wrap-around subarray
        vector<int> two(arr);
        two.insert(two.end(), arr.begin(), arr.end());
        long long best2 = kadane(two);
        // if the whole array sums positive, stuff k-2 full copies in the middle
        if (total > 0)
            best2 += (long long)(k - 2) * total;

        return best2 % MOD;
    }
};