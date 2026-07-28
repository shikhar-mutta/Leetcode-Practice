// Link: https://leetcode.com/problems/number-of-atoms/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: scan left to right maintaining a stack of atom-count maps
// (one per nesting level). '(' pushes a new map; ')' pops it, multiplies
// by the trailing number, and merges into the map below; an uppercase
// letter starts a new element name (optionally followed by lowercase
// letters and a trailing count) merged into the current top map. Finally
// sort element names and build the output string.
class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        int i = 0;
        vector<map<string,long long>> stack_;
        stack_.push_back({});

        auto readNum = [&](int& idx) -> long long {
            if (idx >= n || !isdigit(formula[idx])) return 1;
            long long num = 0;
            while (idx < n && isdigit(formula[idx])) { num = num * 10 + (formula[idx] - '0'); idx++; }
            return num;
        };

        while (i < n) {
            char c = formula[i];
            if (c == '(') {
                stack_.push_back({});
                i++;
            } else if (c == ')') {
                i++;
                long long mult = readNum(i);
                auto top = stack_.back();
                stack_.pop_back();
                for (auto& [name, cnt] : top) stack_.back()[name] += cnt * mult;
            } else {
                int j = i + 1;
                while (j < n && islower(formula[j])) j++;
                string name = formula.substr(i, j - i);
                i = j;
                long long cnt = readNum(i);
                stack_.back()[name] += cnt;
            }
        }

        string res;
        for (auto& [name, cnt] : stack_.back()) {
            res += name;
            if (cnt > 1) res += to_string(cnt);
        }
        return res;
    }
};
