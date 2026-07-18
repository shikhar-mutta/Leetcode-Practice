// Link: https://leetcode.com/problems/furthest-point-from-origin/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int furthestDistanceFromOrigin(string moves)
    {
        // fixed displacement is |L - R|; every '_' can extend it in the same direction
        int l = count(moves.begin(), moves.end(), 'L');
        int r = count(moves.begin(), moves.end(), 'R');
        int blanks = moves.size() - l - r;
        return abs(l - r) + blanks;
    }
};
