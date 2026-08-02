// Link: https://leetcode.com/problems/minimum-partition-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N * K). SC: O(N). DP, divide and conquer optimization.
// Approach: We can use dynamic programming to solve this problem. We can use a DP table to store the minimum partition score for each subarray. We can then use divide and conquer optimization to reduce the time complexity of the DP solution. The idea is to use the fact that the optimal partition point for a subarray is monotonic, which allows us to reduce the number of states we need to consider when computing the DP table.
int s[1000];
long long sc1[1000], sc2[1000], *scores, *nsc;

void eval(int l, int r, int pl, int pr)
{
    int m = (l + r) / 2, bp = -1;
    long long bs = LONG_LONG_MAX;
    for (int p = pl, rr = min(pr, m); p <= rr; ++p)
    {
        int sm = s[m] - s[p - 1];
        long long score = scores[p - 1] + (long long)sm * (sm + 1) / 2;
        if (score < bs)
            bs = score, bp = p;
    }
    nsc[m] = bs;
    if (m > l)
        eval(l, m - 1, pl, bp);
    if (m < r)
        eval(m + 1, r, bp, pr);
}

class Solution
{
public:
    long long minPartitionScore(vector<int> &nums, int k)
    {
        int N = size(nums);
        scores = sc1;
        nsc = sc2;
        for (int i = 0, pv = 0; i < N; ++i)
        {
            s[i] = pv += nums[i];
            scores[i] = (long long)pv * (pv + 1) / 2;
        }
        for (int i = 1; i < k; ++i)
        {
            eval(i, N - 1, i, N - 1);
            swap(scores, nsc);
        }
        return scores[N - 1];
    }
};
