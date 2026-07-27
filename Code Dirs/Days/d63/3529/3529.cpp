// Link: https://leetcode.com/problems/count-cells-in-overlapping-horizontal-and-vertical-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(rows * cols) SC: O(rows * cols)
// Approach: horizontal substrings wrap row-major (end of a row continues
// into the next row's start), vertical substrings wrap column-major.
// Flatten the grid both ways into single strings, run KMP to find every
// occurrence of pattern in each, mark the covered cells, and count cells
// marked by both.
class Solution {
    vector<int> kmpMatches(const string& text, const string& pat) {
        int L = pat.size();
        vector<int> fail(L, 0);
        for (int i = 1; i < L; i++) {
            int j = fail[i-1];
            while (j > 0 && pat[i] != pat[j]) j = fail[j-1];
            if (pat[i] == pat[j]) j++;
            fail[i] = j;
        }
        vector<int> starts;
        int j = 0;
        for (int i = 0; i < (int)text.size(); i++) {
            while (j > 0 && text[i] != pat[j]) j = fail[j-1];
            if (text[i] == pat[j]) j++;
            if (j == L) { starts.push_back(i - L + 1); j = fail[j-1]; }
        }
        return starts;
    }
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        int rows = grid.size(), cols = grid[0].size();
        int L = pattern.size();
        vector<vector<bool>> markH(rows, vector<bool>(cols, false));
        vector<vector<bool>> markV(rows, vector<bool>(cols, false));

        string H;
        H.reserve(rows * cols);
        for (int r = 0; r < rows; r++) for (int c = 0; c < cols; c++) H += grid[r][c];
        for (int start : kmpMatches(H, pattern)) {
            for (int k = 0; k < L; k++) {
                int idx = start + k;
                markH[idx / cols][idx % cols] = true;
            }
        }

        string V;
        V.reserve(rows * cols);
        for (int c = 0; c < cols; c++) for (int r = 0; r < rows; r++) V += grid[r][c];
        for (int start : kmpMatches(V, pattern)) {
            for (int k = 0; k < L; k++) {
                int idx = start + k;
                markV[idx % rows][idx / rows] = true;
            }
        }

        int count = 0;
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (markH[r][c] && markV[r][c]) count++;
        return count;
    }
};
