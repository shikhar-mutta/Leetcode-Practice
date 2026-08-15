// Link: https://leetcode.com/problems/mini-parser/description/

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
    void setInteger(int v) { isInt = true; val = v; }
    void add(const NestedInteger& ni) { isInt = false; list.push_back(ni); }
    const vector<NestedInteger>& getList() const { return list; }
};

// TC: O(n)  SC: O(depth)
// Approach: recursive-descent parse; '[' starts a list, ']' ends it, commas
// separate elements, otherwise parse a (possibly negative) integer
class Solution {
    string s;
    int pos = 0;

    NestedInteger parseValue() {
        if (s[pos] == '[') {
            NestedInteger ni;
            pos++; // consume '['
            if (s[pos] == ']') { pos++; return ni; }
            while (true) {
                ni.add(parseValue());
                if (s[pos] == ',') { pos++; continue; }
                break;
            }
            pos++; // consume ']'
            return ni;
        }
        int start = pos;
        while (pos < (int)s.size() && (isdigit(s[pos]) || s[pos] == '-')) pos++;
        return NestedInteger(stoi(s.substr(start, pos - start)));
    }

public:
    NestedInteger deserialize(string str) {
        s = str;
        pos = 0;
        return parseValue();
    }
};
