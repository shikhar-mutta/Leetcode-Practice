// Link: https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        int twos = 0;
        for (int c : colsum) if (c == 2) twos++;
        if (twos > upper || twos > lower) return {};
        int upperOnes = upper - twos;

        vector<int> row1(n, 0), row2(n, 0);
        for (int i = 0; i < n; i++) {
            if (colsum[i] == 2) {
                row1[i] = row2[i] = 1;
            } else if (colsum[i] == 1) {
                if (upperOnes > 0) { row1[i] = 1; upperOnes--; }
                else { row2[i] = 1; }
            }
        }
        int su = 0, sl = 0;
        for (int i = 0; i < n; i++) { su += row1[i]; sl += row2[i]; }
        if (su != upper || sl != lower) return {};
        return {row1, row2};
    }
};
