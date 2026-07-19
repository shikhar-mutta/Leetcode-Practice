// Link: https://leetcode.com/problems/allocate-mailboxes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * k) where n is the number of houses and k is the number of mailboxes
// SC: O(n^2) where n is the number of houses
// Approach:
//   1. Sort the houses in ascending order.
//   2. Precompute the cost of placing a mailbox for every possible range of houses
//   3. Use dynamic programming to find the minimum cost of placing k mailboxes for the given houses.
//   4. Use divide and conquer optimization to speed up the dynamic programming solution
//   5. Return the minimum cost of placing k mailboxes for the given houses.
int dp[2][105];
int c[105][105];
int n, k1;
const int INF = 0x3f3f3f3f;
void solve(int cur, int lo, int hi, int optlo, int opthi)
{
    if (lo > hi)
        return;
    int mid = (lo + hi) >> 1;
    int bestj = optlo;
    int bestval = INF;
    for (int j = optlo; j <= min(mid - 1, opthi); j++)
    {
        int val = dp[cur ^ 1][j] + c[j + 1][mid];
        if (val < bestval)
        {
            bestval = val;
            bestj = j;
        }
    }
    dp[cur][mid] = bestval;
    solve(cur, lo, mid - 1, optlo, bestj);
    solve(cur, mid + 1, hi, bestj, opthi);
}
class Solution
{
public:
    int minDistance(vector<int> &houses, int k)
    {
        sort(houses.begin(), houses.end());
        n = houses.size();
        k1 = k;
        for (int i = 1; i <= n; i++)
            c[i][i] = 0;
        for (int len = 2; len <= n; len++)
        {
            for (int i = 1; i + len - 1 <= n; i++)
            {
                int j = i + len - 1;
                c[i][j] = c[i + 1][j - 1] + (houses[j - 1] - houses[i - 1]);
            }
        }
        for (int i = 1; i <= n; i++)
            dp[1][i] = c[1][i];
        for (int j = 2; j <= k; j++)
        {
            int cur = j & 1;
            fill(dp[cur], dp[cur] + n + 1, INF);
            solve(cur, j, n, j - 1, n - 1);
        }
        return dp[k & 1][n];
    }
};