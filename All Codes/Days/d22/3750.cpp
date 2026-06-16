// Link: https://leetcode.com/problems/minimum-number-of-flips-to-reverse-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n), SC: O(log n)
    int minimumFlips(int n)
    {
        // build binary string (MSB first, no leading zeros)
        string b;
        for (int t = n; t; t >>= 1)
            b += char('0' + (t & 1));
        // reverse(b.begin(), b.end());
        // flips = positions where a bit differs from its mirror position
        int L = b.size(), flips = 0;
        for (int i = 0; i < L; ++i)
            if (b[i] != b[L - 1 - i])
                flips++;
        return flips;
    }
};
