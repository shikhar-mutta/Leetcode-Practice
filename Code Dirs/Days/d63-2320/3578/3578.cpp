// Link: https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: Use a sliding window to maintain the maximum and minimum values in the current window. Use dynamic programming to count the number of valid partitions. The dp[i] represents the number of valid partitions ending at index i. The cumulative sum c[i] is used to efficiently calculate the number of valid partitions for the current index based on previous indices.
class Solution
{
public:
    int countPartitions(vector<int> &a, int k)
    {
        int n = a.size();
        typedef long long LL;
        const int mod = 1e9 + 7;

        vector<LL> dp(n, 0);
        vector<LL> c(n, 0);
        deque<int> m, M;
        m.push_back(0);
        M.push_back(0);
        int j = -1;
        dp[0] = 1;
        c[0] = 1;
        LL cum = 1;
        for (int i = 1; i < n; ++i)
        {
            while (!m.empty() && a[m.back()] >= a[i])
                m.pop_back();
            while (!M.empty() && a[M.back()] <= a[i])
                M.pop_back();

            m.push_back(i);
            M.push_back(i);

            while (a[M.front()] - a[m.front()] > k)
            {
                if (M.front() < m.front())
                {
                    j = M.front();
                    M.pop_front();
                }
                else
                {
                    j = m.front();
                    m.pop_front();
                }
            }

            LL cc = j >= 1 ? c[j - 1] : 0;

            // printf("%d  M: (%d, %d), m: (%d, %d), cc: %lld, j: %d\n",
            // i, M.front(), a[M.front()], m.front(), a[m.front()], cc, j);

            dp[i] = ((cum) + mod - cc) % mod;
            if (j == -1)
                dp[i] = (dp[i] + 1) % mod;

            // printf("dp: %d %lld\n", i, dp[i]);

            cum = (cum + dp[i]) % mod;
            c[i] = cum;
        }

        return dp[n - 1];
    }
};