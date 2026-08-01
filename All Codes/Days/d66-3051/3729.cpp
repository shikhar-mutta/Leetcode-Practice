// Link: https://leetcode.com/problems/count-distinct-subarrays-divisible-by-k-in-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(min(n,k))
//  Approach: since nums is sorted, two index ranges give the same content
//  only if both are constant runs of the same value and length, so first
//  count every good subarray by index range via the classic prefix-sum-mod-k
//  technique (LC 974), then for each maximal run of equal values of length
//  m, for every length h whose sum (h*value) is divisible by k, subtract the
//  (m-h) extra duplicate occurrences within that run so each distinct
//  content is counted once.
int vals[100002];
int speedup = []
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution
{
public:
    long long numGoodSubarrays(vector<int> &nums, int k)
    {
        int N = size(nums);
        long long res = 0;

        for (int i = 0; i < N; ++i)
            vals[i + 1] = (vals[i] + nums[i]) % k;
        sort(vals + 1, vals + (N + 1));
        vals[N + 1] = -1;

        for (int i = 1, p = 0; i <= N + 1; ++i)
            if (vals[i] != vals[p])
            {
                int s = i - p;
                p = i;
                if (s > 1)
                    res += (s - 1ll) * s / 2;
            }

        for (int i = 1, p = 0; i <= N; ++i)
            if (i == N || nums[i] != nums[p])
            {
                if (int s = i - p; s > 1)
                {
                    if (int f = k / gcd(k, nums[p]); s > f)
                    {
                        int m = (s - 1) / f;
                        res -= (long long)m * (2 * s - f * (m + 1)) / 2;
                    }
                }
                p = i;
            }
        return res;
    }
};
