// Link: https://leetcode.com/problems/paint-house/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: DP with 3 rolling values (min cost ending each house on red/blue/green); each color
// picks the min of the other two colors' previous costs
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int r = 0, b = 0, g = 0;
        for (auto& c : costs) {
            int nr = c[0] + min(b, g);
            int nb = c[1] + min(r, g);
            int ng = c[2] + min(r, b);
            r = nr; b = nb; g = ng;
        }
        return min({r, b, g});
    }
};
