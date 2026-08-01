// Link: https://leetcode.com/problems/number-of-zigzag-arrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * (r - l + 1)) where n is the length of the array and r - l + 1 is the range of values that can be used in the array.
// SC: O(r - l + 1) where r - l + 1 is the range of values that can be used in the array.
// Approach:
// 1. We can use dynamic programming to solve this problem.
// 2. We can use a 1D array to store the number of zigzag arrays of length n that can be formed using the values in the range [l, r].
// 3. We can initialize the array with the number of zigzag arrays of length 1 and 2.
// 4. We can then iterate through the array and for each length, we can calculate the number of zigzag arrays that can be formed using the values in the range [l, r].
// 5. We can use the formula for the number of zigzag arrays of length n that can be formed using the values in the range [l, r] to calculate the number of zigzag arrays of length n that can be formed using the values in the range [l, r].
// 6. Finally, we can return the number of zigzag arrays of length n that can be formed using the values in the range [l, r] modulo 10^9 + 7.
class Solution
{
public:
    int zigZagArrays(int n, int l, int r)
    {
        if (n <= 2)
            return -1;
        const int MOD = 1e9 + 7;
        int m = r - l;
        constexpr int MAX_M = 75;

        array<array<int, MAX_M>, MAX_M> T{};
        for (int i = 0; i <= m; i++)
        {
            for (int j = m - i + 1; j <= m; j++)
            {
                T[i][j] = 1;
            }
        }
        array<array<int, MAX_M>, MAX_M> nextT{};

        array<int, MAX_M> dp{};
        array<int, MAX_M> nextDp{};

        // base case length 2
        for (int i = 0; i <= m; i++)
        {
            dp[i] = i;
        }

        // starting at length 3
        n -= 2;

        // loop variables
        array<unsigned long long, MAX_M> row{};

        while (n > 0)
        {
            if (n & 1)
            {
                for (int i = 0; i <= m; i++)
                {
                    unsigned long long sum = 0;
                    for (int j = 0; j <= m; j++)
                    {
                        sum += static_cast<unsigned long long>(T[i][j]) * dp[j];
                        if ((j & 15) == 15)
                        {
                            sum = sum % MOD;
                        }
                    }
                    nextDp[i] = sum % MOD;
                }
                dp = nextDp;
            }
            n >>= 1;
            if (n == 0)
                break;
            for (int i = 0; i <= m; i++)
            {
                row.fill(0);
                for (int a = 0; a <= m; a++)
                {
                    if (T[i][a] == 0)
                        continue;
                    for (int j = 0; j <= m; j++)
                    {
                        row[j] +=
                            static_cast<unsigned long long>(T[i][a]) * T[a][j];
                    }
                    if ((a & 15) == 15)
                    {
                        for (int j = 0; j <= m; j++)
                        {
                            row[j] = row[j] % MOD;
                        }
                    }
                }
                for (int j = 0; j <= m; j++)
                {
                    nextT[i][j] = row[j] % MOD;
                }
            }
            T = nextT;
        }
        long long answer = 0;
        for (int i = 0; i <= m; i++)
        {
            answer += dp[i];
        }
        return (answer * 2) % MOD;
    }
};
