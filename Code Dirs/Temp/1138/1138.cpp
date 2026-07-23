// Link: https://leetcode.com/problems/alphabet-board-path/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string alphabetBoardPath(string target)
    {
        string res;
        int r = 0, c = 0; // start at 'a' = (0,0)

        for (char ch : target)
        {
            int nr = (ch - 'a') / 5;
            int nc = (ch - 'a') % 5;

            // move up and left first, down and right last
            while (r > nr)
            {
                res += 'U';
                r--;
            }
            while (c > nc)
            {
                res += 'L';
                c--;
            }
            while (c < nc)
            {
                res += 'R';
                c++;
            }
            while (r < nr)
            {
                res += 'D';
                r++;
            }

            res += '!';
        }
        return res;
    }
};