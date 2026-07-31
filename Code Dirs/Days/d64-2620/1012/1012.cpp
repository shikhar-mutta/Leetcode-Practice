// Link: https://leetcode.com/problems/numbers-with-repeated-digits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(logN)  SC: O(logN)
// Approach: Count the numbers with distinct digits and subtract from n. For each length of number, count the distinct numbers using permutations. For the same length as n, count the distinct numbers that are less than or equal to n by checking each digit and counting the available choices for the remaining digits.
class Solution
{
public:
    int numDupDigitsAtMostN(int n)
    {
        string s = to_string(n);
        int L = s.size();

        auto perm = [](int avail, int choose)
        {
            long long r = 1;
            for (int i = 0; i < choose; i++)
                r *= (avail - i);
            return r;
        };

        long long distinctCount = 0;
        for (int len = 1; len < L; len++)
        {
            distinctCount += 9 * perm(9, len - 1);
        }

        vector<bool> used(10, false);
        bool ok = true;
        for (int i = 0; i < L; i++)
        {
            int d = s[i] - '0';
            int startDigit = (i == 0) ? 1 : 0;
            for (int cand = startDigit; cand < d; cand++)
            {
                if (used[cand])
                    continue;
                int remainingSlots = L - i - 1;
                int availableDigits = 10 - (i + 1);
                distinctCount += perm(availableDigits, remainingSlots);
            }
            if (used[d])
            {
                ok = false;
                break;
            }
            used[d] = true;
        }
        if (ok)
            distinctCount += 1;

        return (int)(n - distinctCount);
    }
};
