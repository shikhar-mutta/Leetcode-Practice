// Link: https://leetcode.com/problems/grid-illumination/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(lamps + queries)  SC: O(lamps)
// Approach: track lit counts per row, column, diagonal (r-c), and
// anti-diagonal (r+c) in hashmaps (avoids an O(n^2) grid). For each
// query, the cell is lit iff any of its four counts is > 0; then turn
// off that lamp and its 8 neighbors (removing them from all four maps
// if present) before moving to the next query.
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> rowCnt, colCnt, diagCnt, antiCnt;
        unordered_set<long long> lampSet;

        auto key = [&](int r, int c) { return (long long)r * n + c; };

        for (auto& l : lamps) {
            int r = l[0], c = l[1];
            long long k = key(r, c);
            if (lampSet.count(k)) continue;
            lampSet.insert(k);
            rowCnt[r]++;
            colCnt[c]++;
            diagCnt[r - c]++;
            antiCnt[r + c]++;
        }

        vector<int> ans;
        for (auto& q : queries) {
            int r = q[0], c = q[1];
            bool lit = rowCnt[r] > 0 || colCnt[c] > 0 || diagCnt[r - c] > 0 || antiCnt[r + c] > 0;
            ans.push_back(lit ? 1 : 0);
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int nr = r + dr, nc = c + dc;
                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                    long long k = key(nr, nc);
                    if (!lampSet.count(k)) continue;
                    lampSet.erase(k);
                    rowCnt[nr]--;
                    colCnt[nc]--;
                    diagCnt[nr - nc]--;
                    antiCnt[nr + nc]--;
                }
            }
        }
        return ans;
    }
};
