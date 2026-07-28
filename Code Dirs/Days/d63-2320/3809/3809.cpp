// Link: https://leetcode.com/problems/best-reachable-tower/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: filter towers within radius using squared-distance
// comparison (avoids floating point), then pick the tower with highest
// quality, breaking ties by lexicographically smallest (x, y).
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        long long r2 = (long long)radius * radius;
        int bestQ = -1;
        vector<int> best = {-1, -1};
        for (auto& tw : towers) {
            long long dx = tw[0] - center[0], dy = tw[1] - center[1];
            if (dx * dx + dy * dy > r2) continue;
            int q = tw[2];
            vector<int> coord = {tw[0], tw[1]};
            if (q > bestQ || (q == bestQ && coord < best)) {
                bestQ = q;
                best = coord;
            }
        }
        return best;
    }
};
