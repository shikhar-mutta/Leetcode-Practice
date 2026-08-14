// Link: https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAll(const string& s, const string& p) {
        vector<int> res;
        size_t pos = s.find(p, 0);
        while (pos != string::npos) {
            res.push_back(pos);
            pos = s.find(p, pos + 1);
        }
        return res;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> occA = findAll(s, a);
        vector<int> occB = findAll(s, b);
        vector<int> res;
        for (int i : occA) {
            for (int j : occB) {
                if (abs(i - j) <= k) { res.push_back(i); break; }
            }
        }
        return res;
    }
};
