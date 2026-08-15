// Link: https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;
    int pos;

    pair<int,int> combineAnd(pair<int,int> L, pair<int,int> R) {
        int andCost1 = L.second + R.second;
        int andCost0 = min({L.first+R.first, L.first+R.second, L.second+R.first});
        int orCost1 = min({L.second+R.first, L.first+R.second, L.second+R.second});
        int orCost0 = L.first + R.first;
        return {min(andCost0, 1+orCost0), min(andCost1, 1+orCost1)};
    }

    pair<int,int> combineOr(pair<int,int> L, pair<int,int> R) {
        int orCost1 = min({L.second+R.first, L.first+R.second, L.second+R.second});
        int orCost0 = L.first + R.first;
        int andCost1 = L.second + R.second;
        int andCost0 = min({L.first+R.first, L.first+R.second, L.second+R.first});
        return {min(orCost0, 1+andCost0), min(orCost1, 1+andCost1)};
    }

    pair<int,int> parsePrimary() {
        if (s[pos] == '(') {
            pos++;
            auto r = parseOr();
            pos++; // skip ')'
            return r;
        } else {
            char c = s[pos]; pos++;
            if (c == '0') return {0, 1};
            else return {1, 0};
        }
    }

    pair<int,int> parseAnd() {
        auto left = parsePrimary();
        while (pos < (int)s.size() && s[pos] == '&') {
            pos++;
            auto right = parsePrimary();
            left = combineAnd(left, right);
        }
        return left;
    }

    pair<int,int> parseOr() {
        auto left = parseAnd();
        while (pos < (int)s.size() && s[pos] == '|') {
            pos++;
            auto right = parseAnd();
            left = combineOr(left, right);
        }
        return left;
    }

    int minOperationsToFlip(string expression) {
        s = expression;
        pos = 0;
        auto root = parseOr();
        return root.first == 0 ? root.second : root.first;
    }
};
