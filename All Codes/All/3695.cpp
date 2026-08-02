// Link: https://leetcode.com/problems/maximize-alternating-sum-using-swaps/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) for building the sparse table and O(klogn) for processing the queries, where n is the size of the input array and k is the number of queries.
// SC: O(nlogn) for storing the sparse table and O(n) for storing the input array.
// Approach:
// 1. We can use a sparse table to efficiently compute the minimum and maximum values in any subarray of the input array.
// 2. We can then use a priority queue to keep track of the k largest differences between the maximum and minimum values in the subarrays of the input array
// 3. We can iterate through the input array and for each subarray, we can compute the difference between the maximum and minimum values using the sparse table and add it to the priority queue
// 4. Finally, we can pop the k largest differences from the priority queue and return their sum as the maximum total value of the subarrays.
int p[100000], sz[100000], st[100001], val[100000];
int speedup = []
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
int repr(int i) { return i == p[i] ? i : p[i] = repr(p[i]); }
void merge(int a, int b)
{
    if ((a = repr(a)) == (b = repr(b)))
        return;
    if (sz[a] < sz[b])
    {
        p[a] = b;
        return;
    }
    if (sz[a] == sz[b])
        ++sz[a];
    p[b] = a;
}
class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums, vector<vector<int>> &swaps)
    {
        int N = size(nums);
        iota(p, p + N, 0);
        fill(sz, sz + N, 0);
        for (const auto &s : swaps)
            merge(s[0], s[1]);

        int M = 0;
        for (int i = 0; i < N; ++i)
            if (repr(i) == i)
                sz[i] = M++;
        for (int i = 0; i < N; ++i)
            p[i] = sz[p[i]];

        fill(st, st + M, 0);
        for (int i = 0; i < N; ++i)
            ++st[p[i]];
        for (int i = 1; i < M; ++i)
            st[i] += st[i - 1];
        st[M] = st[M - 1];
        for (int i = N - 1; i >= 0; --i)
            val[--st[p[i]]] = i;

        long long res = 0;
        for (int i = 0; i < M; ++i)
        {
            int a = st[i], b = st[i + 1], cnt = 0;
            for (int j = a; j < b; ++j)
            {
                if (!(val[j] & 1))
                    ++cnt;
                val[j] = nums[val[j]];
            }
            if (cnt == 0)
                res -= accumulate(val + a, val + b, 0ll);
            else if (cnt == b - a)
                res = accumulate(val + a, val + b, res);
            else
            {
                nth_element(val + a, val + a + cnt, val + b, greater<int>());
                res = accumulate(val + a, val + a + cnt,
                                 res - accumulate(val + a + cnt, val + b, 0ll));
            }
        }

        return res;
    }
};
