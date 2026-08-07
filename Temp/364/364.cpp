// Link: https://leetcode.com/problems/nested-list-weight-sum-ii/description/

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

// TC: O(n)  SC: O(depth)
// Approach: weight = maxDepth - depth + 1; equivalently sum each level's
// total once, then accumulate (running level sum added every level, so
// shallower levels get counted more times)
class Solution {
    void collect(const vector<NestedInteger>& nestedList, int depth, vector<int>& levelSum) {
        if ((int)levelSum.size() <= depth) levelSum.resize(depth + 1, 0);
        for (auto& ni : nestedList) {
            if (ni.isInteger()) levelSum[depth] += ni.getInteger();
            else collect(ni.getList(), depth + 1, levelSum);
        }
    }

public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> levelSum;
        collect(nestedList, 0, levelSum);
        int maxDepth = levelSum.size();
        int total = 0;
        for (int i = 0; i < maxDepth; i++) total += levelSum[i] * (maxDepth - i);
        return total;
    }
};
