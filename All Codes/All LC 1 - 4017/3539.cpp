// Link: https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * k * n * m): Recursion with memoization
// SC: O(m * k * n * m): dp array
// Approach: We can use recursion with memoization to solve this problem. We can define a recursive function that takes the current index, the number of elements left to choose, the number of magical sequences left, and a bitmask representing the current state of the sequence as parameters. The base case is when we have chosen all m elements or when we have reached the end of the nums array. If we have chosen all m elements and have exactly k magical sequences, we return 1. Otherwise, we return 0. In each recursive call, we have two options: either we choose the current element or we don't. If we choose the current element, we update the bitmask and decrement the number of elements left to choose. If we don't choose the current element, we simply move to the next index. We return the sum of these two options and store it in a dp array for memoization.
static constexpr int MOD = 1e9 + 7;
static int C[31][31] = {{0}};
static int dp[31][31][50][31];
class Solution
{
    int m, k, n;
    void Pascal()
    {
        if (C[0][0] == 1)
            return;
        for (int i = 1; i <= 30; i++)
        {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j <= i / 2; j++)
            {
                const int Cij = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] = C[i][i - j] = Cij;
            }
        }
    }

    int dfs(int m, int k, int i, unsigned flag, vector<int> &nums)
    {
        const int bz = popcount(flag);
        if (m < 0 || k < 0 || m + bz < k)
            return 0;
        if (m == 0)
            return (k == bz) ? 1 : 0;
        if (i >= n)
            return 0;

        if (dp[m][k][i][flag] != -1)
            return dp[m][k][i][flag];

        long long ans = 0, powX = 1;
        const int x = nums[i];
        for (int f = 0; f <= m; f++)
        {
            long long perm = C[m][f] * powX % MOD;
            unsigned newFlag = flag + f;
            unsigned nextFlag = newFlag >> 1;
            bool bitSet = newFlag & 1;
            ans = (ans + perm * dfs(m - f, k - bitSet, i + 1, nextFlag, nums)) %
                  MOD;
            powX = (powX * x) % MOD;
        }

        return dp[m][k][i][flag] = ans;
    }

public:
    int magicalSum(int m, int k, vector<int> &nums)
    {
        Pascal();
        this->m = m;
        this->k = k;
        n = nums.size();
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= m; j++)
                for (int s = 0; s < n; s++)
                    memset(dp[i][j][s], -1, sizeof(int) * (m + 1));

        return dfs(m, k, 0, 0, nums);
    }
};
