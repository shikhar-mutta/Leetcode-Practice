// Link: https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the strings s1 and s2
    // SC: O(1) as we are using a constant amount of extra space for the counters xy and yx
    //  Approach:
    //  1. We will iterate through the strings s1 and s2 and count the number of positions where s1 has 'x' and s2 has 'y' (xy)
    //     and the number of positions where s1 has 'y' and s2 has 'x' (yx).
    //  2. If the sum of xy and yx is odd, it is impossible to make the strings equal, so we return -1.
    //  3. The minimum number of swaps needed to make the strings equal is given by the formula:
    //     xy / 2 + yx / 2 + (xy % 2) * 2. This accounts for the pairs of mismatched characters and any remaining single mismatches.
    //  4. We return the calculated number of swaps as the final result.
    int minimumSwap(string s1, string s2)
    {
        int xy = 0, yx = 0;
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] == 'x' && s2[i] == 'y')
                ++xy;
            else if (s1[i] == 'y' && s2[i] == 'x')
                ++yx;
        }
        if ((xy + yx) % 2)
            return -1;
        return xy / 2 + yx / 2 + (xy % 2) * 2;
    }
};