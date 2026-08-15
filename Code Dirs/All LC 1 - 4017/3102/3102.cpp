// Link: https://leetcode.com/problems/minimize-manhattan-distances/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        multiset<int> uSet, vSet;
        for (auto& p : points) {
            uSet.insert(p[0] + p[1]);
            vSet.insert(p[0] - p[1]);
        }
        int best = INT_MAX;
        for (auto& p : points) {
            int u = p[0] + p[1], v = p[0] - p[1];
            uSet.erase(uSet.find(u));
            vSet.erase(vSet.find(v));
            int du = *uSet.rbegin() - *uSet.begin();
            int dv = *vSet.rbegin() - *vSet.begin();
            best = min(best, max(du, dv));
            uSet.insert(u);
            vSet.insert(v);
        }
        return best;
    }
};
