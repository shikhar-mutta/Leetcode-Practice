// Link: https://leetcode.com/problems/describe-the-painting/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int, long long> delta;
        for (auto& s : segments) {
            delta[s[0]] += s[2];
            delta[s[1]] -= s[2];
        }

        vector<vector<long long>> res;
        long long cur = 0;
        int prevPos = -1;
        for (auto& [pos, d] : delta) {
            if (prevPos != -1 && cur > 0) {
                res.push_back({prevPos, pos, cur});
            }
            cur += d;
            prevPos = pos;
        }
        return res;
    }
};
