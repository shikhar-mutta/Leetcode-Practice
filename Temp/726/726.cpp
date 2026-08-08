// Link: https://leetcode.com/problems/number-of-atoms/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: stack of atom-count maps, one per nesting level. On '(' push a new map; on ')' pop it, multiply by trailing digits, and merge into the new top; otherwise parse an element name + optional count and merge into current top. Output sorted alphabetically.
class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        int i = 0;
        vector<map<string,int>> stk;
        stk.push_back({});
        while (i < n) {
            char c = formula[i];
            if (c == '(') {
                stk.push_back({});
                i++;
            } else if (c == ')') {
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) i++;
                int mult = (i > start) ? stoi(formula.substr(start, i-start)) : 1;
                auto top = stk.back();
                stk.pop_back();
                for (auto& [name, cnt] : top) stk.back()[name] += cnt * mult;
            } else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) i++;
                string name = formula.substr(start, i-start);
                start = i;
                while (i < n && isdigit(formula[i])) i++;
                int cnt = (i > start) ? stoi(formula.substr(start, i-start)) : 1;
                stk.back()[name] += cnt;
            }
        }
        string res;
        for (auto& [name, cnt] : stk.back()) {
            res += name;
            if (cnt > 1) res += to_string(cnt);
        }
        return res;
    }
};
