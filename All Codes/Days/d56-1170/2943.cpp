// Link: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + mlogm), SC: O(1)
    //  Approach:
    //   1. Sort the horizontal and vertical bars
    //   2. Find the longest run of consecutive bars in both horizontal and vertical bars
    //   3. The side of the square hole is the minimum of the longest runs
    //   4. Return the area of the square hole
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        auto longestRun = [](vector<int> &bars)
        {
            sort(bars.begin(), bars.end());
            int best = 1, cur = 1;
            for (int i = 1; i < (int)bars.size(); i++)
            {
                cur = (bars[i] == bars[i - 1] + 1) ? cur + 1 : 1;
                best = max(best, cur);
            }
            return best;
        };
        int side = min(longestRun(hBars), longestRun(vBars)) + 1;
        return side * side;
    }
};
