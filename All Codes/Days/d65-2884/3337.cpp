// Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(26^3 * log(t)), SC: O(26^2)
// Approach: We can represent the transformation as a matrix multiplication problem. We can create a 26x26 matrix M, where M[i][j] represents the number of ways to transform character 'a' + j to character 'a' + i in one transformation. We can then raise this matrix to the power of t using matrix exponentiation. Finally, we can multiply the resulting matrix with the initial character counts to get the final character counts after t transformations. The sum of these counts will give us the total number of characters in the string after t transformations.
class Solution
{
public:
    static constexpr long long MOD = 1'000'000'007;
    using Matrix = std::array<std::array<long long, 26>, 26>;

    Matrix multiply(const Matrix &A, const Matrix &B)
    {
        Matrix C{};
        for (auto &row : C)
            row.fill(0);
        for (int i = 0; i < 26; i++)
            for (int k = 0; k < 26; k++)
            {
                if (A[i][k] == 0)
                    continue;
                for (int j = 0; j < 26; j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        return C;
    }

    Matrix matpow(Matrix M, int p)
    {
        Matrix result{};
        for (int i = 0; i < 26; i++)
        {
            result[i].fill(0);
            result[i][i] = 1;
        }
        while (p > 0)
        {
            if (p & 1)
                result = multiply(result, M);
            M = multiply(M, M);
            p >>= 1;
        }
        return result;
    }

    int lengthAfterTransformations(std::string s, int t,
                                   std::vector<int> &nums)
    {
        Matrix M{};
        for (auto &row : M)
            row.fill(0);
        for (int i = 0; i < 26; i++)
            for (int k = 1; k <= nums[i]; k++)
                M[(i + k) % 26][i] = 1;

        Matrix Mt = matpow(M, t);

        std::array<long long, 26> cnt{};
        cnt.fill(0);
        for (char c : s)
            cnt[c - 'a']++;

        long long ans = 0;
        for (int j = 0; j < 26; j++)
        {
            long long val = 0;
            for (int i = 0; i < 26; i++)
                val = (val + Mt[j][i] * cnt[i]) % MOD;
            ans = (ans + val) % MOD;
        }
        return (int)ans;
    }
};
