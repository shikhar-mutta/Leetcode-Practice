// Link: https://leetcode.com/problems/maximum-score-using-exactly-k-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m*k)  SC: O(n*m*k)
//  Approach: choose exactly k index pairs (i1<i2<...<ik into nums1, j1<j2<...<jk into nums2 independently) maximizing sum of nums1[i]*nums2[j]. DP f[i][j][t] = best score using nums1[0..i-1], nums2[0..j-1] with exactly t pairs placed so far; transitions either skip the current nums1 or nums2 element, or use them together as the t-th pair.

int speedup = []
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
long long prd[100 * 100], dp[100 * 100 + 101];

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int N = size(nums1), M = size(nums2), T = M + 1;
        fill(dp, dp + (N * M + T), 0);
        for (int i = 0, p = 0; i < N; ++i)
            for (int j = 0; j < M; ++j, ++p)
                prd[p] = (long long)nums1[i] * nums2[j];

        for (int u = 0; u < k; ++u)
        {
            int p = N * M - 1;
            for (int i = N - 1; i >= u; --i, p -= u)
            {
                for (int j = M - 1; j >= u; --j, --p)
                    dp[p + T] = prd[p] + dp[p];
            }

            p += T + u + 2;
            for (int j = u + 1; j < M; ++j, ++p)
                dp[p] = max(dp[p], dp[p - 1]);
            for (int i = u + 1; i < N; ++i)
            {
                p += u;
                dp[p] = max(dp[p], dp[p - M]);
                ++p;
                for (int j = u + 1; j < M; ++j, ++p)
                    dp[p] = max(dp[p], max(dp[p - 1], dp[p - M]));
            }
        }
        return dp[N * M + M];
    }
};
