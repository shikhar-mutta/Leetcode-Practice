// Link: https://leetcode.com/problems/binary-gap/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n), SC: O(1)
    // Use pre index to record pos
    int binaryGap(int n)
    {
        int gap = 0, prev = -1;
        for (int i = 0; n; ++i, n >>= 1)
            if (n & 1)
            {
                if (prev != -1)
                    gap = max(gap, i - prev);
                prev = i;
            }
        return gap;
    }
};
