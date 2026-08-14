// Link: https://leetcode.com/problems/design-sql/description/

#include <bits/stdc++.h>
using namespace std;

class SQL {
    unordered_map<string, map<int, vector<string>>> tables;
    unordered_map<string, int> nextId;
public:
    SQL(vector<string>& names, vector<int>& columns) {
        for (auto &n : names) {
            tables[n] = {};
            nextId[n] = 1;
        }
    }

    bool insertRow(string name, vector<string> row) {
        int id = nextId[name]++;
        tables[name][id] = row;
        return true;
    }

    void removeRow(string name, int rowId) {
        tables[name].erase(rowId);
    }

    string selectCell(string name, int rowId, int columnId) {
        return tables[name][rowId][columnId - 1];
    }

    vector<string> exportTable(string name) {
        vector<string> res;
        for (auto &[id, row] : tables[name]) {
            string s = to_string(id);
            for (auto &v : row) s += "," + v;
            res.push_back(s);
        }
        return res;
    }
};
