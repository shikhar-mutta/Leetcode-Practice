// Link: https://leetcode.com/problems/design-excel-sum-formula/description/

#include <bits/stdc++.h>
using namespace std;

// TC: get/set O(cells referenced) amortized, sum O(range size) SC: O(rows*cols)
// Approach: store a grid of raw values plus, per cell, an optional list of referenced cells (formula). get() recursively sums referenced cells' get() results; set() clears any formula on that cell.
class Excel {
    vector<vector<int>> grid;
    vector<vector<vector<pair<int,int>>>> formula; // list of referenced (row,col) per cell, empty if no formula
public:
    Excel(int height, char width) {
        int w = width - 'A' + 1;
        grid.assign(height+1, vector<int>(w+1, 0));
        formula.assign(height+1, vector<vector<pair<int,int>>>(w+1));
    }

    void set(int row, char column, int val) {
        int col = column - 'A' + 1;
        grid[row][col] = val;
        formula[row][col].clear();
    }

    int get(int row, char column) {
        int col = column - 'A' + 1;
        if (formula[row][col].empty()) return grid[row][col];
        int sum = 0;
        for (auto& [r, c] : formula[row][col]) sum += get(r, (char)('A'+c-1));
        return sum;
    }

    int sum(int row, char column, vector<string> numbers) {
        int col = column - 'A' + 1;
        vector<pair<int,int>> refs;
        for (auto& tok : numbers) {
            size_t colon = tok.find(':');
            if (colon == string::npos) {
                char c = tok[0];
                int r = stoi(tok.substr(1));
                refs.push_back({r, c-'A'+1});
            } else {
                string a = tok.substr(0, colon), b = tok.substr(colon+1);
                char c1 = a[0]; int r1 = stoi(a.substr(1));
                char c2 = b[0]; int r2 = stoi(b.substr(1));
                for (int r = r1; r <= r2; r++)
                    for (int c = c1-'A'+1; c <= c2-'A'+1; c++)
                        refs.push_back({r, c});
            }
        }
        formula[row][col] = refs;
        int val = get(row, column);
        grid[row][col] = val;
        return val;
    }
};
