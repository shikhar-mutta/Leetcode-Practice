// Link: https://leetcode.com/problems/squirrel-simulation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: total distance = 2*sum(tree-to-nut) + savings from starting at
// one nut instead of the tree; pick the nut minimizing extra distance
// (dist(squirrel,nut) - dist(tree,nut))
class Solution {
    int manhattan(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int total = 0;
        int minExtra = INT_MAX;
        for (auto& nut : nuts) {
            int treeToNut = manhattan(tree, nut);
            total += 2 * treeToNut;
            int extra = manhattan(squirrel, nut) - treeToNut;
            minExtra = min(minExtra, extra);
        }
        return total + minExtra;
    }
};
