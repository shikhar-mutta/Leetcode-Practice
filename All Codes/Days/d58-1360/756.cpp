// Link: https://leetcode.com/problems/pyramid-transition-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(3^n) where n is the length of the bottom string.
// SC: O(n^2) where n is the length of the bottom string.
// Approach: Backtracking
// 1. Create a 3D vector to store the allowed transitions for each pair of characters.
// 2. Convert the bottom string to a vector of characters.
// 3. Use a recursive function to build the pyramid from the bottom to the top.

class Solution
{
    bool canBuild(int level, int index, int size, vector<string> &pyr, vector<vector<vector<char>>> &tri)
    {
        if (index == 0 || index >= size)
            return true;
        for (char i : tri[pyr[level][index - 1]][pyr[level][index]])
        {
            pyr[level - 1][index - 1] = i;
            if (canBuild(level - 1, index - 1, index, pyr, tri))
                if (canBuild(level, index + 1, size, pyr, tri))
                    return true;
        }
        return false;
    }

public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        vector<vector<vector<char>>> tri(6, vector<vector<char>>(6));
        for (auto &t : allowed)
            tri[t[0] - 'A'][t[1] - 'A'].push_back(t[2] - 'A');
        for (auto &c : bottom)
            c -= 'A';
        vector<string> pyr(bottom.size(), bottom);
        return canBuild(bottom.size() - 1, 1, bottom.size(), pyr, tri);
    }
};