// Link: https://leetcode.com/problems/count-stepping-numbers-in-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the parent, SC: O(n) where n is the length of the parent
//  Approach: We can use dynamic programming to count the number of stepping numbers in the given range. We will maintain two arrays, one for the current counts and one for the previous counts. We will iterate through the digits of the high and low numbers, updating the counts based on the previous counts and the current digit. We will also keep track of whether the low number is a stepping number or not. Finally, we will calculate the total number of stepping numbers in the range by subtracting the counts for the low number from the counts for the high number, and adding 1 if the low number is a stepping number.
class Solution
{
public:
    static constexpr const int MOD = 1000000007;

    static void resetCounts(long long *counts)
    {
        for (int i = 0; i < 10; ++i)
            counts[i] = 0;
    }

    static void calcCounts(long long *prev, long long *cur, int max = 9)
    {
        for (int i = 0; i <= max; ++i)
            cur[i] = (cur[i] + (i > 0 ? prev[i - 1] : 0) +
                      (i < 9 ? prev[i + 1] : 0)) %
                     MOD;
    }

    static void calcCountsDigit(long long *prev, long long *cur, int digit)
    {
        cur[digit] = (cur[digit] + (digit > 0 ? prev[digit - 1] : 0) +
                      (digit < 9 ? prev[digit + 1] : 0)) %
                     MOD;
    }

    static long long sumCounts(long long *counts)
    {
        long long accum = 0;
        for (int i = 1; i < 10; ++i)
            accum += counts[i];
        return accum;
    }

    static bool isStepping(int a, int b)
    {
        int d = a - b;
        return d == 1 || d == -1;
    }

    int countSteppingNumbers(string low, string high)
    {
        long long all_a[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        long long all_b[10];
        long long *all_prev = all_a;
        long long *all_cur = all_b;

        long long high_a[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        long long high_b[10];
        long long *high_prev = high_a;
        long long *high_cur = high_b;

        long long low_a[10] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        long long low_b[10];
        long long *low_prev = low_a;
        long long *low_cur = low_b;

        int high_last = high.back() - '0';
        for (int j = 1; j <= high_last; ++j)
            high_a[j] = 1;

        int low_last = low.back() - '0';
        for (int j = 1; j <= low_last; ++j)
            low_a[j] = 1;

        long long high_accum = 0;
        long long low_accum = 0;
        bool low_is_stepping = true;
        for (int i = 2; i <= high.size(); ++i)
        {
            resetCounts(all_cur);
            calcCounts(all_prev, all_cur);
            high_accum = (high_accum + sumCounts(all_prev)) % MOD;

            int high_digit = high[high.size() - i] - '0';
            resetCounts(high_cur);
            calcCountsDigit(high_prev, high_cur, high_digit);
            calcCounts(all_prev, high_cur, high_digit - 1);
            swap(high_cur, high_prev);

            if (i <= low.size())
            {
                int low_digit = low[low.size() - i] - '0';
                if (low_is_stepping)
                {
                    if (!isStepping(low_digit, low_last))
                        low_is_stepping = false;
                }
                low_last = low_digit;
                resetCounts(low_cur);
                calcCountsDigit(low_prev, low_cur, low_digit);
                calcCounts(all_prev, low_cur, low_digit - 1);
                swap(low_cur, low_prev);
                low_accum = high_accum;
            }

            swap(all_cur, all_prev);
        }
        high_accum += sumCounts(high_prev);
        low_accum += sumCounts(low_prev);

        long long total =
            ((high_accum - low_accum + (low_is_stepping ? 1 : 0)) % MOD + MOD) %
            MOD;

        return total;
    }
};
