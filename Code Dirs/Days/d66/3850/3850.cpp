// Link: https://leetcode.com/problems/count-sequences-to-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n^2)
// Approach: Let cnts[i] = count of i in nums. Let t2, t3, t5 be the powers of 2, 3, 5 in k. If k has any other prime factor, return 0. Let r15 = number of sequences that can be formed using only 1 and 5 such that the product is divisible by 5^t5 * 3^t3. Let r2346 = number of sequences that can be formed using only 2, 3, 4, 6 such that the product is divisible by 2^t2 * 3^t3. The answer is r15 * r2346. To compute r15, we can choose how many 5's to use and how many 1's to use. To compute r2346, we can choose how many 6's to use and how many 2's and 4's to use. We can use combinatorics to count the number of ways to choose the numbers.
int C[20][20], pow3[20];
int speedup = []
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    pow3[0] = 1;
    C[0][0] = 1;
    for (int i = 1; i < 20; ++i)
    {
        pow3[i] = 3 * pow3[i - 1];
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    return 0;
}();

class Solution
{
public:
    int countSequences(vector<int> &nums, long long k)
    {
        int cnts[7]{}, N = size(nums), t3 = 0, t5 = 0;
        for (int n : nums)
            ++cnts[n];
        int t2 = __builtin_ctzll(k);
        k >>= t2;
        while (k % 3 == 0)
            k /= 3, ++t3;
        while (k % 5 == 0)
            k /= 5, ++t5;
        if (k != 1)
            return 0;

        int r15 = 0;
        for (int i = 0, tgt = (cnts[5] - t5) / 2; i <= tgt; ++i)
        {
            int tot = t5 + 2 * i;
            r15 += C[cnts[5]][tot] * C[tot][i];
        }
        r15 *= pow3[cnts[1]];

        int r2346 = 0;
        for (int d = 0; d <= cnts[6]; ++d)
        {
            int f6 = 0;
            for (int i = 0, tgt = (cnts[6] - d) / 2; i <= tgt; ++i)
            {
                int tot = d + 2 * i;
                f6 += C[cnts[6]][tot] * C[tot][i];
            }

            int r234 = 0;
            for (int d6 : {d, -d})
            {
                int r3 = 0;
                for (int i = 0, t3f = abs(t3 + d6), tgt = (cnts[3] - t3f) / 2; i <= tgt; ++i)
                {
                    int tot = t3f + 2 * i;
                    r3 += C[cnts[3]][tot] * C[tot][i];
                }

                int r24 = 0, t2f = abs(t2 + d6);
                for (int d4 = 0; d4 <= cnts[4]; ++d4)
                {
                    int f4 = 0;
                    for (int i = 0, tgt = (cnts[4] - d4) / 2; i <= tgt; ++i)
                    {
                        int tot = d4 + 2 * i;
                        f4 += C[cnts[4]][tot] * C[tot][i];
                    }

                    int r2 = 0;
                    for (int t2s : {t2f + 2 * d4, abs(t2f - 2 * d4)})
                    {
                        for (int i = 0, tgt = (cnts[2] - t2s) / 2; i <= tgt; ++i)
                        {
                            int tot = t2s + 2 * i;
                            r2 += C[cnts[2]][tot] * C[tot][i];
                        }
                        if (!d4)
                            break;
                    }
                    r24 += r2 * f4;
                }
                r234 += r3 * r24;
                if (!d6)
                    break;
            }
            r2346 += r234 * f6;
        }

        return r15 * r2346;
    }
};
