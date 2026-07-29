// Link: https://leetcode.com/problems/maximum-value-sum-by-placing-three-rooks-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(R*C log C + R^3), SC: O(R)
// Approach: an optimal rook can always be chosen among the top 3 values of its row (swapping a
// lower-ranked pick for a higher one in the same row, avoiding column conflicts, never decreases
// the sum). Keep the top 3 (value, col) per row, then brute-force all triples of rows (choosing
// one of up to 3 candidates per row) checking column distinctness.
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int R = board.size(), C = board[0].size();
        vector<vector<pair<int,int>>> top(R); // (value, col), top 3 per row
        for (int r = 0; r < R; r++) {
            vector<pair<int,int>> row;
            for (int c = 0; c < C; c++) row.push_back({board[r][c], c});
            sort(row.begin(), row.end(), greater<>());
            for (int i = 0; i < min(3, (int)row.size()); i++) top[r].push_back(row[i]);
        }

        long long ans = LLONG_MIN;
        for (int r1 = 0; r1 < R; r1++) {
            for (int r2 = r1+1; r2 < R; r2++) {
                for (int r3 = r2+1; r3 < R; r3++) {
                    for (auto& [v1, c1] : top[r1]) {
                        for (auto& [v2, c2] : top[r2]) {
                            if (c2 == c1) continue;
                            for (auto& [v3, c3] : top[r3]) {
                                if (c3 == c1 || c3 == c2) continue;
                                ans = max(ans, (long long)v1 + v2 + v3);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
