// Link: https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        // set a bit per distinct letter; pangram when all 26 bits are on
        int mask = 0;
        for (char c : sentence)
            mask |= 1 << (c - 'a');
        return mask == (1 << 26) - 1;
    }
};
