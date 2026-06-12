// Link: https://leetcode.com/problems/robot-return-to-origin/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC = O(n), SC = O(1)
    bool judgeCircle(string moves)
    {
        int x = 0, y = 0;
        for (char move : moves)
        {
            switch (move)
            {
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            }
        }
        return x == 0 && y == 0;
    }
};
