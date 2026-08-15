// Link: https://leetcode.com/problems/di-string-match/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int lo = 0, hi = s.size();
        vector<int> res;
        for (char c : s) {
            if (c == 'I') res.push_back(lo++);
            else res.push_back(hi--);
        }
        res.push_back(lo);
        return res;
    }
};
