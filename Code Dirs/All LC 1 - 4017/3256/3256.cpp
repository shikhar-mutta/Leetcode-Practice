// Link: https://leetcode.com/problems/maximum-value-sum-by-placing-three-rooks-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<pair<int,int>>> topPerRow(m); // (value, col)
        for (int i = 0; i < m; i++) {
            vector<pair<int,int>> row;
            for (int j = 0; j < n; j++) row.push_back({board[i][j], j});
            sort(row.begin(), row.end(), greater<>());
            int keep = min((int)row.size(), 3);
            topPerRow[i].assign(row.begin(), row.begin() + keep);
        }

        long long best = LLONG_MIN;
        for (int r1 = 0; r1 < m; r1++) {
            for (int r2 = r1 + 1; r2 < m; r2++) {
                for (int r3 = r2 + 1; r3 < m; r3++) {
                    for (auto& [v1, c1] : topPerRow[r1]) {
                        for (auto& [v2, c2] : topPerRow[r2]) {
                            if (c2 == c1) continue;
                            for (auto& [v3, c3] : topPerRow[r3]) {
                                if (c3 == c1 || c3 == c2) continue;
                                long long sum = (long long)v1 + v2 + v3;
                                best = max(best, sum);
                            }
                        }
                    }
                }
            }
        }
        return best;
    }
};
