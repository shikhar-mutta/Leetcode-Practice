// Link: https://leetcode.com/problems/grid-illumination/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> rowCnt, colCnt, diagCnt, antiCnt;
        set<pair<int,int>> lampSet;

        for (auto& l : lamps) {
            int r = l[0], c = l[1];
            if (lampSet.count({r, c})) continue;
            lampSet.insert({r, c});
            rowCnt[r]++;
            colCnt[c]++;
            diagCnt[r - c]++;
            antiCnt[r + c]++;
        }

        vector<int> res;
        int dr[] = {-1,-1,-1,0,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,0,1,-1,0,1};
        for (auto& q : queries) {
            int r = q[0], c = q[1];
            bool lit = rowCnt[r] > 0 || colCnt[c] > 0 || diagCnt[r-c] > 0 || antiCnt[r+c] > 0;
            res.push_back(lit ? 1 : 0);
            for (int d = 0; d < 9; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if (lampSet.count({nr, nc})) {
                    lampSet.erase({nr, nc});
                    rowCnt[nr]--;
                    colCnt[nc]--;
                    diagCnt[nr-nc]--;
                    antiCnt[nr+nc]--;
                }
            }
        }
        return res;
    }
};
