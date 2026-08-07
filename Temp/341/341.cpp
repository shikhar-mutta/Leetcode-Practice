// Link: https://leetcode.com/problems/flatten-nested-list-iterator/description/

#include <bits/stdc++.h>
using namespace std;

class NestedInteger {
    bool isInt;
    int val;
    vector<NestedInteger> list;
public:
    NestedInteger() : isInt(false), val(0) {}
    NestedInteger(int v) : isInt(true), val(v) {}
    bool isInteger() const { return isInt; }
    int getInteger() const { return val; }
    void add(const NestedInteger& ni) { isInt = false; list.push_back(ni); }
    const vector<NestedInteger>& getList() const { return list; }
};

// TC: O(n) total flatten, O(1) amortized next/hasNext  SC: O(n)
// Approach: flatten the nested structure into a flat vector<int> up front,
// then iterate with an index pointer
class NestedIterator {
    vector<int> flat;
    int idx = 0;

    void flatten(const vector<NestedInteger>& nestedList) {
        for (auto& ni : nestedList) {
            if (ni.isInteger()) flat.push_back(ni.getInteger());
            else flatten(ni.getList());
        }
    }

public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        flatten(nestedList);
    }

    int next() {
        return flat[idx++];
    }

    bool hasNext() {
        return idx < (int)flat.size();
    }
};
