// Link: https://leetcode.com/problems/design-spreadsheet/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) per op SC: O(cells set)
// Approach: hashmap from cell name to value (missing = 0). getValue
// strips the leading '=', splits on '+' into two operands, and resolves
// each operand as either an integer literal or a cell lookup.
class Spreadsheet {
    unordered_map<string, int> cells;
    int resolve(const string& s) {
        if (isdigit(s[0]) || s[0] == '-') return stoi(s);
        auto it = cells.find(s);
        return it != cells.end() ? it->second : 0;
    }
public:
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) {
        cells[cell] = value;
    }

    void resetCell(string cell) {
        cells.erase(cell);
    }

    int getValue(string formula) {
        string expr = formula.substr(1);
        int pos = expr.find('+');
        return resolve(expr.substr(0, pos)) + resolve(expr.substr(pos + 1));
    }
};
