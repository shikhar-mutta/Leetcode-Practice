// Link: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: for fixed right endpoint r, g(l) = distinct-count of nums[l..r] is monotonic in l
// and, as r grows by one, increases by exactly 1 for every l in (prevOcc(nums[r]), r] (a range
// update) and stays the same elsewhere. Track sum_l g(l)^2 incrementally: when g increases by 1
// over a range, the sum-of-squares changes by 2*sum(oldG over range) + rangeSize — maintained
// with a range-update/range-sum Fenwick tree for oldG's range sum.
class Solution
{
public:
    vector<long long> bit1, bit2;
    int n;

    void bitAdd(vector<long long> &bit, int i, long long val)
    {
        for (; i <= n; i += i & (-i))
            bit[i] += val;
    }
    long long bitQuery(vector<long long> &bit, int i)
    {
        long long s = 0;
        for (; i > 0; i -= i & (-i))
            s += bit[i];
        return s;
    }
    void rangeAdd(int l, int r, long long val)
    { // 1-indexed inclusive
        bitAdd(bit1, l, val);
        bitAdd(bit1, r + 1, -val);
        bitAdd(bit2, l, val * (l - 1));
        bitAdd(bit2, r + 1, -val * r);
    }
    long long prefixSum(int i)
    {
        return bitQuery(bit1, i) * i - bitQuery(bit2, i);
    }
    long long rangeSum(int l, int r)
    { // 1-indexed inclusive
        if (l > r)
            return 0;
        return prefixSum(r) - prefixSum(l - 1);
    }

    int sumCounts(vector<int> &nums)
    {
        n = nums.size();
        bit1.assign(n + 2, 0);
        bit2.assign(n + 2, 0);
        const long long MOD = 1e9 + 7;

        unordered_map<int, int> lastOcc; // 1-indexed position of last occurrence
        long long sumSquares = 0, ans = 0;

        for (int r = 1; r <= n; r++)
        {
            int prevOcc = lastOcc.count(nums[r - 1]) ? lastOcc[nums[r - 1]] : 0;
            int a = prevOcc + 1, b = r;
            long long oldSum = rangeSum(a, b);
            long long rangeSize = b - a + 1;
            long long delta = 2 * oldSum + rangeSize;
            rangeAdd(a, b, 1);
            sumSquares = (sumSquares + delta) % MOD;
            ans = (ans + sumSquares) % MOD;
            lastOcc[nums[r - 1]] = r;
        }
        return (int)ans;
    }
};
