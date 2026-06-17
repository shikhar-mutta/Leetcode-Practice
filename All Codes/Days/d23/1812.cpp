// Link: https://leetcode.com/problems/determine-color-of-a-chessboard-square/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    bool squareIsWhite(string coordinates)
    {
        // white square iff file + rank have opposite parity (sum is odd)
        return (coordinates[0] + coordinates[1]) % 2 == 1;
    }
};
