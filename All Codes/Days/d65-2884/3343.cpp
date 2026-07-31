// Link: https://leetcode.com/problems/count-number-of-balanced-permutations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(10^3 * 40^2), SC: O(10^3 * 40^2)
// Approach: We can use dynamic programming to count the number of balanced permutations. We can define a 3D DP array dp[i][j][k] where i represents the current digit we are considering, j represents the number of digits we have used so far, and k represents the sum of the digits we have used so far. The base case is dp[0][0][0] = 1, which means that there is one way to form a balanced permutation with no digits used and a sum of 0. For each digit, we can either use it or not use it, and we can update the DP array accordingly. Finally, we can return dp[10][n/2][s/2], where n is the length of the input string and s is the sum of the digits in the input string.
const int Modulus = 1e9 + 7;
int C[81][81];
static int preprocess = []()
{
    C[0][0] = 1;
    for (int i = 1; i <= 80; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Modulus;
    }

    return 0;
}();

int dp[11][41][361];
class Solution
{
public:
    int countBalancedPermutations(string num)
    {
        int size{(int)num.size()}, sod{};
        int freq[10]{}, prefix[11]{};

        for (const char &ch : num)
        {
            ++freq[ch - '0'];
            sod += (ch - '0');
        }
        if (sod & 1)
            return 0;

        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= 10; ++i)
            prefix[i] = prefix[i - 1] + freq[i - 1];

        auto dfs = [&](this auto &&self, int i, int n, int sum) -> int
        {
            if (!i)
                return (!n && !sum);
            auto &ret = dp[i][n][sum];
            if (ret != -1)
                return ret;

            int cnt = 0;
            for (int j = 0; j <= freq[i - 1]; ++j)
            {
                if (j > n || (i - 1) * j > sum ||
                    freq[i - 1] - j > prefix[i] - n)
                    continue;
                cnt = (cnt +
                       ((1LL * C[n][j] * C[prefix[i] - n][freq[i - 1] - j]) %
                        Modulus) *
                           self(i - 1, n - j, sum - (i - 1) * j)) %
                      Modulus;
            }

            return ret = cnt;
        };

        return dfs(10, size >> 1, sod >> 1);
    }
};
