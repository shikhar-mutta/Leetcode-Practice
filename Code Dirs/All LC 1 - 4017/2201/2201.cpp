// Link: https://leetcode.com/problems/count-artifacts-that-can-be-extracted/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        set<pair<int,int>> dug;
        for (auto& d : dig) dug.insert({d[0], d[1]});
        int count = 0;
        for (auto& a : artifacts) {
            bool all = true;
            for (int r = a[0]; r <= a[2] && all; r++) {
                for (int c = a[1]; c <= a[3] && all; c++) {
                    if (!dug.count({r, c})) all = false;
                }
            }
            if (all) count++;
        }
        return count;
    }
};
