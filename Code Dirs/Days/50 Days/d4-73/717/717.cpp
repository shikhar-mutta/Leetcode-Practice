// Link: https://leetcode.com/problems/1-bit-and-2-bit-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int n = bits.size(), last;

        for (int i = 0; i < n; i++)
        {
            if (bits[i])
            {
                last = 2;
                i++;
            }
            else
            {
                last = 1;
            }
        }
        return last == 1;
    }
};
