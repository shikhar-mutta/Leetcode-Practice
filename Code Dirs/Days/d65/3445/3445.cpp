// Link: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        const int INF = INT_MAX / 2;
        int ans = INT_MIN;

        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                if (x == y) continue;
                char cx0 = '0' + x, cy0 = '0' + y;

                int bucket[2][2];
                for (int a = 0; a < 2; a++) for (int b = 0; b < 2; b++) bucket[a][b] = INF;

                int cx = 0, cy = 0; // prefix counts at current r
                int lcx = 0, lcy = 0; // prefix counts at l_inserted
                int l_inserted = 0;
                int lastYBound = -1;

                for (int r = 1; r <= n; r++) {
                    char c = s[r-1];
                    if (c == cx0) cx++;
                    if (c == cy0) { cy++; lastYBound = r - 1; }

                    if (lastYBound == -1) continue;
                    int U = min(r - k, lastYBound);
                    while (l_inserted <= U) {
                        int pa = lcx & 1, pb = lcy & 1;
                        int val = lcx - lcy;
                        if (val < bucket[pa][pb]) bucket[pa][pb] = val;
                        // advance lcx,lcy to position l_inserted+1
                        if (l_inserted < n) {
                            if (s[l_inserted] == cx0) lcx++;
                            if (s[l_inserted] == cy0) lcy++;
                        }
                        l_inserted++;
                    }

                    if (r < k) continue;
                    int wantCxParity = 1 - (cx & 1);
                    int wantCyParity = cy & 1;
                    int bm = bucket[wantCxParity][wantCyParity];
                    if (bm < INF) {
                        int candidate = (cx - cy) - bm;
                        ans = max(ans, candidate);
                    }
                }
            }
        }

        return ans;
    }
};
