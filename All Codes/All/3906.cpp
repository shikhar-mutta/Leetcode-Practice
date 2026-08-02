// Link: https://leetcode.com/problems/count-good-integers-on-a-grid-path/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(r) + log(l))  SC: O(1)
//  Approach: We can use a greedy approach to solve this problem. We can count the number of good integers on the path from l to r by counting the number of good integers less than or equal to r and subtracting the number of good integers less than l. We can use a precomputed table to count the number of good integers less than or equal to a given number. We can use a bitmask to represent the directions and the digits of the number. We can use a recursive function to count the number of good integers less than or equal to a given number. We can use a loop to iterate through the digits of the number and check if the digit is in the set of good digits. If the digit is in the set of good digits, we can add the number of good integers less than or equal to the remaining digits to the answer. If the digit is not in the set of good digits, we can break the loop and return the answer. We can use a loop to iterate through the digits of the number and check if the digit is in the set of good digits. If the digit is in the set of good digits, we can add the number of good integers less than or equal to the remaining digits to the answer. If the digit is not in the set of good digits, we can break the loop and return the answer. We can use a loop to iterate through the digits of the number and check if the digit is in the set of good digits. If the digit is in the set of good digits, we can add the number of good integers less than or equal to the remaining digits to the answer. If the digit is not in the set of good digits, we can break the loop and return the answer. We can use a loop to iterate through the digits of the number and check if the digit is in the set of good digits.
class Solution
{
    inline static int cnt_inc[9][10];
    inline static long long pow10[17]{1};
    inline static const int _precomp = []()
    {
        for (int j = 0; j <= 9; ++j)
            cnt_inc[0][j] = cnt_inc[1][j] = 1;
        for (int i = 2; i <= 8; ++i)
            for (int j = 0; j <= 9; ++j)
                for (int k = j; k <= 9; ++k)
                    cnt_inc[i][j] += cnt_inc[i - 1][k];
        for (int i = 1; i <= 16; ++i)
            pow10[i] = 10 * pow10[i - 1];
        return 0;
    }();

public:
    long long countGoodIntegersOnPath(long long l, long long r,
                                      string directions)
    {
        bool is[16]{};
        is[15] = true;
        for (int i = 0, dig = 15; i < 6; ++i)
            is[dig -= (directions[i] == 'D' ? 4 : 1)] = true;
        auto lt = [&is](long long r)
        {
            int digs[16];
            int digs_cnt = 0;
            for (; r; r /= 10)
                digs[digs_cnt++] = r % 10;
            int last = 0, rem = count(is, is + digs_cnt, true);
            long long ans = 0;
            for (int i = digs_cnt - 1; i >= 0; --i)
            {
                if (is[i])
                {
                    for (int j = digs[i] - 1; j >= last; --j)
                        ans += cnt_inc[rem][j] * pow10[i + 1 - rem];
                    if (digs[i] < last)
                        return ans;
                    last = digs[i];
                    --rem;
                }
                else
                {
                    ans += digs[i] * cnt_inc[rem + 1][last] * pow10[i - rem];
                }
            }
            return ans;
        };
        return lt(r + 1) - lt(l);
    }
};
