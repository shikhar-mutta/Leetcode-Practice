// Link: https://leetcode.com/problems/find-and-replace-pattern/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (auto& w : words) if (matches(w, pattern)) res.push_back(w);
        return res;
    }

private:
    bool matches(const string& w, const string& p) {
        unordered_map<char,char> m1, m2;
        for (int i = 0; i < (int)w.size(); i++) {
            char a = w[i], b = p[i];
            if (m1.count(a) && m1[a] != b) return false;
            if (m2.count(b) && m2[b] != a) return false;
            m1[a] = b;
            m2[b] = a;
        }
        return true;
    }
};
