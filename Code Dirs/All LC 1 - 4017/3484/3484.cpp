// Link: https://leetcode.com/problems/design-spreadsheet/description/

#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
    unordered_map<string, int> cells;

    long long resolve(const string& tok) {
        if (isdigit(tok[0])) return stoll(tok);
        auto it = cells.find(tok);
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
        string body = formula.substr(1);
        int plus = body.find('+');
        string x = body.substr(0, plus);
        string y = body.substr(plus + 1);
        return (int)(resolve(x) + resolve(y));
    }
};
