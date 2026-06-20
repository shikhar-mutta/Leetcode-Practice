// Link: https://leetcode.com/problems/minimum-moves-to-convert-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the length of the string. SC: O(1)
    int minimumMoves(string s)
    {
        int moves = 0, n = s.size();
        for (int i = 0; i < n;)
        {
            if (s[i] == 'X')
            {
                moves++;
                i += 3;
            } // cover this X and the next 2 chars
            else
                i++;
        }
        return moves;
    }
};
