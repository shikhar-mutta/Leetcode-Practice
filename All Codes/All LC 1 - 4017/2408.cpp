// Link: https://leetcode.com/problems/design-sql/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized for ins/rmv/sel; O(rows * columns) for exp
// SC: O(total cells stored)
// Approach: `db` maps table name to its fixed column count. `h` maps table
// name to its rows (each row a vector<string>). ins validates the row's
// width against db before appending. rmv "deletes" a row by clearing its
// vector in place (keeping row IDs stable for later rows, matching the
// problem's 1-indexed, non-reassigned row numbering) rather than erasing
// it from the vector. sel checks bounds and emptiness before indexing, and
// exp skips cleared rows while formatting the rest as
// "rowId,col1,col2,...".
class SQL {
private:
    unordered_map<string, int> db{};
    unordered_map<string, vector<vector<string>>> h{};

public:
    SQL(vector<string>& names, vector<int>& columns) {
        const auto l{int(size(names))};
        for (int i{}; i < l; ++i) {
            db.emplace(names[i], columns[i]);
        }
    }

    bool ins(string name, vector<string> row) {
        auto it{db.find(name)};
        if (it == end(db) or it->second != int(size(row)))
            return false;
        h[name].emplace_back(std::move(row));
        return true;
    }

    void rmv(string name, int rowId) {
        auto it{db.find(name)};
        if (it == end(db))
            return;
        auto ptr{h.find(name)};
        if (ptr == end(h) or ptr->second.size() < rowId)
            return;
        ptr->second[rowId - 1].clear();
    }

    string sel(string name, int rowId, int columnId) {
        auto it{h.find(name)};
        if (it == end(h))
            return "<null>";
        const auto& vec{it->second};
        if (size(vec) < rowId or vec[rowId - 1].empty() or
            vec[rowId - 1].size() < columnId)
            return "<null>";
        return vec[--rowId][--columnId];
    }

    vector<string> exp(string name) {
        auto it{db.find(name)};
        if (it == end(db))
            return {};
        auto ptr{h.find(name)};
        if (ptr == end(h))
            return {};
        const auto& vec{ptr->second};
        if (ranges::empty(vec))
            return {};
        const auto l{int(size(vec))};
        vector<string> ret{};
        ret.reserve(l);
        for (int i{}; i < l; ++i) {
            if (ranges::empty(vec[i]))
                continue;
            string tmp{to_string(i + 1)};
            tmp += ",";
            for (auto&& z : vec[i]) {
                tmp += z;
                tmp += ",";
            }
            tmp.pop_back();
            ret.emplace_back(std::move(tmp));
        }
        return ret;
    }
};
