// Link: https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the length of the string s.
// SC: O(n), where n is the length of the string s.
// Approach:
//  1. We first calculate the maximum number of steps we can take in each direction (up, down, left, right) from the starting position. This is done by calculating the distance from the starting position to the edges of the grid.
//  2. We then iterate through the string s in reverse order, keeping track of the current position (x, y) and the earliest index we can reach that position. We use two unordered maps, reachX and reachY, to store the earliest index we can reach each x and y coordinate, respectively.
//  3. For each character in the string s, we update the current position (x, y) based on the direction of the character. We then check if we can reach the current position (x, y) from the starting position without going out of bounds. If we can, we update the earliest index we can reach that position in the reachX and reachY maps. We also check if we can reach the current position (x, y) from the starting position without going out of bounds in any of the four directions (up, down, left, right). If we can, we update the earliest index we can reach that position in the reachX and reachY maps. We then calculate the number of steps we can take from the current index to the end of the string s without going out of bounds and store it in the ans vector.
class Solution
{
public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        const int m = s.length();
        const int uMost = startPos[0] + 1;
        const int dMost = n - startPos[0];
        const int lMost = startPos[1] + 1;
        const int rMost = n - startPos[1];
        const unordered_map<char, pair<int, int>> moves{
            {'L', {0, -1}},
            {'R', {0, 1}},
            {'U', {-1, 0}},
            {'D', {1, 0}},
        };

        vector<int> ans(m);
        unordered_map<int, int> reachX{{0, m}};
        unordered_map<int, int> reachY{{0, m}};
        int x = 0;
        int y = 0;

        for (int i = m - 1; i >= 0; --i)
        {
            const auto &[dx, dy] = moves.at(s[i]);
            x -= dx;
            y -= dy;
            reachX[x] = i;
            reachY[y] = i;
            int out = INT_MAX;
            if (const auto it = reachX.find(x - uMost); it != reachX.cend())
                out = min(out, it->second);
            if (const auto it = reachX.find(x + dMost); it != reachX.cend())
                out = min(out, it->second);
            if (const auto it = reachY.find(y - lMost); it != reachY.cend())
                out = min(out, it->second);
            if (const auto it = reachY.find(y + rMost); it != reachY.cend())
                out = min(out, it->second);
            ans[i] = out == INT_MAX ? m - i : out - i - 1;
        }

        return ans;
    }
};
