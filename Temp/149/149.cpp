// Link: https://leetcode.com/problems/max-points-on-a-line/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
// Approach: for each anchor point, bucket other points by reduced (dx/gcd, dy/gcd) slope (sign-normalized
// on dx) to avoid float precision; track duplicate-point count separately since slope is undefined for them
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int best = 1;
        for (int i = 0; i < n; i++) {
            unordered_map<long long, int> slopeCount;
            int duplicates = 0, localBest = 0;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                long long dx = points[j][0] - points[i][0];
                long long dy = points[j][1] - points[i][1];
                if (dx == 0 && dy == 0) { duplicates++; continue; }
                long long g = gcd(abs(dx), abs(dy));
                dx /= g; dy /= g;
                if (dx < 0) { dx = -dx; dy = -dy; }
                long long key = dx * 200001LL + (dy + 100000);
                slopeCount[key]++;
                localBest = max(localBest, slopeCount[key]);
            }
            best = max(best, localBest + duplicates + 1);
        }
        return best;
    }
};
