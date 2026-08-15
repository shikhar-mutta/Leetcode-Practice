// Link: https://leetcode.com/problems/nested-list-weight-sum/description/

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
// Approach: DFS tracking depth, sum integer * depth, recurse into lists with depth+1
class Solution {
    int helper(const vector<NestedInteger>& nestedList, int depth) {
        int sum = 0;
        for (auto& ni : nestedList) {
            if (ni.isInteger()) sum += ni.getInteger() * depth;
            else sum += helper(ni.getList(), depth + 1);
        }
        return sum;
    }

public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return helper(nestedList, 1);
    }
};
