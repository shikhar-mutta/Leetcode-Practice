// Link: https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kmpFindAll(const string& s, const string& p) {
        vector<int> res;
        int m = p.size();
        if (m == 0) return res;
        vector<int> fail(m, 0);
        for (int i = 1; i < m; i++) {
            int j = fail[i-1];
            while (j > 0 && p[i] != p[j]) j = fail[j-1];
            if (p[i] == p[j]) j++;
            fail[i] = j;
        }
        int j = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            while (j > 0 && s[i] != p[j]) j = fail[j-1];
            if (s[i] == p[j]) j++;
            if (j == m) { res.push_back(i - m + 1); j = fail[j-1]; }
        }
        return res;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> occA = kmpFindAll(s, a);
        vector<int> occB = kmpFindAll(s, b);
        vector<int> res;
        for (int i : occA) {
            auto it = lower_bound(occB.begin(), occB.end(), i - k);
            if (it != occB.end() && *it <= i + k) res.push_back(i);
        }
        return res;
    }
};
