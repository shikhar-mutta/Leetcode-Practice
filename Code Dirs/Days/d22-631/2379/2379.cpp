// Link: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        // each window of size k needs (number of 'W' in it) recolors; minimize that
        int whites = 0;
        for (int i = 0; i < k; ++i)
            whites += (blocks[i] == 'W');
        int best = whites;
        for (int i = k; i < (int)blocks.size(); ++i)
        {
            whites += (blocks[i] == 'W') - (blocks[i - k] == 'W'); // slide window
            best = min(best, whites);
        }
        return best;
    }
};
