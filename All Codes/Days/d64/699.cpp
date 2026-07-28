// Link: https://leetcode.com/problems/falling-squares/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n)
// Approach: for each square, find the max height among all previously
// placed squares whose x-interval overlaps it, land on top of that
// (height = maxBelow + side), record its interval/height, and track the
// running overall maximum for the answer sequence.
class Solution
{
public:
    vector<int> fallingSquares(vector<vector<int>> &positions)
    {
        vector<array<long long, 3>> placed; // left, right, top
        vector<int> ans;
        long long overallMax = 0;
        for (auto &p : positions)
        {
            long long l = p[0], side = p[1], r = l + side;
            long long base = 0;
            for (auto &q : placed)
            {
                if (l < q[1] && r > q[0])
                    base = max(base, q[2]);
            }
            long long top = base + side;
            placed.push_back({l, r, top});
            overallMax = max(overallMax, top);
            ans.push_back((int)overallMax);
        }
        return ans;
    }
};
