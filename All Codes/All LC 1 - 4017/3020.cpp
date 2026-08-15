// Link: https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + sqrt(maxVal)), SC: O(sqrt(maxVal))
// Approach: Bitset-based version of the doubling-square-chain idea (x, x^2,
// x^4, ...). freq1/freq2 mark values seen once/twice among nums < sqrt(maxVal);
// sqset flags values whose square root is also present, used to detect a
// full even-length chain (peak reused as its own square). len2end bounds how
// far up the chain still needs checking once a candidate maxlen is known.
constexpr int len2end[4]{31622, 177, 13, 3};

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        bitset<31623> freq1, freq2, sqset;
        int ones = 0, minv = 31623, maxv = 0;
        for (int v : nums)
        {
            if (v == 1)
                ones++;
            else if (v < 31623)
            {
                if (!freq1[v])
                {
                    freq1[v] = 1;
                }
                else
                {
                    freq2[v] = 1;
                    minv = min(minv, v);
                    maxv = max(maxv, v);
                }
            }
            else
            {
                int r = sqrt(v);
                if (r * r == v)
                    sqset[r] = 1;
            }
        }
        int maxlen = ones > 0 ? (ones - 1) / 2 : 0;
        if (maxlen >= 4)
            return maxlen * 2 + 1;
        maxv = min(maxv, len2end[maxlen]);
        int i = minv;
        while (i <= min(3, maxv))
        {
            if (freq2[i])
            {
                int i2 = i * i;
                if (freq2[i2])
                {
                    int i4 = i2 * i2;
                    if (freq2[i4])
                    {
                        int i8 = i4 * i4;
                        if (freq2[i8])
                        {
                            if (sqset[i8])
                                return 9;
                            maxlen = 3;
                            maxv = min(maxv, 3);
                        }
                        else
                        {
                            maxlen = max(maxlen, 2 + freq1[i8]);
                            maxv = min(maxv, len2end[maxlen]);
                        }
                    }
                    else
                    {
                        maxlen = max(maxlen, 1 + freq1[i4]);
                        maxv = min(maxv, len2end[maxlen]);
                    }
                }
                else
                {
                    maxlen = max(maxlen, (int)freq1[i2]);
                    maxv = min(maxv, len2end[maxlen]);
                }
            }
            ++i;
        }
        if (i > maxv)
            return maxlen * 2 + 1;
        while (i <= min(13, maxv))
        {
            if (freq2[i])
            {
                int i2 = i * i;
                if (freq2[i2])
                {
                    int i4 = i2 * i2;
                    if (freq2[i4])
                    {
                        if (sqset[i4])
                            return 7;
                        maxlen = 2;
                        maxv = min(maxv, 13);
                    }
                    else
                    {
                        maxlen = max(maxlen, 1 + freq1[i4]);
                        maxv = min(maxv, len2end[maxlen]);
                    }
                }
                else
                {
                    maxlen = max(maxlen, (int)freq1[i2]);
                    maxv = min(maxv, len2end[maxlen]);
                }
            }
            ++i;
        }
        if (i > maxv)
            return maxlen * 2 + 1;
        while (i <= min(177, maxv))
        {
            if (freq2[i])
            {
                int i2 = i * i;
                if (freq2[i2])
                {
                    if (sqset[i2])
                        return 5;
                    maxlen = 1;
                    maxv = min(maxv, 177);
                }
                else
                {
                    maxlen = max(maxlen, (int)freq1[i2]);
                    maxv = min(maxv, len2end[maxlen]);
                }
            }
            ++i;
        }
        if (i > maxv)
            return maxlen * 2 + 1;
        while (i <= maxv)
        {
            if (freq2[i] && sqset[i])
                return 3;
            ++i;
        }
        return 1;
    }
};