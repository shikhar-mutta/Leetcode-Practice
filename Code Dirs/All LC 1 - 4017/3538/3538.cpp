// Link: https://leetcode.com/problems/merge-operations-for-minimum-travel-time/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * k): Recursion with memoization
// SC: O(n * k): dp array
// Approach: We can use recursion with memoization to solve this problem. We can define a recursive function that takes the current index, the number of merges left, and the previous time as parameters. The base case is when we reach the end of the positions array. If we have no merges left, we return 0. Otherwise, we return a large value. In each recursive call, we have two options: either we merge the current position with the previous one or we don't. If we don't merge, we calculate the total time taken to travel from the previous position to the current position and add it to the result of the next recursive call. If we do merge, we iterate through the next positions and merge them until we run out of merges or reach the end of the array. We calculate the total time taken to travel from the previous position to the last merged position and add it to the result of the next recursive call. We return the minimum of these two options and store it in a dp array for memoization.
class Solution
{
public:
    int dp[50][11][101];
    int rec(int ind, vector<int> &pos, vector<int> &time, int n, int k,
            int prevT)
    {

        // ami ind thek merge kora suru korte chai jodi k > 0 hoy nahole na
        // jodi ami merge na kori tahole ami calculate korbo ind-1 theke ind
        // obdhi aste time ta nahole merge korte korte jabo

        // r current ta jodi merge na korte chai tahole prev time amar lagbe

        if (ind == n)
        {
            if (k == 0)
                return 0;
            return 1e9;
        }
        if (dp[ind][k][prevT] != -1)
            return dp[ind][k][prevT];
        // ami chaichi merge na korte
        int ans = 1e9;
        int tot = (pos[ind] - pos[ind - 1]) * prevT;
        ans = min(ans, rec(ind + 1, pos, time, n, k, time[ind]) + tot);

        // ebar merge korbo
        if (k > 0)
        {
            int cnt = k, tSum = time[ind];
            for (int i = ind + 1; i < n; i++)
            {
                if (cnt == 0)
                    break;
                cnt--;
                tSum += time[i];
                tot = (pos[i] - pos[ind - 1]) * prevT;
                if (cnt >= 0)
                    ans = min(ans, tot + rec(i + 1, pos, time, n, cnt, tSum));
            }
        }
        return dp[ind][k][prevT] = ans;
    }
    int minTravelTime(int l, int n, int k, vector<int> &pos,
                      vector<int> &time)
    {
        memset(dp, -1, sizeof(dp));
        int ans = rec(1, pos, time, n, k, time[0]);
        return ans;
    }
};