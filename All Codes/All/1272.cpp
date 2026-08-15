// Link: https://leetcode.com/problems/remove-interval/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int rl = toBeRemoved[0], rr = toBeRemoved[1];
        vector<vector<int>> res;
        for (auto& iv : intervals) {
            int l = iv[0], r = iv[1];
            if (r <= rl || l >= rr) {
                res.push_back({l, r});
            } else {
                if (l < rl) res.push_back({l, rl});
                if (r > rr) res.push_back({rr, r});
            }
        }
        return res;
    }
};
