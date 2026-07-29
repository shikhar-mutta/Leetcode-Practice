// Link: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * m)  SC: O(n * m)
// Approach: We can use a prefix sum array to calculate the sum of submatrices in constant time. We can iterate over all pairs of rows and for each pair, we can calculate the sum of the submatrix formed by those two rows and all columns. We can use a hash map to count the number of times each sum occurs and check if the difference between the current sum and the target exists in the hash map. If it does, we add the count to our answer.
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
class Solution
{
    static constexpr int nmax = 100;
    static constexpr int M = nmax * nmax * 1000;
    inline static int cnt[2 * M + 1];
    inline static int pref_col[nmax];
    inline static vector<vector<int>> tr{nmax, vector<int>(nmax)};

public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int tar)
    {
        int n = matrix.size(), m = matrix[0].size();
        auto &mt = n <= m ? matrix : tr;
        if (n > m)
        {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    tr[j][i] = matrix[i][j];
            swap(n, m);
        }
        int ans = 0;
        for (int i1 = 0; i1 < n; ++i1)
        {
            memset(pref_col, 0, m * sizeof(int));
            for (int i2 = i1; i2 < n; ++i2)
            {
                cnt[M] = 1;
                int pref_sub = 0;
                for (int j = 0; j < m; ++j)
                {
                    pref_sub += (pref_col[j] += mt[i2][j]);
                    if (abs(pref_sub - tar) <= M)
                        ans += cnt[pref_sub - tar + M];
                    ++cnt[pref_sub + M];
                }
                pref_sub = 0;
                for (int j = 0; j < m; ++j)
                    cnt[(pref_sub += pref_col[j]) + M] = 0;
            }
        }
        return ans;
    }
};