// Link: https://leetcode.com/problems/minimum-inversion-count-in-subarrays-of-fixed-length/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
//  Approach: Use a Fenwick tree to maintain the count of elements in the current window of size k. For each new element added to the window, we can calculate the number of inversions by querying the Fenwick tree for the count of elements greater than the current element. We can also update the Fenwick tree by adding the current element to it. When we remove an element from the window, we can update the Fenwick tree by removing that element from it. We keep track of the minimum inversion count seen so far and return it at the end.

int vals[100000], M;

inline int eval(int i)
{
    int res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        res += vals[i];
    return res;
}

inline void update(int i, int v)
{
    for (; i < M; i = i | (i + 1))
        vals[i] += v;
}

class Solution
{
public:
    long long minInversionCount(vector<int> &nums, int k)
    {
        if (k == 1)
            return 0;
        int N = size(nums);
        copy(begin(nums), end(nums), vals);
        sort(vals, vals + N);
        M = unique(vals, vals + N) - vals;
        for (int i = 0; i < N; ++i)
            nums[i] = lower_bound(vals, vals + M, nums[i]) - vals;
        fill(vals, vals + M, 0);
        long long cur = 0;
        for (int i = 0; i < k; ++i)
        {
            cur += i - eval(nums[i]);
            update(nums[i], 1);
        }
        long long res = cur;
        for (int i = k; i < N; ++i)
        {
            cur -= eval(nums[i - k] - 1);
            update(nums[i - k], -1);
            cur += (k - 1) - eval(nums[i]);
            update(nums[i], 1);
            res = min(res, cur);
        }
        return res;
    }
};