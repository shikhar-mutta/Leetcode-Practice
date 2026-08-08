// Link: https://leetcode.com/problems/camelcase-matching/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (auto& q : queries) res.push_back(matches(q, pattern));
        return res;
    }

private:
    bool matches(const string& q, const string& p) {
        int j = 0;
        for (char c : q) {
            if (j < (int)p.size() && p[j] == c) { j++; continue; }
            if (isupper(c)) return false;
        }
        return j == (int)p.size();
    }
};
