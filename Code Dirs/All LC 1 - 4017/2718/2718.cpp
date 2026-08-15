// Link: https://leetcode.com/problems/sum-of-matrix-after-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> rowDone(n, false), colDone(n, false);
        int rowsDone = 0, colsDone = 0;
        long long total = 0;

        for (int i = queries.size() - 1; i >= 0; i--) {
            int type = queries[i][0], idx = queries[i][1], val = queries[i][2];
            if (type == 0) {
                if (rowDone[idx]) continue;
                rowDone[idx] = true;
                rowsDone++;
                total += (long long)val * (n - colsDone);
            } else {
                if (colDone[idx]) continue;
                colDone[idx] = true;
                colsDone++;
                total += (long long)val * (n - rowsDone);
            }
        }
        return total;
    }
};
