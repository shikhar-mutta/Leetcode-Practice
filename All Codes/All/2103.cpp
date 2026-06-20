// Link: https://leetcode.com/problems/rings-and-rods/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int countPoints(string rings)
    {
        int mask[10] = {0}; // per rod: bit0=R, bit1=G, bit2=B
        for (int i = 0; i + 1 < (int)rings.size(); i += 2)
        {
            int rod = rings[i + 1] - '0';
            int bit = rings[i] == 'R' ? 0 : rings[i] == 'G' ? 1
                                                            : 2;
            mask[rod] |= 1 << bit;
        }
        // a rod with all three colors has mask 0b111 = 7
        int cnt = 0;
        for (int m : mask)
            if (m == 7)
                cnt++;
        return cnt;
    }
};
