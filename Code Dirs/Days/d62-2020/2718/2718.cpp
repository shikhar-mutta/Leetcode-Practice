// Link: https://leetcode.com/problems/sum-of-matrix-after-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(Q + n)
// SC: O(n)
// Approach: process queries in REVERSE order — a later query always overwrites
// an earlier one on its row/column, so the first time (scanning backward) a
// given row (or column) index is touched is the value that survives in the
// final matrix for every not-yet-finalized cell in it. For a newly-finalized
// row/col of value `val`, it contributes val * (count of columns/rows not yet
// finalized) to the answer, since only those cells still show this value.
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long ans = 0;
        // seen[0] := row, seen[1] := col
        vector<vector<bool>> seen(2, vector<bool>(n));
        // notSet[0] = row, notSet[1] := col
        vector<int> notSet(2, n);

        // Later queries dominate.
        for (int i = queries.size() - 1; i >= 0; --i) {
            const int type = queries[i][0];
            const int index = queries[i][1];
            const int val = queries[i][2];
            if (!seen[type][index]) {
                ans += val * notSet[type ^ 1];
                seen[type][index] = true;
                --notSet[type];
            }
        }
        return ans;
    }
};
