// Link: https://leetcode.com/problems/maximum-value-sum-by-placing-three-rooks-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(R^2) (with R,C <= 500), SC: O(R)
// Approach: precompute each row's top 3 (value, col) cells (a row's optimal pick, when excluding
// up to 2 specific columns, is always among its top 3). For a fixed excluded row and column,
// solve "best 2 rooks among the rest": collect each remaining row's top-2 cells avoiding the
// excluded column, then try each of the top few (by value) as the "first" rook and greedily pair
// it with the best remaining candidate of a different row/column — trying only the single
// overall-best candidate as "first" isn't safe because value ties can force a bad column choice,
// so a handful of top candidates are tried to be robust to that. Loop the third rook over every
// row's top 3 cells and combine with that 2-rook solver.
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int R = board.size(), C = board[0].size();
        const long long NEG = LLONG_MIN / 2;

        vector<vector<pair<int,int>>> top3(R);
        for (int r = 0; r < R; r++) {
            vector<pair<int,int>> row;
            for (int c = 0; c < C; c++) row.push_back({board[r][c], c});
            sort(row.begin(), row.end(), greater<>());
            for (int i = 0; i < min(3, (int)row.size()); i++) top3[r].push_back(row[i]);
        }

        auto bestPairExcluding = [&](int exRow, int exCol) -> long long {
            // for each eligible row, keep up to its top 2 cells (after skipping exCol)
            struct Cand { long long v; int row, col; };
            vector<Cand> cands;
            for (int r = 0; r < R; r++) {
                if (r == exRow) continue;
                int kept = 0;
                for (auto& [vv, cc] : top3[r]) {
                    if (cc == exCol) continue;
                    cands.push_back({vv, r, cc});
                    if (++kept == 2) break;
                }
            }
            if (cands.size() < 2) return NEG;
            sort(cands.begin(), cands.end(), [](auto& a, auto& b){ return a.v > b.v; });
            long long best = NEG;
            int tries = min((int)cands.size(), 5);
            for (int i = 0; i < tries; i++) {
                long long best2v = NEG;
                for (auto& cd : cands) {
                    if (cd.row == cands[i].row || cd.col == cands[i].col) continue;
                    best2v = max(best2v, cd.v);
                }
                if (best2v > NEG) best = max(best, cands[i].v + best2v);
            }
            return best;
        };

        long long ans = NEG;
        for (int r = 0; r < R; r++) {
            for (auto& [v, c] : top3[r]) {
                long long pairVal = bestPairExcluding(r, c);
                if (pairVal > NEG) ans = max(ans, pairVal + v);
            }
        }
        return ans;
    }
};
