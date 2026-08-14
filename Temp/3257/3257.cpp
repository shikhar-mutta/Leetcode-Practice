// Link: https://leetcode.com/problems/maximum-value-sum-by-placing-three-rooks-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();

        // top3ColVal[row] = top-3 (value,col) in that row
        vector<vector<pair<int,int>>> top3ColVal(m);
        for (int i = 0; i < m; i++) {
            vector<pair<int,int>> row;
            for (int j = 0; j < n; j++) row.push_back({board[i][j], j});
            sort(row.begin(), row.end(), greater<>());
            int keep = min((int)row.size(), 3);
            top3ColVal[i].assign(row.begin(), row.begin() + keep);
        }

        // top3RowVal[col] = top-3 (value,row) in that column
        vector<vector<pair<int,int>>> top3RowVal(n);
        for (int j = 0; j < n; j++) {
            vector<pair<int,int>> col;
            for (int i = 0; i < m; i++) col.push_back({board[i][j], i});
            sort(col.begin(), col.end(), greater<>());
            int keep = min((int)col.size(), 3);
            top3RowVal[j].assign(col.begin(), col.begin() + keep);
        }

        long long best3 = LLONG_MIN;

        for (int r1 = 0; r1 < m; r1++) {
            for (int r2 = r1 + 1; r2 < m; r2++) {
                // colVal[c] = best value in column c using a row not in {r1,r2}
                vector<pair<int,int>> colVal(n); // (value, col)
                for (int c = 0; c < n; c++) {
                    int val = INT_MIN;
                    for (auto& [v, r] : top3RowVal[c]) {
                        if (r != r1 && r != r2) { val = v; break; }
                    }
                    colVal[c] = {val, c};
                }
                // top-3 of colVal by value
                vector<pair<int,int>> top3Col = colVal;
                partial_sort(top3Col.begin(), top3Col.begin() + min(3, n), top3Col.end(), greater<>());
                if ((int)top3Col.size() > 3) top3Col.resize(3);

                for (auto& [v1, c1] : top3ColVal[r1]) {
                    for (auto& [v2, c2] : top3ColVal[r2]) {
                        if (c2 == c1) continue;
                        long long pairSum = (long long)v1 + v2;
                        for (auto& [v3, c3] : top3Col) {
                            if (c3 != c1 && c3 != c2) {
                                best3 = max(best3, pairSum + v3);
                                break;
                            }
                        }
                    }
                }
            }
        }

        return best3;
    }
};
